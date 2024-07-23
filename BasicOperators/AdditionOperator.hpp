//
// Created by dominik on 06.10.2021.
//

#ifndef ADDITIONOPERATOR_HPP
#define ADDITIONOPERATOR_HPP

#include "../Operator.hpp"

class AdditionOperator : public Operator
{
  int getPrecedence() const override;
  bool isLeftCumulative() const override;
  bool isRightCumulative() const override;
  std::string getName() const override;
  Operand operator()(const Operand &inFirst, const Operand &inSecond) const override;
};


#endif //ADDITIONOPERATOR_HPP
