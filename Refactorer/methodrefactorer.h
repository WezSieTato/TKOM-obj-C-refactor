#ifndef METHODREFACTORER_H
#define METHODREFACTORER_H

#include "refactorer.h"

class MethodRefactorer : public Refactorer
{
public:
    MethodRefactorer();

    // Refactorer interface
public:
    bool operator ()(std::string &interface, std::string &implementation, unsigned startPos, unsigned endPos);

private:
    void createBody(objc::MethodDefinition &definition);
};

#endif // METHODREFACTORER_H
