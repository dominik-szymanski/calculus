//
// Created by dominik on 06.10.2021.
//

#include "BasicFunctionProvider.hpp"
#include "BasicFunctions.hpp"

std::map<std::string, std::function<std::unique_ptr<Function>()>> BasicFunctionProvider::_functionCreator =
  {{"log", [](){return std::make_unique<FunctionLogarithm>();}}};

std::unique_ptr<Function>
BasicFunctionProvider::createFunction(const std::string &inName) const
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
BasicFunctionProvider::isExist(const std::string &inName) const
{
  return _functionCreator.find(inName) != _functionCreator.end();
}
