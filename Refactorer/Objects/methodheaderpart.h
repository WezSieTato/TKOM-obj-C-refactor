#ifndef METHODHEADERPART_H
#define METHODHEADERPART_H

#include "codeobject.h"
#include "variabledeclaration.h"

namespace objc {

class MethodHeaderPart : public CodeObject
{
public:
    MethodHeaderPart();

    string methodName() const;
    void setMethodName(const string &methodName);

    VariableDeclaration variable() const;
    void setVariable(const VariableDeclaration &variable);

private:
    string _methodName;
    VariableDeclaration _variable;
};

}

#endif // METHODHEADERPART_H
