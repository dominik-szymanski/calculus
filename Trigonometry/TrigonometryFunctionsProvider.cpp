//
// Created by dominik on 07.10.2021.
//

#include "TrigonometryFunctionsProvider.hpp"
#include "TrigonometryFunctions.hpp"

TrigonometryFunctionsProvider provider;

std::map<std::string, std::function<std::unique_ptr<Function>()>> TrigonometryFunctionsProvider::_functionCreator =
  {{"sin", [](){return std::make_unique<FunctionSinus>();}},
   {"cos", [](){return std::make_unique<FunctionCosinus>();}},
   {"tan", [](){return std::make_unique<FunctionTangens>();}},
   {"ctg", [](){return std::make_unique<FunctionCotangens>();}},
   {"sum", [](){return std::make_unique<Sum>();}},
   {"rect_area", [](){return std::make_unique<RectangleArea>();}},};

std::unique_ptr<Function>
TrigonometryFunctionsProvider::createFunction(const std::string &inName) const
{
  if (isExist(inName))
  {
    return _functionCreator[inName]();
  }
  else
  {
    return nullptr;
  }
}

bool
TrigonometryFunctionsProvider::isExist(const std::string &inName) const
{
  return _functionCreator.find(inName) != _functionCreator.end();
}