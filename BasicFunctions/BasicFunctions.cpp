//
// Created by dominik on 06.10.2021.
//

#include <fstream>
#include <iostream>
#include <sstream>
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

std::vector<std::vector<std::string>> getNextLineAndSplitIntoTokens(std::istream& str)
{
  std::string line;
  std::vector<std::vector<std::string>> result;
  while(std::getline(str,line)) {
    std::vector<std::string> row;

    std::stringstream lineStream(line);
    std::string cell;

    while (std::getline(lineStream, cell, ',')) {
      row.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty()) {
      // If there was a trailing comma then add an empty element.
      row.push_back("");
    }
    result.push_back(row);
  }
  return result;
}


unsigned int FunctionCsvLoader::getParametersNo() const
{
  return PARAMS_NO;
}

bool
isNumber(const std::string &expression)
{
  try
  {
    auto value = std::stod(expression);
    return true;
  }
  catch (...)
  {
    return false;
  }
}

Operand FunctionCsvLoader::operator()(const std::vector<Operand> &parameters) const
{
  if (parameters.size() != PARAMS_NO)
  {
    throw std::runtime_error("incorrect parameters number");
  }
  std::ifstream file(parameters[0].getString());
  std::string str = "load "+parameters[0].getString();
  auto result = getNextLineAndSplitIntoTokens(file);

  std::vector<Operand> array_operand;
  for (auto row : result){
    std::vector<Operand> row_operand;
    for (auto cell : row){
      if (isNumber(cell)){
        row_operand.push_back(Operand(std::stod(cell)));
      }
      else{
        row_operand.push_back(Operand(cell));
      }
    }
    array_operand.push_back(Operand(row_operand));
  }

  return Operand(array_operand);
}

std::string FunctionCsvLoader::getName() const
{
  return "load_csv";
}