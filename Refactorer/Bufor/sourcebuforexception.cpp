#include "sourcebuforexception.h"
#include <sstream>

SourceBuforException::SourceBuforException(SourceBufor *bufor, string powod) :
    _bufor(bufor)
{
    std::stringstream stream;
    stream << std::hex << ((int)((size_t)(bufor)));
    std::string result( stream.str() );
    _description += "Blad na buforze: 0x" + result + " powod: " + powod;
}

const char *SourceBuforException::what() const throw()
{
    return _description.c_str();
}
