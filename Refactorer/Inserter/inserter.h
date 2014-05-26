#ifndef INSERTER_H
#define INSERTER_H

#include "../Bufor/sourcebufor.h"
#include "../Files/file.h"

class Inserter
{
public:
    Inserter(SourceBufor* bufor, objc::File file);

    Inserter& operator << (objc::MethodDefinition& definition);

    std::string currentClass() const;
    void setCurrentClass(const std::string &currentClass);

private:
    SourceBufor* _bufor;
    objc::File _file;
    std::string _currentClass;
};

#endif // INSERTER_H
