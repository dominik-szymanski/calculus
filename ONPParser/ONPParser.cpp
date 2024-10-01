//
// Created by dominik on 06.10.2021.
//

#include "boost/algorithm/string.hpp"

#include "ONPParser.hpp"

MakeList::MakeList(int params_no)
        : _params_no(params_no)
{}

unsigned int MakeList::getParametersNo() const
{
  return _params_no;
}

Operand MakeList::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != _params_no)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  return Operand(parameters);
}

std::string MakeList::getName() const
{
  return "make_list";
}

ONPParser::ONPParser(const std::vector<std::shared_ptr<OperatorProvider>>& inOperatorProviders,
                     const std::vector<std::shared_ptr<FunctionProvider>>& inFunctionProviders)
: _operatorProviders(inOperatorProviders),
  _functionProviders(inFunctionProviders)
{}

bool
ONPParser::isNumber(const std::string &expression) const
{
  try
  {
    auto value = std::stod(expression);
    return true;
  }
  catch (...)
  {
    return false;
  }
}

bool
ONPParser::isOperator(const std::string &expression) const
{
  return expression == "+" || expression == "-" || expression == "*" || expression == "/" || expression == "^";
}

bool
ONPParser::isDash(const std::string &expression) const
{
  return expression == ",";
}

bool
ONPParser::isLeftBracket(const std::string &expression) const
{
  return expression == "(";
}

bool
ONPParser::isRightBracket(const std::string &expression) const
{
  return expression == ")";
}

bool
ONPParser::isFunction(const std::string &expression) const
{
  return !isNumber(expression) && !isOperator(expression) && !isDash(expression) && !isLeftBracket(expression) &&
  !isRightBracket(expression);
}

std::string preprocessExpression(const std::string &inExpression)
{
  std::string preprocessed{};

  for (unsigned int i = 0; i < inExpression.size(); ++i)
  {
    if(inExpression[i] != '[' && inExpression[i] != ']')
    {
      preprocessed += inExpression[i];
      continue;
    }
    if (inExpression[i] == ']')
    {
      preprocessed += ")";
      continue;
    }

    int counter = 1;
    int depth = 0;
    for (unsigned int j = i + 1; j < inExpression.size(); ++j)
    {
      if (inExpression[j] == '(' || inExpression[j] == '[')
      {
        depth++;
      }
      else if(inExpression[j] == ']' && depth == 0)
      {
        break;
      }
      else if (inExpression[j] == ')' || inExpression[j] == ']')
      {
        depth--;
      }
      else if (inExpression[j] == ',' && depth == 0)
      {
        counter++;
      }
    }
    preprocessed += "make_list_"+std::to_string(counter)+"(";
  }
  return preprocessed;
}

std::vector<std::string>
ONPParser::splitExpression(const std::string &inExpression) const
{
  auto expression = preprocessExpression(inExpression);
  std::vector<std::string> split_expression;
  std::string sub_exp = {expression[0]};

  for (int i = 1; i < expression.size(); ++i)
  {
    if(sub_exp == " ")
    {
      continue;
    }
    if (isNumber(sub_exp))
    {
      std::string new_sub_exp = sub_exp + expression[i];
      std::string str {expression[i]};
      if (!isNumber(str))
      {
        split_expression.push_back(sub_exp);
        sub_exp = expression[i];
        continue;
      }
      else
      {
        sub_exp = new_sub_exp;
        continue;
      }
    }
    if (isLeftBracket(sub_exp))
    {
      split_expression.push_back(sub_exp);
      sub_exp = expression[i];
      continue;
    }
    if (isRightBracket(sub_exp))
    {
      split_expression.push_back(sub_exp);
      sub_exp = expression[i];
      continue;
    }
    if (isOperator(sub_exp))
    {
      split_expression.push_back(sub_exp);
      sub_exp = expression[i];
      continue;
    }
    if (isFunction(sub_exp))
    {
      std::string new_sub_exp = sub_exp + expression[i];
      std::string str {expression[i]};
      if (isOperator(str) || isDash(str) || isLeftBracket(str) || isRightBracket(str))
      {
        split_expression.push_back(sub_exp);
        sub_exp = expression[i];
        continue;
      }
      else
      {
        sub_exp = new_sub_exp;
        continue;
      }
    }
    if (isDash(sub_exp))
    {
      split_expression.push_back(sub_exp);
      sub_exp = expression[i];
      continue;
    }
    sub_exp += expression[i];
  }
  if (!sub_exp.empty())
  {
    split_expression.push_back(sub_exp);
  }
  return split_expression;
}

std::unique_ptr<Operator>
ONPParser::createOperatorIfExist(const std::string &inName) const
{
  for (auto provider: _operatorProviders)
  {
    if (provider->isExist(inName))
    {
      return provider->createOperator(inName);
    }
  }
  throw std::runtime_error("not found operator " + inName);
}

