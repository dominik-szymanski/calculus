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

  explicit Operand(std::string inValue)
  : _value(std::move(inValue)),
    _type("string")
  {
  }

    explicit Operand(const std::vector<Operand>& inValue)
    : _value(inValue),
      _type("list")
    {
    }

    double getDouble() const
    {
      return *std::get_if<double>(&_value);
    }

    std::string getString() const
    {
      return *std::get_if<std::string>(&_value);
    }

    std::vector<Operand> getList() const
    {
      return *std::get_if<std::vector<Operand>>(&_value);
    }

    std::string getType() const
    {
      return _type;
    }

    std::string print() const
    {
      if (_type == "double")
      {
        return std::to_string(*std::get_if<double>(&_value));
      }
      else if (_type == "string")
      {
        return *std::get_if<std::string>(&_value);
      }
      else if(_type == "list")
      {
        std::string str_value{'['};
        auto list = *std::get_if<std::vector<Operand>>(&_value);
        for(auto& op : list)
        {
          str_value += op.print() + ", ";
        }
        str_value += "]";
        return str_value;
      }
    }

  private:
    std::string _type;
    std::variant<double, std::vector<Operand>, std::string> _value;
  };


#endif //OPERAND_HPP
