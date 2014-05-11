#include "methodheaderdeclaration.h"

using namespace objc;

MethodHeaderDeclaration::MethodHeaderDeclaration()
{
}

MethodHeader MethodHeaderDeclaration::header() const
{
    return _header;
}

void MethodHeaderDeclaration::setHeader(const MethodHeader &header)
{
    _header = header;
}
