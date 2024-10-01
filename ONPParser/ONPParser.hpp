//
// Created by dominik on 06.10.2021.
//

#ifndef ONPPARSER_HPP
#define ONPPARSER_HPP

#include <memory>
#include <vector>
#include <variant>

#include "../Operator.hpp"
#include "../Operand.hpp"
#include "../Function.hpp"
#include "../OperatorProvider.hpp"
#include "../FunctionProvider.hpp"
#include "../types.hpp"

class MakeList : public Function
{
public:
  explicit MakeList(int params_no);
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~MakeList() override = default;

private:
  int _params_no;
};

class ONPParser
{
public:
  ONPParser(const std::vector<std::shared_ptr<OperatorProvider>>& inOperatorProviders,
            const std::vector<std::shared_ptr<FunctionProvider>>& inFunctionProviders);

  MathExpression parse(const std::string &inExpression) const;

private:
  std::vector<std::string> splitExpression(const std::string &inExpression) const;
  std::vector<std::variant<std::shared_ptr<Operator>, Operand>> translateFromStringVec(const std::vector<std::string> &words) const;
  std::vector<std::variant<std::shared_ptr<Operator>, Operand>> onp() const;

  bool isNumber(const std::string &expression) const;
  bool isOperator(const std::string &expression) const;
  bool isDash(const std::string &expression) const;
  bool isLeftBracket(const std::string &expression) const;
  bool isRightBracket(const std::string &expression) const;
  bool isFunction(const std::string &expression) const;

  std::unique_ptr<Operator> createOperatorIfExist(const std::string &inName) const;
  std::unique_ptr<Function> createFunctionIfExist(const std::string &inName) const;

  void handleOperator(const std::unique_ptr<Operator> &inOperator, MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const;
  void handleDash(MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const;
  void rightBracketHandle(MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const;
  void addNextWord(const std::string &inWord, MathExpression &inoutQueue, std::vector<std::string> &inoutStack) const;

  std::vector<std::shared_ptr<OperatorProvider>> _operatorProviders;
  std::vector<std::shared_ptr<FunctionProvider>> _functionProviders;
};


#endif //ONPPARSER_HPP
