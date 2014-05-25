#ifndef REFACTORER_H
#define REFACTORER_H

#include "Parser/parser.h"
#include "Inserter/inserter.h"

class Refactorer
{
public:
    Refactorer();
    virtual bool operator () (std::string &interface, std::string &implementation, unsigned startPos, unsigned endPos) = 0;

protected:
    void setUp(std::string &interface, std::string &implementation);
    void cleanUp();

    SourceBufor *_interfaceBufor;
    SourceBufor *_implementationBufor;

    objc::File _interfaceFile;
    objc::File _implementationFile;
};

#endif // REFACTORER_H
