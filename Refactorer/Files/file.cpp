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
ClassInterfaceList File::classInterfaces() const
{
    return _classInterfaces;
}

void File::setClassInterfaces(const ClassInterfaceList &classInterfaces)
{
    _classInterfaces = classInterfaces;
}

