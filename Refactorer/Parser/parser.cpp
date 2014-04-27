#include "parser.h"

Parser::Parser(SourceBufor *bufor) :
    _bufor(bufor)
{

}

Parser &Parser::operator >>(string &str)
{
    _bufor->getSourceChar();
    string available("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_1234567890");
    while (available.find(_bufor->getChar()) != string::npos) {
       str += _bufor->getChar();
       ++(*_bufor);
    }

    return *this;
}

Parser &Parser::operator >>(stringList &strList)
{
    do{
       if(_bufor->getSourceChar() == ',')
           ++(*_bufor);
       string str;
       *this >> str;
       if(!str.size())
           break;
       strList.push_back(str);
    } while (_bufor->getSourceChar() == ',');
    return *this;
}

Parser &Parser::operator >>(objc::VariableDeclaration &varDec)
{
    _bufor->getSourceChar();
    varDec.setStartPos(_bufor->pos());
    string type;
    *this >> type;
    unsigned starCounter = 0;
    while (_bufor->getSourceChar() == '*') {
       ++starCounter;
        ++(*_bufor);
    }
    string object;
    *this >> object;

    for (unsigned i = 0; i < starCounter; ++i) {
       type += '*';
    }

    varDec.setTypeName(type);
    varDec.setObjectName(object);
    varDec.setEndPos(_bufor->pos());

    return *this;
}

Parser &Parser::operator >>(objc::PropertyDeclaration &proDec)
{
    proDec.setStartPos(_bufor->pos());
    _bufor->moveBy(10);

    if(_bufor->getSourceChar() == '('){
        ++(*_bufor);
        stringList list;
        *this >> list;
        proDec.setAttributes(list);
        if(_bufor->getSourceChar() != ')')
            throw ParserExpectedChar(_bufor, _bufor->pos(), "PropertyDeclaration", ')');
        ++(*_bufor);
    }

   objc::VariableDeclaration varDec;

   *this >> varDec;
    proDec.setVariableDec(varDec);

    if(_bufor->getSourceChar() != ';')
        throw ParserExpectedChar(_bufor, _bufor->pos(), "PropertyDeclaration", ';');

    proDec.setEndPos(_bufor->pos());

    return *this;
}
