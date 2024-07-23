//
// Created by dominik on 05.10.2021.
//

#ifndef OPERATOR_HPP
#define OPERATOR_HPP


#include "Operand.hpp"
class Operator
{
public:
  virtual int getPrecedence() const = 0;
  virtual bool isLeftCumulative() const = 0;
  virtual bool isRightCumulative() const = 0;
  virtual std::string getName() const = 0;

  virtual Operand operator()(const Operand &inFirst, const Operand &inSecond) const = 0;

  virtual ~Operator() = default;
};


#endif //OPERATOR_HPP
