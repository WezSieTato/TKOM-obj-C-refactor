#include "propertydeclaration.h"

using namespace objc;

PropertyDeclaration::PropertyDeclaration()
{
}

stringList PropertyDeclaration::attributes() const
{
    return _attributes;
}

void PropertyDeclaration::setAttributes(const stringList &attributes)
{
    _attributes = attributes;
}

VariableDeclaration PropertyDeclaration::variableDeclaration() const
{
    return _variableDec;
}

void PropertyDeclaration::setVariableDeclaration(const VariableDeclaration &variableDec)
{
    _variableDec = variableDec;
}
