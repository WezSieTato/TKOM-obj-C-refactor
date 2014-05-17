#ifndef CLASSPART_H
#define CLASSPART_H

#include "codeobject.h"

namespace objc {

class ClassPart : public CodeObject
{
public:
    ClassPart();

    std::string className() const;
    void setClassName(const std::string &className);

private:
    std::string _className;
};

}

#endif // CLASSPART_H
