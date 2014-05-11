#include "variabletype.h"
#include <algorithm>

using namespace objc;

VariableType::VariableType()
{
}

string VariableType::name() const
{
    return _name;
}

void VariableType::setName(const string &type)
{
    _name = type;
}

unsigned VariableType::starNumber() const
{
    return std::count(_name.begin(), _name.end(), '*');
}

bool objc::VariableType::isPointer() const
{
    return starNumber();
}
