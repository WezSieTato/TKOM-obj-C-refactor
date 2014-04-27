#ifndef PARSEREXPECTEDCHAR_H
#define PARSEREXPECTEDCHAR_H

#include "parserexception.h"

class ParserExpectedChar : public ParserException
{
public:
    ParserExpectedChar(SourceBufor *bufor, int position, string type, char expected);
    char expectedChar() const;
private:
    const char _expectedChar;
};

#endif // PARSEREXPECTEDCHAR_H
