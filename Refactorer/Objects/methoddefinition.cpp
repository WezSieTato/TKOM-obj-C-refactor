#include "methoddefinition.h"

using namespace objc;

MethodDefinition::MethodDefinition()
{
}

std::string MethodDefinition::body() const
{
    return _body;
}

void MethodDefinition::setBody(const std::string &body)
{
    _body = body;
}
