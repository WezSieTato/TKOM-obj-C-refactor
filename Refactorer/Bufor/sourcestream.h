#ifndef SOURCESTREAM_H
#define SOURCESTREAM_H

#include <iostream>

using namespace std;

class SourceStream
{
public:
    SourceStream(const string &bufor);
    char getChar() const;
    char getSourceChar(const bool &skipBlanks = true);
    string getChars(unsigned int size) const;
    string getSourceChars(unsigned int size, const bool &skipBlanks = true);

    int moveBy(const int &delta);
    int moveBySourceChars(const int &delta, const bool &skipBlanks = true);

    int pos() const;
    void setPos(int pos);

    SourceStream& operator++();
    SourceStream& operator--();


private:
    string  _bufor;
    int _pos;


};

#endif // SOURCESTREAM_H
