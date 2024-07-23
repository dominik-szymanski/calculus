//
// Created by dominik on 07.10.2021.
//

#ifndef TYPES_HPP
#define TYPES_HPP

#include "Operator.hpp"
#include "Function.hpp"
#include "Operand.hpp"

typedef std::variant<std::shared_ptr<Operator>, std::shared_ptr<Function>, Operand> MathItem;
typedef std::vector<MathItem> MathExpression;

#endif //TYPES_HPP
