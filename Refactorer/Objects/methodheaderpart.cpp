#include "methodheaderpart.h"

using namespace objc;

MethodHeaderPart::MethodHeaderPart()
{
}
string MethodHeaderPart::methodName() const
{
    return _methodName;
}

void MethodHeaderPart::setMethodName(const string &methodName)
{
    _methodName = methodName;
}
VariableDeclaration MethodHeaderPart::variable() const
{
    return _variable;
}

void MethodHeaderPart::setVariable(const VariableDeclaration &variable)
{
    _variable = variable;
}
