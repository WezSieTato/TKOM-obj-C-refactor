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
    void setStarNumber(const unsigned &starNumber);

    bool isPointer() const;

private:
    string _type;
    unsigned _starNumber;
};
}
#endif // VARIABLETYPE_H
