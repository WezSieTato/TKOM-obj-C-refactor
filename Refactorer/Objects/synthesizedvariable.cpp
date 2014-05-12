#include "synthesizedvariable.h"

using namespace objc;

SynthesizedVariable::SynthesizedVariable()
{
}
std::string SynthesizedVariable::propertyName() const
{
    return _propertyName;
}

void SynthesizedVariable::setPropertyName(const std::string &propertyName)
{
    _propertyName = propertyName;
}
std::string SynthesizedVariable::variableName() const
{
    return _variableName;
}

void SynthesizedVariable::setVariableName(const std::string &variableName)
{
    _variableName = variableName;
}


