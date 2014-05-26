#ifndef PROPERTYREFACTORER_H
#define PROPERTYREFACTORER_H

#include "refactorer.h"

class PropertyRefactorer : public Refactorer
{
public:
    PropertyRefactorer();

    // Refactorer interface
public:
    bool operator ()(string &interface, string &implementation, unsigned startPos, unsigned endPos);
};

#endif // PROPERTYREFACTORER_H
