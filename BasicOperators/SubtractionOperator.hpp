//
// Created by dominik on 06.10.2021.
//

#ifndef SUBTRACTIONOPERATOR_HPP
#define SUBTRACTIONOPERATOR_HPP

#include "../Operator.hpp"

class SubtractionOperator : public Operator
{
public:
  int getPrecedence() const override;
  bool isLeftCumulative() const override;
  bool isRightCumulative() const override;
  std::string getName() const override;
  Operand operator()(const Operand &inFirst, const Operand &inSecond) const override;
};


#endif //SUBTRACTIONOPERATOR_HPP
