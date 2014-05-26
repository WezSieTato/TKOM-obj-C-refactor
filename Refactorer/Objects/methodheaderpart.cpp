#include "methodheaderpart.h"

using namespace objc;

MethodHeaderPart::MethodHeaderPart() :
    _isParameter(false)
{
}

string MethodHeaderPart::name() const
{
    return _methodName;
}

void MethodHeaderPart::setName(const string &methodName)
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
    _isParameter = true;
}


bool MethodHeaderPart::isParameter() const
{
    return _isParameter;
}

bool MethodHeaderPart::operator ==(const MethodHeaderPart &other) const
{
    return (_methodName == other._methodName && _variable == other.variable());
}




