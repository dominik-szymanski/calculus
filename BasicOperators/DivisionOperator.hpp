//
// Created by dominik on 06.10.2021.
//

#ifndef DIVISIONOPERATOR_HPP
#define DIVISIONOPERATOR_HPP

#include "../Operator.hpp"

class DivisionOperator : public Operator
{
  int getPrecedence() const override;
  bool isLeftCumulative() const override;
  bool isRightCumulative() const override;
  std::string getName() const override;
  Operand operator()(const Operand &inFirst, const Operand &inSecond) const override;
};


#endif //DIVISIONOPERATOR_HPP
