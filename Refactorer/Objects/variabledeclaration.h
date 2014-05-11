#ifndef VARIABLEDECLARATION_H
#define VARIABLEDECLARATION_H

#include "variabletype.h"

namespace objc {

class VariableDeclaration: public CodeObject
{
public:
    VariableDeclaration();

    string objectName() const;
    void setObjectName(const string &objectName);

    VariableType type() const;
    void setType(const VariableType &type);

private:
    VariableType _type;
    string _objectName;
};

}

#endif // VARIABLEDECLARATION_H
