#ifndef CODEOBJECT_H
#define CODEOBJECT_H

#include <iostream>
#include <list>
using namespace std;

typedef std::list< std::string > stringList;

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
