#include "variabledeclaration.h"

using namespace objc;

VariableDeclaration::VariableDeclaration()
{
}

string VariableDeclaration::objectName() const
{
    return _objectName;
}

void VariableDeclaration::setObjectName(const string &objectName)
{
    _objectName = objectName;
}
VariableType VariableDeclaration::type() const
{
    return _type;
}

void VariableDeclaration::setType(const VariableType &type)
{
    _type = type;
}

bool VariableDeclaration::operator ==(const VariableDeclaration &other) const
{
    return (_objectName == other._objectName && _type == other.type());
}



