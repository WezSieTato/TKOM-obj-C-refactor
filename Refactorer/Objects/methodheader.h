#ifndef METHODHEADER_H
#define METHODHEADER_H

#include "methodheaderpart.h"


namespace objc {

typedef std::list< objc::MethodHeaderPart > MethodName;

class MethodHeader : public CodeObject
{
public:
    MethodHeader();

    bool isStatic() const;
    void setStatic(bool isStatic);

    VariableType type() const;
    void setType(const VariableType &type);

    MethodName partsHeaderList() const;
    void setPartsHeaderList(const MethodName &partsHeaderList);

private:
    bool _isStatic;
    VariableType _type;
    MethodName _partsHeaderList;
};

}

#endif // METHODHEADER_H
