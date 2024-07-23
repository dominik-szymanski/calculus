//
// Created by dominik on 06.10.2021.
//

#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <memory>
#include <string>
#include <variant>
#include <vector>

#include "../types.hpp"
#include "../Operand.hpp"
#include "../Operator.hpp"
#include "../Function.hpp"


class Solver
{
public:
  Operand solve(const MathExpression &inExpression) const;

private:
  void addOperandToStack(const MathItem &inOperand, std::vector<Operand> &inoutStack) const;
  void executeOperatorOnStack(const MathItem &inOperator, std::vector<Operand> &inoutStack) const;
  void executeFunctionOnStack(const MathItem &inFunction, std::vector<Operand> &inoutStack) const;

};


#endif //SOLVER_HPP
