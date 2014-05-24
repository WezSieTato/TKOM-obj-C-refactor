#ifndef METHODHEADERPART_H
#define METHODHEADERPART_H

#include "codeobject.h"
#include "variabledeclaration.h"

namespace objc {

class MethodHeaderPart : public CodeObject
{
public:
    MethodHeaderPart();

    string name() const;
    void setName(const string &name);

    VariableDeclaration variable() const;
    void setVariable(const VariableDeclaration &variable);

    bool isParameter() const;

private:
    string _methodName;
    VariableDeclaration _variable;
    bool _isParameter;
};

}

#endif // METHODHEADERPART_H
