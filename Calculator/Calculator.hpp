//
// Created by dominik on 07.10.2021.
//

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>
#include "../Solver/Solver.hpp"
#include "../ONPParser/ONPParser.hpp"

class Calculator
{
public:
  explicit Calculator(const ONPParser &inParser);
  int start(std::ostream& outStream);

private:
  ONPParser _parser;
  Solver _solver;
};


#endif //CALCULATOR_HPP
