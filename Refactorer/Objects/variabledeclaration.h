#ifndef VARIABLEDECLARATION_H
#define VARIABLEDECLARATION_H

#include "codeobject.h"

namespace objc {

class VariableDeclaration: public CodeObject
{
public:
    VariableDeclaration();

    string typeName() const;
    void setTypeName(const string &typeName);

    string objectName() const;
    void setObjectName(const string &objectName);

private:
    string _typeName;
    string _objectName;
};

}

#endif // VARIABLEDECLARATION_H
