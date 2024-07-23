//
// Created by dominik on 07.10.2021.
//

#ifndef TRIGONOMETRYFUNCTIONSPROVIDER_HPP
#define TRIGONOMETRYFUNCTIONSPROVIDER_HPP

#include <functional>
#include <map>
#include <memory>

#include "../Function.hpp"
#include "../FunctionProvider.hpp"

class TrigonometryFunctionsProvider : public FunctionProvider
{
public:
  std::unique_ptr<Function> createFunction(const std::string &inName) const override;
  bool isExist(const std::string &inName) const override;
  ~TrigonometryFunctionsProvider() override = default;

private:
  static std::map<std::string, std::function<std::unique_ptr<Function>()>> _functionCreator;
};


#endif //TRIGONOMETRYFUNCTIONSPROVIDER_HPP
