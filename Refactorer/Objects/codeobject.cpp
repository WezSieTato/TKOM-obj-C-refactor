#include "codeobject.h"

using namespace objc;

CodeObject::CodeObject()
{
}
int CodeObject::startPos() const
{
    return _startPos;
}

void CodeObject::setStartPos(int startPos)
{
    _startPos = startPos;
}
int CodeObject::endPos() const
{
    return _endPos;
}

void CodeObject::setEndPos(int endPos)
{
    _endPos = endPos;
}


