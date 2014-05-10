#include "variabledeclaration.h"

using namespace objc;

VariableDeclaration::VariableDeclaration()
{
}
//string VariableDeclaration::typeName() const
//{
//    return _typeName;
//}

//void VariableDeclaration::setTypeName(const string &typeName)
//{
//    _typeName = typeName;
//}
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



