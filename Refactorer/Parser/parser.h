#ifndef PARSER_H
#define PARSER_H

#include "../Bufor/sourcebufor.h"
#include "../Objects/codeobjects.h"
#include "parserexpectedchar.h"
#include "parserexpectedstring.h"

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
    Parser& operator >> (objc::MethodDeclaration& methHead);
    Parser& operator >> (objc::MethodDefinition& method);
    Parser& operator >> (objc::SynthesizedVariable& variable);
    Parser& operator >> (objc::SynthesizeBlock &block);
    Parser& operator >> (objc::ClassInterface &classInterface);
    Parser& operator >> (objc::ClassImplementation &classImplementation);



private:
    void setStartPos(objc::CodeObject& object);
    void setEndPos(objc::CodeObject& object);

    objc::VariableType methodInType();
    bool isActualChar(char ch, bool skipBlanks = true) const;
    bool isActualChar(std::string chars) const;
    bool isActualString(std::string expected, bool skipBlanks = false) const;

    void expectedChar(char ch, std::string parsedObject);
    void expectedChar(std::string chars, std::string parsedObject);
    void expectedString(std::string expected, std::string parsedObject);

    SourceBufor*_bufor;
};

#endif // PARSER_H
