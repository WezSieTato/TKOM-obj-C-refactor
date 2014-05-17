#ifndef SOURCEBUFOREXCEPTION_H
#define SOURCEBUFOREXCEPTION_H

#include <exception>
#include <iostream>
using namespace std;

class SourceBufor;

class SourceBuforException : public exception
{
public:
    SourceBuforException(SourceBufor *bufor, string powod);
    virtual ~SourceBuforException() throw() {}

public:
    virtual const char *what() const throw();

private:
    const SourceBufor * const _bufor;

protected:
    string _description;
};

#endif // SOURCEBUFOREXCEPTION_H
