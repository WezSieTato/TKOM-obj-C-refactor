#ifndef VARIABLETYPE_H
#define VARIABLETYPE_H

#include "codeobject.h"

namespace objc {
class VariableType : public  CodeObject
{
public:
    VariableType();

    string type() const;
    void setType(const string &type);

    unsigned starNumber() const;
    bool isPointer() const;

private:
    string _type;
};
}
#endif // VARIABLETYPE_H
