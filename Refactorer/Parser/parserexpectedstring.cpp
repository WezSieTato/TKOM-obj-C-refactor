#include "parserexpectedstring.h"

ParserExpectedString::ParserExpectedString(SourceBufor *bufor, int position, string type, string expected) :
    ParserException(bufor, position, type)
{
    _description += " oczekiwany ciag: ";
    _description += expected;
}

std::string ParserExpectedString::expectedString() const
{
    return _expectedString;
}

