#include "synthetizedvariable.h"

using namespace objc;

SynthetizedVariable::SynthetizedVariable()
{
}
std::string SynthetizedVariable::propertyName() const
{
    return _propertyName;
}

void SynthetizedVariable::setPropertyName(const std::string &propertyName)
{
    _propertyName = propertyName;
}
std::string SynthetizedVariable::variableName() const
{
    return _variableName;
}

void SynthetizedVariable::setVariableName(const std::string &variableName)
{
    _variableName = variableName;
}


