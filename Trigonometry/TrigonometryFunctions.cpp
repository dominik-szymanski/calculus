//
// Created by dominik on 07.10.2021.
//

#include <cmath>
#include <stdexcept>

#include "TrigonometryFunctions.hpp"

unsigned int FunctionSinus::getParametersNo() const
{
  return 1;
}

Operand FunctionSinus::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  return Operand(std::sin(parameters[0].getDouble()));
}

std::string FunctionSinus::getName() const
{
  return "sin";
}

unsigned int FunctionCosinus::getParametersNo() const
{
  return 1;
}

Operand FunctionCosinus::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  return Operand(std::cos(parameters[0].getDouble()));
}

std::string FunctionCosinus::getName() const
{
  return "cos";
}

unsigned int FunctionTangens::getParametersNo() const
{
  return 1;
}

Operand FunctionTangens::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  return Operand(std::tan(parameters[0].getDouble()));
}

std::string FunctionTangens::getName() const
{
  return "tan";
}

unsigned int FunctionCotangens::getParametersNo() const
{
  return 1;
}

Operand FunctionCotangens::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  return Operand(std::cos(parameters[0].getDouble()) / std::sin(parameters[0].getDouble()));
}

std::string FunctionCotangens::getName() const
{
  return "ctg";
}

unsigned int RectangleArea::getParametersNo() const
{
  return 2;
}

Operand RectangleArea::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  return Operand(parameters[0].getDouble() * parameters[1].getDouble());
}

std::string RectangleArea::getName() const
{
  return "rect_area";
}