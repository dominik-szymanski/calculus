//
// Created by dominik on 06.10.2021.
//

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include <variant>
#include <vector>

class Operand
  {
  public:
    explicit Operand(double inValue)
    : _value(inValue),
      _type("double")
    {
    }

    explicit Operand(std::vector<Operand> inValue)
    : _value(inValue),
      _type("double")
    {
    }

    double getDouble() const
    {
      return *std::get_if<double>(&_value);
    }

    std::vector<Operand> getList() const
    {
      return *std::get_if<std::vector<Operand>>(&_value);
    }

    std::string getType() const
    {
      return _type;
    }

  private:
    std::string _type;
    std::variant<double, std::vector<Operand>> _value;
  };


#endif //OPERAND_HPP
