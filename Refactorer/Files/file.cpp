#include "file.h"

using namespace objc;

File::File()
{
}
ClassImplementationList File::classImplementations() const
{
    return _classImplementations;
}

void File::setClassImplementations(const ClassImplementationList &classImplementations)
{
    _classImplementations = classImplementations;
}
ClassImplementationList File::classInterfaces() const
{
    return _classInterfaces;
}

void File::setClassInterfaces(const ClassImplementationList &classInterfaces)
{
    _classInterfaces = classInterfaces;
}


