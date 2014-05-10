#include "variabletype.h"

using namespace objc;

VariableType::VariableType()
{
}

string VariableType::type() const
{
    return _type;
}

void VariableType::setType(const string &type)
{
    _type = type;
}

unsigned VariableType::starNumber() const
{
    return _starNumber;
}

void VariableType::setStarNumber(const unsigned &starNumber)
{
    _starNumber = starNumber;
}


bool objc::VariableType::isPointer() const
{
    return _starNumber;
}
