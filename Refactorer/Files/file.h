#ifndef FILE_H
#define FILE_H

#include "../Objects/codeobjects.h"

namespace objc {

typedef std::list < ClassImplementation > ClassImplementationList;
typedef std::list < ClassInterface > ClassInterfaceList;

class File
{
public:
    File();

    ClassImplementationList classImplementations() const;
    void setClassImplementations(const ClassImplementationList &classImplementations);

    ClassImplementationList classInterfaces() const;
    void setClassInterfaces(const ClassImplementationList &classInterfaces);

private:
    ClassImplementationList _classImplementations;
    ClassImplementationList _classInterfaces;
};

}
#endif // FILE_H
