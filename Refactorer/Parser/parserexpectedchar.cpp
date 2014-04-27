#include "parserexpectedchar.h"

ParserExpectedChar::ParserExpectedChar(SourceBufor *bufor, int position, string type, char expected) :
    ParserException(bufor, position, type),
    _expectedChar(expected)
{
    _description += "oczekiwany znak: ";
    _description += expected;
}

char ParserExpectedChar::expectedChar() const
{
    return _expectedChar;
}


