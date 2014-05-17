#include "classpart.h"

using namespace objc;

ClassPart::ClassPart()
{
}

std::string ClassPart::className() const
{
    return _className;
}

void ClassPart::setClassName(const std::string &className)
{
    _className = className;
}
