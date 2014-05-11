#include "variabletype.h"
#include <algorithm>

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
    return std::count(_type.begin(), _type.end(), '*');
}

bool objc::VariableType::isPointer() const
{
    return starNumber();
}
