//
// Created by dominik on 06.10.2021.
//
#include <string>

#include "SubtractionOperator.hpp"

int
SubtractionOperator::getPrecedence() const
{
  return 1;
}

bool
SubtractionOperator::isLeftCumulative() const
{
  return true;
}

bool
SubtractionOperator::isRightCumulative() const
{
  return false;
}

std::string
SubtractionOperator::getName() const
{
  return "-";
}

Operand
SubtractionOperator::operator()(const Operand &inFirst, const Operand &inSecond) const
{
  return Operand(inFirst.getDouble() - inSecond.getDouble());
}