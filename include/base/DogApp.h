#ifndef DOGAPP_H
#define DOGAPP_H

#include "MooseApp.h"

class DogApp;

template<>
InputParameters validParams<DogApp>();

class DogApp : public MooseApp
{
public:
  DogApp(InputParameters parameters);
  virtual ~DogApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* DOGAPP_H */
