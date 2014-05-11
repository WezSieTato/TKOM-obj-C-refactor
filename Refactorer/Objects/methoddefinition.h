#ifndef METHODDEFINITION_H
#define METHODDEFINITION_H

#include "methoddeclaration.h"

namespace objc {

class MethodDefinition : public MethodDeclaration
{
public:
    MethodDefinition();

    std::string body() const;
    void setBody(const std::string &body);

private:
    std::string _body;
};

}
#endif // METHODDEFINITION_H
