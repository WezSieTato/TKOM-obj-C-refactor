#include "parserexception.h"
using namespace std;

#include <sstream>

ParserException::ParserException(SourceBufor *bufor, int position, string type) :
 _parsingBufer(bufor),
  _parsingPosition(position),
  _parsingType(type)
{
    std::stringstream stream;
    stream << std::hex << ((int)((size_t)(bufor)));
    std::string result( stream.str() );
    _description += "Blad podczas parsowania: 0x" + result + " na pozycji: "
                + to_string(position) + " parsowany obiekt: " + type;
}

const char *ParserException::what() const throw()
{
    return _description.c_str();
}

int ParserException::parsingPosition() const
{
    return _parsingPosition;
}

const SourceBufor *ParserException::parsingBufer() const
{
    return _parsingBufer;
}
string ParserException::parsingType() const
{
    return _parsingType;
}




