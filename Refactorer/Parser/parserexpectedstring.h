#ifndef PARSEREXPECTEDSTRING_H
#define PARSEREXPECTEDSTRING_H

#include "parserexception.h"

class ParserExpectedString : public ParserException
{
public:
    ParserExpectedString(SourceBufor *bufor, int position, string type, std::string expected);
    std::string expectedString() const;
    virtual ~ParserExpectedString() throw() {}
private:
    const std::string _expectedString;
};

#endif // PARSEREXPECTEDSTRING_H
