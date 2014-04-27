#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H

#include <exception>
#include <iostream>
using namespace std;

class SourceBufor;

class ParserException : public exception
{
public:
    ParserException(SourceBufor *bufor, int position, string type);

public:
    const char *what() const throw();

    int parsingPosition() const;
    const SourceBufor *parsingBufer() const;
    string parsingType() const;

private:
    const SourceBufor * const _parsingBufer;
    const int _parsingPosition;
    const string _parsingType;

    string description;
};

#endif // PARSEREXCEPTION_H
