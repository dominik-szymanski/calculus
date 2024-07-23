//
// Created by dominik on 06.10.2021.
//

#include "Solver.hpp"

void
Solver::addOperandToStack(const MathItem &inOperand, std::vector<Operand> &inoutStack) const
{
  auto operand = std::get_if<Operand>(&inOperand);
  if (operand)
  {
    inoutStack.push_back(*operand);
  }
}

void
Solver::executeOperatorOnStack(const MathItem &inOperator, std::vector<Operand> &inoutStack) const
{
  auto op = std::get_if<std::shared_ptr<Operator>>(&inOperator);
  if (op)
  {
    auto second_operand = inoutStack.back();
    inoutStack.pop_back();
    auto first_operand = inoutStack.back();
    inoutStack.pop_back();
    inoutStack.push_back((*(*op))(first_operand, second_operand));
  }
}

void
Solver::executeFunctionOnStack(const MathItem &inFunction, std::vector<Operand> &inoutStack) const
{
  auto function = std::get_if<std::shared_ptr<Function>>(&inFunction);
  if (function)
  {
    std::vector<Operand> parameters;
    for (unsigned int i = 0; i < (*function)->getParametersNo(); ++i)
    {
      parameters.push_back(inoutStack.back());
      inoutStack.pop_back();
    }
    inoutStack.push_back((*(*function))(parameters));
  }
}

Operand
Solver::solve(const MathExpression &inExpression) const
{
  std::vector<Operand> stack;

  for (auto iter = inExpression.rbegin(); iter != inExpression.rend(); ++iter)
  {
    if (iter->index() == 2)
    {
      addOperandToStack(*iter, stack);
    }
    else if (iter->index() == 0)
    {
      executeOperatorOnStack(*iter, stack);
    }
    else if (iter->index() == 1)
    {
      executeFunctionOnStack(*iter, stack);
    }
  }

  return stack.back();
}