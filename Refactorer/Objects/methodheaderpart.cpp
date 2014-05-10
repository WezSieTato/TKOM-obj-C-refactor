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
string MethodHeaderPart::methodType() const
{
    return _methodType;
}

void MethodHeaderPart::setMethodType(const string &methodType)
{
    _methodType = methodType;
}
string MethodHeaderPart::variableName() const
{
    return _variableName;
}

void MethodHeaderPart::setVariableName(const string &variableName)
{
    _variableName = variableName;
}



