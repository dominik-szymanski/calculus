//
// Created by dominik on 07.10.2021.
//

#ifndef TRIGONOMETRYFUNCTIONS_HPP
#define TRIGONOMETRYFUNCTIONS_HPP

#include <vector>
#include <string>
#include "../Function.hpp"
#include "../Operand.hpp"

class FunctionSinus : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~FunctionSinus() override = default;

private:
  static constexpr int PARAMS_NO = 1;
};

class FunctionCosinus : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~FunctionCosinus() override = default;

private:
  static constexpr int PARAMS_NO = 1;
};

class FunctionTangens : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~FunctionTangens() override = default;

private:
  static constexpr int PARAMS_NO = 1;
};

class FunctionCotangens : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~FunctionCotangens() override = default;

private:
  static constexpr int PARAMS_NO = 1;
};

class RectangleArea : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~RectangleArea() override = default;

private:
  static constexpr int PARAMS_NO = 2;
};

class Sum : public Function
{
public:
  unsigned int getParametersNo() const override;
  Operand operator()(const std::vector<Operand> &parameters) const override;
  std::string getName() const override;
  ~Sum() override = default;

private:
  static constexpr int PARAMS_NO = 1;
};

#endif //TRIGONOMETRYFUNCTIONS_HPP
