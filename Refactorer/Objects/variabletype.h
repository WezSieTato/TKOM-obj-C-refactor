#ifndef VARIABLETYPE_H
#define VARIABLETYPE_H

#include "codeobject.h"

namespace objc {
class VariableType : public  CodeObject
{
public:
    VariableType();

    string name() const;
    void setName(const string &name);

    unsigned starNumber() const;
    bool isPointer() const;

    bool operator == (const VariableType& other) const;

private:
    string _name;
};
}
#endif // VARIABLETYPE_H