std::unique_ptr<Function>
ONPParser::createFunctionIfExist(const std::string &inName) const
{
  if(inName.starts_with("make_list_"))
  {
    std::string size_str(inName.begin()+10, inName.end());
    int size = std::stoi(size_str);
    return std::make_unique<MakeList>(size);
  }
  for (auto provider: _functionProviders)
  {
    if (provider->isExist(inName))
    {
      return provider->createFunction(inName);
    }
  }
  throw std::runtime_error("not found function " + inName);
}

void
ONPParser::handleOperator(const std::unique_ptr<Operator> &inOperator, MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const
{
  if (inOperator->isLeftCumulative())
  {
    while (!inoutStack.empty() && isOperator(inoutStack.back()))
    {
      auto op = createOperatorIfExist(inoutStack.back());
      if (!op)
      {
        throw std::runtime_error("Unknown operator");
      }
      if (inOperator->getPrecedence() <= op->getPrecedence())
      {
        inoutQueue.insert(inoutQueue.begin(), std::move(op));
        inoutStack.pop_back();
      }
      else
      {
        break;
      }
    }
  }
  if (inOperator->isRightCumulative())
  {
    while (!inoutStack.empty() && isOperator(inoutStack.back()))
    {
      auto op = createOperatorIfExist(inoutStack.back());
      if (!op)
      {
        throw std::runtime_error("Unknown operator");
      }
      if (inOperator->getPrecedence() < op->getPrecedence())
      {
        inoutQueue.insert(inoutQueue.begin(), std::move(op));
        inoutStack.pop_back();
      }
      else
      {
        break;
      }
    }
  }
  inoutStack.push_back(inOperator->getName());
}

void
ONPParser::handleDash(MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const
{
  while (!inoutStack.empty() && !isLeftBracket(inoutStack.back()))
  {
    if(isFunction(inoutStack.back()))
    {
      auto func = createFunctionIfExist(inoutStack.back());
      if (!func)
      {
        throw std::runtime_error("Unknown function '" + inoutStack.back() + "'");
      }
      inoutQueue.insert(inoutQueue.begin(), std::move(func));
    }
    else if(isOperator(inoutStack.back()))
    {
      auto op = createOperatorIfExist(inoutStack.back());
      if (!op)
      {
        throw std::runtime_error("Unknown operator '" + inoutStack.back() + "'");
      }
      inoutQueue.insert(inoutQueue.begin(), std::move(op));
    }
    else if (isNumber(inoutStack.back()))
    {
      inoutQueue.insert(inoutQueue.begin(), Operand(std::stod(inoutStack.back())));
    }
    inoutStack.pop_back();
  }
}

void
ONPParser::rightBracketHandle(MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const
{
  while(!isLeftBracket(inoutStack.back()))
  {
    inoutQueue.insert(inoutQueue.begin(), createOperatorIfExist(inoutStack.back()));
    inoutStack.pop_back();
  }
  inoutStack.pop_back();
  if (!inoutStack.empty() && isFunction(inoutStack.back()))
  {
    inoutQueue.insert(inoutQueue.begin(), createFunctionIfExist(inoutStack.back()));
    inoutStack.pop_back();
  }
}

void
ONPParser::addNextWord(const std::string &inWord, MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const
{
  if (isNumber(inWord))
  {
    inoutQueue.insert(inoutQueue.begin(), Operand(std::stod(inWord)));
  }
  else if (isFunction(inWord))
  {
    inoutStack.push_back(inWord);
  }
  else if (isDash(inWord))
  {
    handleDash(inoutQueue, inoutStack);
  }
  else if (isOperator(inWord))
  {
    auto new_operator = createOperatorIfExist(inWord);
    if (!new_operator)
    {
      throw std::runtime_error("Unknown operator '" + inWord + "'");
    }
    handleOperator(new_operator, inoutQueue, inoutStack);
  }
  else if (isLeftBracket(inWord))
  {
    inoutStack.push_back(inWord);
  }
  else if (isRightBracket(inWord))
  {
    rightBracketHandle(inoutQueue, inoutStack);
  }
}

MathExpression
ONPParser::parse(const std::string &inExpression) const
{
  std::vector<std::variant<std::shared_ptr<Operator>, std::shared_ptr<Function>, Operand>> out_queue;
  std::vector<std::string> stack;
  auto splitted_expression = splitExpression(inExpression);
  for (auto & word : splitted_expression)
  {
    addNextWord(word, out_queue, stack);
  }

  for (auto iter = stack.rbegin(); iter != stack.rend(); ++iter)
  {
    out_queue.insert(out_queue.begin(), createOperatorIfExist(*iter));
  }

  return out_queue;
}