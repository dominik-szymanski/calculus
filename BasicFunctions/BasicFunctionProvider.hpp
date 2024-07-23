//
// Created by dominik on 06.10.2021.
//

#ifndef BASICFUNCTIONPROVIDER_HPP
#define BASICFUNCTIONPROVIDER_HPP

#include <functional>
#include <map>
#include <memory>

#include "../Function.hpp"
#include "../FunctionProvider.hpp"

class BasicFunctionProvider : public FunctionProvider
{
public:
  std::unique_ptr<Function> createFunction(const std::string &inName) const override;
  bool isExist(const std::string &inName) const override;
  ~BasicFunctionProvider() override = default;

private:
  static std::map<std::string, std::function<std::unique_ptr<Function>()>> _functionCreator;
};


#endif //BASICFUNCTIONPROVIDER_HPP
