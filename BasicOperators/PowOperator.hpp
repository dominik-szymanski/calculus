//
// Created by dominik on 14.10.2021.
//

#ifndef POWOPERATOR_HPP
#define POWOPERATOR_HPP

#include <string>
#include "../Operator.hpp"

class PowOperator : public Operator
{
  int getPrecedence() const override;
  bool isLeftCumulative() const override;
  bool isRightCumulative() const override;
  std::string getName() const override;
  Operand operator()(const Operand &inFirst, const Operand &inSecond) const override;
};


#endif //POWOPERATOR_HPP
