#ifndef PROPERTYDECLARATION_H
#define PROPERTYDECLARATION_H

#include "variabledeclaration.h"

namespace objc {

class PropertyDeclaration : public CodeObject
{
public:
    PropertyDeclaration();

    stringList attributes() const;
    void setAttributes(const stringList &attributes);

    VariableDeclaration variableDec() const;
    void setVariableDec(const VariableDeclaration &variableDec);

private:
    stringList _attributes;
    VariableDeclaration _variableDec;
};

}

#endif // PROPERTYDECLARATION_H
