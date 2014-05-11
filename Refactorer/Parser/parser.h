#ifndef PARSER_H
#define PARSER_H

#include "../Bufor/sourcebufor.h"
#include "../Objects/codeobjects.h"
#include <list>
#include "parserexpectedchar.h"

class Parser
{
public:
    Parser(SourceBufor* bufor);

    Parser& operator >> (std::string& str);
    Parser& operator >> (stringList& strList);
    Parser& operator >> (objc::VariableType& type);
    Parser& operator >> (objc::VariableDeclaration& varDec);
    Parser& operator >> (objc::PropertyDeclaration& proDec);
    Parser& operator >> (objc::MethodHeaderPart& methPart);
    Parser& operator >> (objc::MethodHeader& methHead);
    Parser& operator >> (objc::MethodHeaderDeclaration& methHead);

private:
    void setStartPos(objc::CodeObject& object);
    void setEndPos(objc::CodeObject& object);

    objc::VariableType methodInType();

    SourceBufor*_bufor;
};

#endif // PARSER_H
