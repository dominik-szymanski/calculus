//
// Created by dominik on 06.10.2021.
//

#ifndef MULTIPLICATIONOPERATOR_HPP
#define MULTIPLICATIONOPERATOR_HPP

#include <string>
#include "../Operator.hpp"

class MultiplicationOperator : public Operator
{
public:
  int getPrecedence() const override;
  bool isLeftCumulative() const override;
  bool isRightCumulative() const override;
  std::string getName() const override;
  Operand operator()(const Operand &inFirst, const Operand &inSecond) const override;
};


#endif //MULTIPLICATIONOPERATOR_HPP
