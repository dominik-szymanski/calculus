//
// Created by dominik on 14.10.2021.
//

#include <cmath>

#include "PowOperator.hpp"

int
PowOperator::getPrecedence() const
{
  return 1;
}

bool
PowOperator::isLeftCumulative() const
{
  return false;
}

bool
PowOperator::isRightCumulative() const
{
  return true;
}

std::string
PowOperator::getName() const
{
  return "^";
}

Operand
PowOperator::operator()(const Operand &inFirst, const Operand &inSecond) const
{
  return Operand(std::pow(inFirst.getDouble(), inSecond.getDouble()));
}