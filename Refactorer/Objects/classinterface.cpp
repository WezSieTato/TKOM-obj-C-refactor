#include "classinterface.h"

using namespace objc;

ClassInterface::ClassInterface()
{
}

std::string ClassInterface::baseClass() const
{
    return _baseClass;
}

void ClassInterface::setBaseClass(const std::string &baseClass)
{
    _baseClass = baseClass;
}

VariableDeclarationList ClassInterface::variableDeclarations() const
{
    return _variableDeclarations;
}

void ClassInterface::setVariableDeclarations(const VariableDeclarationList &variableDeclarations)
{
    _variableDeclarations = variableDeclarations;
}

PropertyDeclarationList ClassInterface::propertyDeclarations() const
{
    return _propertyDeclarations;
}

void ClassInterface::setPropertyDeclarations(const PropertyDeclarationList &propertyDeclarations)
{
    _propertyDeclarations = propertyDeclarations;
}

MethodDeclarationList ClassInterface::methodDeclarations() const
{
    return _methodDeclarations;
}

void ClassInterface::setMethodDeclarations(const MethodDeclarationList &methodDeclarations)
{
    _methodDeclarations = methodDeclarations;
}

unsigned ClassInterface::addPropertyDeclaration(PropertyDeclaration &propertyDeclaration, int size)
{
    unsigned pos;
    if(_propertyDeclarations.size()){
         pos = _propertyDeclarations.back().endPos();
    } else if(_methodDeclarations.size()){
        pos = _methodDeclarations.front().startPos();
    } else {
        pos = endPos() - 4;
    }

    propertyDeclaration.setStartPos(pos);
    propertyDeclaration.setEndPos(pos +size);

    _propertyDeclarations.push_back(propertyDeclaration);

    return pos;
}

bool ClassInterface::isProperty(const VariableDeclaration &variableDeclaration) const
{
    std::string name(variableDeclaration.objectName());
    name.erase(0, 1);

    for(const PropertyDeclaration& prop : _propertyDeclarations){
        if(prop.variableDeclaration().objectName() == name)
            return true;
    }

    return false;
}
