#include "sourcebufor.h"

SourceBufor::SourceBufor(const string &bufor) :
    _bufor(bufor),
    _pos(0)
{

}

char SourceBufor::getChar() const
{
    return _bufor[_pos];
}

char SourceBufor::getSourceChar(const bool &skipBlanks)
{
    char ch = getChar();
    if(skipBlanks){
      while(isspace(ch)){
          ++*this;
          ch = getChar();
      }
    }

    if(ch == '/'){
        ++*this;
        char next = getChar();
        if(next == '/'){
            while(getChar() != '\n'){
                ++*this;
            }
            ++*this;
            ch = getSourceChar(skipBlanks);
        } else if (next == '*'){
            while (getChars(2) != "*/"){
                ++*this;
            }
            ++++*this;
            ch = getSourceChar(skipBlanks);
        } else {
            --*this;
        }
    }

    return ch;
}

string SourceBufor::getChars(unsigned int size) const
{
    return _bufor.substr(_pos, size);
}

string SourceBufor::getSourceChars(unsigned int size, const bool &skipBlanks)
{
    if(!size)
        return string("");

    string str;
    str +=getSourceChar(skipBlanks) ;
    int p = pos();
    for (unsigned int i = 0; i < size; ++i) {
        str +=getSourceChar(skipBlanks) ;
    }
    setPos(p);
    return str;
}

int SourceBufor::moveBy(const int &delta)
{
    _pos += delta;
    return pos();
}

int SourceBufor::moveBySourceChars(const int &delta, const bool &skipBlanks)
{
    for (int i = 0; i < delta; ++i) {
       getSourceChar(skipBlanks);
       ++*this;
    }
    return pos();
}


int SourceBufor::pos() const
{
    return _pos;
}

void SourceBufor::setPos(int pos)
{
    _pos = pos;
}

SourceBufor &SourceBufor::operator++()
{
    ++_pos;
    return *this;
}

SourceBufor &SourceBufor::operator--()
{
    --_pos;
    return *this;
}
