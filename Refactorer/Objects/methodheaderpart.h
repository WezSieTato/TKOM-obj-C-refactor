#ifndef METHODHEADERPART_H
#define METHODHEADERPART_H

#include "codeobject.h"

namespace objc {

class MethodHeaderPart : public CodeObject
{
public:
    MethodHeaderPart();

    string methodName() const;
    void setMethodName(const string &methodName);

    string methodType() const;
    void setMethodType(const string &methodType);

    string variableName() const;
    void setVariableName(const string &variableName);

private:
    string _methodName;
    string _methodType;
    string _variableName;
};

}

#endif // METHODHEADERPART_H
