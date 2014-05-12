#ifndef SOURCEBUFOROUTOFBONDSEXCEPTION_H
#define SOURCEBUFOROUTOFBONDSEXCEPTION_H

#include "sourcebuforexception.h"

class SourceBuforOutOfBoundsException : public SourceBuforException
{
public:
    SourceBuforOutOfBoundsException(SourceBufor *bufor, int pos);

    int pos() const;

private:
    const int _pos;
};

#endif // SOURCEBUFOROUTOFBONDSEXCEPTION_H
