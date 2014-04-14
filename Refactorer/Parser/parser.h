#ifndef PARSER_H
#define PARSER_H

#include "../Bufor/sourcebufor.h"

class Parser
{
public:
    Parser(SourceBufor* bufor);

    Parser& operator >> (std::string& str);
private:
    SourceBufor*_bufor;
};

#endif // PARSER_H
