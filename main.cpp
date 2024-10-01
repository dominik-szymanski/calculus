#include <iostream>
#include <dlfcn.h>

#include "Operator.hpp"
#include "Operand.hpp"
#include "BasicOperators/BasicOperatorProvider.hpp"
#include "ONPParser/ONPParser.hpp"
#include "Solver/Solver.hpp"
#include "BasicFunctions/BasicFunctionProvider.hpp"
#include "Calculator/Calculator.hpp"

extern "C"

void*
loadProvider(const std::string& libName)
{
  /* load shared lib */
  void* handle = dlopen(libName.c_str(), RTLD_LAZY);
  void* object = nullptr;

  if (!handle)
  {
//    std::cerr << dlerror() << std::endl;
  }
  else
  {
    /* load object from lib */
    object = dlsym(handle, "provider");
  }
  return object;
}

int main()
{
  auto basic_provider = std::make_shared<BasicOperatorProvider>();
  auto basic_function_provider = std::make_shared<BasicFunctionProvider>();

  std::vector<std::shared_ptr<FunctionProvider>> function_providers = {basic_function_provider};

  /* load plugin */
  void* object =
    loadProvider("/home/dominik/Documents/calculus/cmake-build-debug/plugins/libtrigonometry_functions.so");

  if(object)
  {
    FunctionProvider* provider = static_cast<FunctionProvider*>(object);
    if (provider)
    {
      function_providers.push_back(std::shared_ptr<FunctionProvider>(provider));
    }
  }
  /* --- */
  ONPParser parser({basic_provider}, function_providers);

  Calculator calc1(parser);
  calc1.start(std::cout);

  return 0;
}
