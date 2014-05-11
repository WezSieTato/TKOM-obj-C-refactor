#include "methoddeclaration.h"

using namespace objc;

MethodDeclaration::MethodDeclaration()
{
}

MethodHeader MethodDeclaration::header() const
{
    return _header;
}

void MethodDeclaration::setHeader(const MethodHeader &header)
{
    _header = header;
}
