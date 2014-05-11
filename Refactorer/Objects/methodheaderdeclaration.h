#ifndef METHODHEADERDECLARATION_H
#define METHODHEADERDECLARATION_H

#include "methodheader.h"

namespace objc {

class MethodHeaderDeclaration : public CodeObject
{
public:
    MethodHeaderDeclaration();

    MethodHeader header() const;
    void setHeader(const MethodHeader &header);

private:
    MethodHeader _header;
};

}
#endif // METHODHEADERDECLARATION_H
