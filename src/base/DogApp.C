#include "DogApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<DogApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

DogApp::DogApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DogApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DogApp::associateSyntax(_syntax, _action_factory);
}

DogApp::~DogApp()
{
}

// External entry point for dynamic application loading
extern "C" void DogApp__registerApps() { DogApp::registerApps(); }
void
DogApp::registerApps()
{
  registerApp(DogApp);
}

// External entry point for dynamic object registration
extern "C" void DogApp__registerObjects(Factory & factory) { DogApp::registerObjects(factory); }
void
DogApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void DogApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { DogApp::associateSyntax(syntax, action_factory); }
void
DogApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
