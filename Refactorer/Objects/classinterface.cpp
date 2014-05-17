#include "classinterface.h"

using namespace objc;

ClassInterface::ClassInterface()
{
}

std::string ClassInterface::baseClass() const
{
    return _baseClass;
}

void ClassInterface::setBaseClass(const std::string &baseClass)
{
    _baseClass = baseClass;
}

VariableDeclarationList ClassInterface::variableDeclarations() const
{
    return _variableDeclarations;
}

void ClassInterface::setVariableDeclarations(const VariableDeclarationList &variableDeclarations)
{
    _variableDeclarations = variableDeclarations;
}

PropertyDeclarationList ClassInterface::propertyDeclarations() const
{
    return _propertyDeclarations;
}

void ClassInterface::setPropertyDeclarations(const PropertyDeclarationList &propertyDeclarations)
{
    _propertyDeclarations = propertyDeclarations;
}

MethodDeclarationList ClassInterface::methodDeclarations() const
{
    return _methodDeclarations;
}

void ClassInterface::setMethodDeclarations(const MethodDeclarationList &methodDeclarations)
{
    _methodDeclarations = methodDeclarations;
}
