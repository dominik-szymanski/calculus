//
// Created by dominik on 06.10.2021.
//
#include <string>

#include "DivisionOperator.hpp"

int
DivisionOperator::getPrecedence() const
{
  return 2;
}

bool
DivisionOperator::isLeftCumulative() const
{
  return true;
}

bool
DivisionOperator::isRightCumulative() const
{
  return false;
}

std::string
DivisionOperator::getName() const
{
  return "/";
}

Operand
DivisionOperator::operator()(const Operand &inFirst, const Operand &inSecond) const
{
  return Operand(inFirst.getDouble() / inSecond.getDouble());
}