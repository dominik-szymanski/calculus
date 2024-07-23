//
// Created by dominik on 06.10.2021.
//

#ifndef FUNCTIONPROVIDER_HPP
#define FUNCTIONPROVIDER_HPP

class FunctionProvider
{
public:
  virtual std::unique_ptr<Function> createFunction(const std::string& inName) const = 0;
  virtual bool isExist(const std::string& inName) const = 0;

  virtual ~FunctionProvider() = default;
};

#endif //FUNCTIONPROVIDER_HPP
