//
// Created by dominik on 05.10.2021.
//

#ifndef OPERATORPROVIDER_HPP
#define OPERATORPROVIDER_HPP

#include <memory>
#include "Operator.hpp"

class OperatorProvider
{
public:
  virtual std::unique_ptr<Operator> createOperator(const std::string& inName) const = 0;
  virtual bool isExist(const std::string& inName) const = 0;
};


#endif //OPERATORPROVIDER_HPP
