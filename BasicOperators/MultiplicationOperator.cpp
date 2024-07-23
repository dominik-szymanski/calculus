//
// Created by dominik on 06.10.2021.
//

#include "MultiplicationOperator.hpp"

int
MultiplicationOperator::getPrecedence() const
{
  return 2;
}

bool
MultiplicationOperator::isLeftCumulative() const
{
  return true;
}

bool
MultiplicationOperator::isRightCumulative() const
{
  return true;
}

std::string
MultiplicationOperator::getName() const
{
  return "*";
}

Operand
MultiplicationOperator::operator()(const Operand &inFirst, const Operand &inSecond) const
{
  return Operand(inFirst.getDouble() * inSecond.getDouble());
}