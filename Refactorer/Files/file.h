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


    ClassInterfaceList classInterfaces() const;
    void setClassInterfaces(const ClassInterfaceList &classInterfaces);

    std::string getClassNameAtPosition(unsigned position);
    std::string getClassNameAtPosition(unsigned startPos, unsigned endPos);

    MethodDeclarationList getMethodDeclarationsAtPosition(unsigned startPos, unsigned endPos);
    VariableDeclarationList getVariableDeclarationsAtPosition(unsigned startPos, unsigned endPos);

    ClassImplementation& getClassImplementation(std::string className);
private:
    ClassImplementationList _classImplementations;
    ClassInterfaceList _classInterfaces;
};

}
#endif // FILE_H
