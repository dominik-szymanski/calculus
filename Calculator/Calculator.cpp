//
// Created by dominik on 07.10.2021.
//

#include "Calculator.hpp"

Calculator::Calculator(const ONPParser &inParser)
: _parser(inParser)
{
}

int
Calculator::start(std::ostream& outStream)
{
  outStream << "Calculator v.1.0" << std::endl;
  outStream << "> ";

  while (true)
  {
    std::string expression;
    std::getline(std::cin, expression);

    auto parsed_expression = _parser.parse(expression);
    auto result = _solver.solve(parsed_expression);
    outStream << "> result: " << result.getDouble() << std::endl;
    outStream << "> ";
  }

  return 0;
}
