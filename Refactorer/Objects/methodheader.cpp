#include "methodheader.h"

using namespace objc;

MethodHeader::MethodHeader()
{
}

bool MethodHeader::isStatic() const
{
    return _isStatic;
}

void MethodHeader::setStatic(bool isStatic)
{
    _isStatic = isStatic;
}

VariableType MethodHeader::type() const
{
    return _type;
}

void MethodHeader::setType(const VariableType &type)
{
    _type = type;
}

MethodName MethodHeader::partsHeaderList() const
{
    return _partsHeaderList;
}

void MethodHeader::setPartsHeaderList(const MethodName &partsHeaderList)
{
    _partsHeaderList = partsHeaderList;
}

bool MethodHeader::operator ==(const MethodHeader &other) const
{
    return (_type == other.type() && _partsHeaderList == other.partsHeaderList());
}
