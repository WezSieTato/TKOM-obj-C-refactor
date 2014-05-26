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

std::string File::getClassNameAtPosition(unsigned position)
{
    for(ClassImplementation impl : _classImplementations){
        if(impl.startPos() <= (int)position && impl.endPos() >= (int)position)
            return impl.className();
    }

    for(ClassInterface impl : _classInterfaces){
        if(impl.startPos() <= (int)position && impl.endPos() >= (int)position)
            return impl.className();
    }

    return "";
}

string File::getClassNameAtPosition(unsigned startPos, unsigned endPos)
{
    string rtn;
    rtn = getClassNameAtPosition(startPos);
    if(rtn != getClassNameAtPosition(endPos))
        return "";
    return rtn;
}

MethodDeclarationList File::getMethodDeclarationsAtPosition(unsigned startPos, unsigned endPos)
{
    MethodDeclarationList list;

    for(const ClassInterface &impl : _classInterfaces){
        if(impl.startPos() <= (int)startPos && impl.endPos() >= (int)endPos){
            for(const MethodDeclaration &meth : impl.methodDeclarations()){
                if((meth.startPos() <= (int)startPos && meth.endPos() >=(int) startPos) ||
                        (meth.startPos() >= (int)startPos && meth.endPos() <= (int)endPos) ||
                        (meth.startPos() <= (int)endPos && meth.endPos() >= (int)endPos))
                {
                    list.push_back(meth);
                }
            }
            break;
        }
    }

    return list;
}

VariableDeclarationList File::getVariableDeclarationsAtPosition(unsigned startPos, unsigned endPos)
{
    VariableDeclarationList list;
    for(const ClassInterface &impl : _classInterfaces){
        if(impl.startPos() <= (int)startPos && impl.endPos() >= (int)endPos){
            for(const VariableDeclaration &meth : impl.variableDeclarations()){
                if(((meth.startPos() <= (int)startPos && meth.endPos() >=(int) startPos) ||
                        (meth.startPos() >= (int)startPos && meth.endPos() <= (int)endPos) ||
                        (meth.startPos() <= (int)endPos && meth.endPos() >= (int)endPos))
                        && meth.objectName()[0] == '_')
                {
                    list.push_back(meth);
                }
            }
            break;
        }
    }

    return list;
}

ClassImplementation &File::getClassImplementation(string className)
{
    for(ClassImplementation &impl : _classImplementations){
        if(impl.className() == className)
            return impl;
    }


}

ClassInterface &File::getClassInterface(string className)
{
    for(ClassInterface &impl : _classInterfaces){
        if(impl.className() == className)
            return impl;
    }
}

