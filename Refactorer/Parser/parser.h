#ifndef PARSER_H
#define PARSER_H

#include "../Bufor/sourcebufor.h"
#include "../Objects/codeobjects.h"

#include <list>

typedef std::list< std::string > stringList;

class Parser
{
public:
    Parser(SourceBufor* bufor);

    Parser& operator >> (std::string& str);
    Parser& operator >> (stringList& strList);
    Parser& operator >> (objc::VariableDeclaration& varDec);

private:
    SourceBufor*_bufor;
};

#endif // PARSER_H
