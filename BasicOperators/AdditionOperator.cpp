//
// Created by dominik on 06.10.2021.
//
#include <string>

#include "AdditionOperator.hpp"

int
AdditionOperator::getPrecedence() const
{
  return 1;
}

bool
AdditionOperator::isLeftCumulative() const
{
  return true;
}

bool
AdditionOperator::isRightCumulative() const
{
  return true;
}

std::string
AdditionOperator::getName() const
{
  return "+";
}

Operand
AdditionOperator::operator()(const Operand &inFirst, const Operand &inSecond) const
{
  return Operand(inFirst.getDouble() + inSecond.getDouble());
}