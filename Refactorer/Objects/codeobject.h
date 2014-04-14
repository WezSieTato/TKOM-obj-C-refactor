#ifndef CODEOBJECT_H
#define CODEOBJECT_H

#include <iostream>
using namespace std;

namespace objc {

class CodeObject
{
public:
    CodeObject();

    int startPos() const;
    void setStartPos(int startPos);

    int endPos() const;
    void setEndPos(int endPos);

private:
    int _startPos;
    int _endPos;
};

}

#endif // CODEOBJECT_H
