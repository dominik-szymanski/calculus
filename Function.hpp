//
// Created by dominik on 06.10.2021.
//

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "Operand.hpp"

class Function
{
public:
  virtual unsigned int getParametersNo() const = 0;
  virtual Operand operator()(const std::vector<Operand> &parameters) const = 0;
  virtual std::string getName() const = 0;

  virtual ~Function() = default;
};

#endif //FUNCTION_HPP
