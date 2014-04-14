#include "propertydeclaration.h"

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

VariableDeclaration PropertyDeclaration::variableDec() const
{
    return _variableDec;
}

void PropertyDeclaration::setVariableDec(const VariableDeclaration &variableDec)
{
    _variableDec = variableDec;
}
