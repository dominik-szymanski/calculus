//
// Created by dominik on 06.10.2021.
//

#ifndef BASICFUNCTIONS_HPP
#define BASICFUNCTIONS_HPP

#include <vector>
#include <string>
#include "../Function.hpp"
#include "../Operand.hpp"

class FunctionLogarithm : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~FunctionLogarithm() override = default;

private:
  static constexpr int PARAMS_NO = 2;
};

class FunctionCsvLoader : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~FunctionCsvLoader() override = default;

private:
  static constexpr int PARAMS_NO = 1;
};

#endif //BASICFUNCTIONS_HPP
