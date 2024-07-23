//
// Created by dominik on 06.10.2021.
//

#ifndef BASICOPERATORPROVIDER_HPP
#define BASICOPERATORPROVIDER_HPP

#include <map>
#include <functional>

#include "../OperatorProvider.hpp"

class BasicOperatorProvider : public OperatorProvider
{
public:
  std::unique_ptr<Operator> createOperator(const std::string& inName) const override;
  bool isExist(const std::string& inName) const override;

private:
  static std::map<std::string, std::function<std::unique_ptr<Operator>()>> _operatorCreator;
};


#endif //BASICOPERATORPROVIDER_HPP
