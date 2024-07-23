//
// Created by dominik on 06.10.2021.
//

#include <algorithm>
#include <map>

#include "BasicOperatorProvider.hpp"
#include "AdditionOperator.hpp"
#include "MultiplicationOperator.hpp"
#include "SubtractionOperator.hpp"
#include "DivisionOperator.hpp"
#include "PowOperator.hpp"

std::map<std::string, std::function<std::unique_ptr<Operator>()>> BasicOperatorProvider::_operatorCreator =
  {{"+", [](){return std::make_unique<AdditionOperator>();}},
   {"*", [](){return std::make_unique<MultiplicationOperator>();}},
   {"-", [](){return std::make_unique<SubtractionOperator>();}},
   {"/", [](){return std::make_unique<DivisionOperator>();}},
   {"^", [](){return std::make_unique<PowOperator>();}}};

std::unique_ptr<Operator>
BasicOperatorProvider::createOperator(const std::string& inName) const
{
  if (isExist(inName))
  {
    return _operatorCreator[inName]();
  }
  else
  {
    return nullptr;
  }
}

bool
BasicOperatorProvider::isExist(const std::string& inName) const
{
  return _operatorCreator.find(inName) != _operatorCreator.end();
}