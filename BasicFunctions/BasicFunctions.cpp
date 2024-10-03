//
// Created by dominik on 06.10.2021.
//

#include <cmath>
#include <stdexcept>
#include "BasicFunctions.hpp"

unsigned int FunctionLogarithm::getParametersNo() const
{
  return PARAMS_NO;
}

Operand FunctionLogarithm::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  return Operand(std::log(parameters[0].getDouble()) / std::log(parameters[1].getDouble()));
}

std::string FunctionLogarithm::getName() const
{
  return "log";
}

//---//

unsigned int FunctionCsvLoader::getParametersNo() const
{
  return PARAMS_NO;
}

Operand FunctionCsvLoader::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  std::string str = "load "+parameters[0].getString();
  return Operand(str);
}

std::string FunctionCsvLoader::getName() const
{
  return "load_csv";
}