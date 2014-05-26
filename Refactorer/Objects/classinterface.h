#ifndef CLASSINTERFACE_H
#define CLASSINTERFACE_H

#include "propertydeclaration.h"
#include "methoddeclaration.h"
#include "classpart.h"

namespace objc {

typedef std::list< VariableDeclaration > VariableDeclarationList;
typedef std::list< PropertyDeclaration > PropertyDeclarationList;
typedef std::list< MethodDeclaration > MethodDeclarationList;


class ClassInterface : public ClassPart
{
public:
    ClassInterface();

    std::string baseClass() const;
    void setBaseClass(const std::string &baseClass);

    VariableDeclarationList variableDeclarations() const;
    void setVariableDeclarations(const VariableDeclarationList &variableDeclarations);

    PropertyDeclarationList propertyDeclarations() const;
    void setPropertyDeclarations(const PropertyDeclarationList &propertyDeclarations);

    MethodDeclarationList methodDeclarations() const;
    void setMethodDeclarations(const MethodDeclarationList &methodDeclarations);

    unsigned addPropertyDeclaration(PropertyDeclaration& propertyDeclaration, int size);

    bool isProperty(const VariableDeclaration& variableDeclaration) const;

private:

    std::string _baseClass;

    VariableDeclarationList _variableDeclarations;
    PropertyDeclarationList _propertyDeclarations;
    MethodDeclarationList _methodDeclarations;
};

}
#endif // CLASSINTERFACE_H
