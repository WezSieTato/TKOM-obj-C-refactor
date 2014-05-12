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

Parser &Parser::operator >>(objc::VariableType &type)
{
    setStartPos(type);
    string typeStr;
    *this >> typeStr;

    unsigned starCounter = 0;
    while (_bufor->getSourceChar() == '*') {
       ++starCounter;
        ++(*_bufor);
    }

    for(unsigned i = 0; i < starCounter; ++i){
        typeStr += '*';
    }

    type.setName(typeStr);

    setEndPos(type);
    return *this;
}

Parser &Parser::operator >>(objc::VariableDeclaration &varDec)
{
    setStartPos(varDec);
    objc::VariableType type;
    *this >> type;
    varDec.setType(type);
    string object;
    *this >> object;

    varDec.setObjectName(object);

    setEndPos(varDec);
    return *this;
}


Parser &Parser::operator >>(objc::PropertyDeclaration &proDec)
{
    setStartPos(proDec);
    _bufor->moveBy(10);

    if(_bufor->getSourceChar() == '('){
        ++(*_bufor);
        stringList list;
        *this >> list;
        proDec.setAttributes(list);
        expectedChar(')', "PropertyDeclaration");
        ++(*_bufor);
    }

   objc::VariableDeclaration varDec;

   *this >> varDec;
    proDec.setVariableDeclaration(varDec);

    expectedChar(';', "PropertyDeclaration");
    ++(*_bufor);

    setEndPos(proDec);
    return *this;
}

objc::VariableType Parser::methodInType()
{
    expectedChar('(', "Type in method");
    ++(*_bufor);

    objc::VariableType type;
    *this >> type;

    expectedChar(')', "Type in method");
    ++(*_bufor);

    return type;
}



Parser &Parser::operator >>(objc::MethodHeaderPart &methPart)
{
    setStartPos(methPart);

    string name;
    *this >> name;
    methPart.setName(name);
    expectedChar(':', "MethodHeaderPart");
    ++(*_bufor);

    objc::VariableType type = methodInType();

    objc::VariableDeclaration variable;
    variable.setType(type);
    std::string variableName;

    *this >> variableName;
    variable.setObjectName(variableName);

    setEndPos(methPart);

    return *this;
}

Parser &Parser::operator >>(objc::MethodHeader &methHead)
{
    setStartPos(methHead);

    expectedChar("-+", "MethodHeader");
    char typeChar = _bufor->getSourceChar();
    if(typeChar == '-')
        methHead.setStatic(false);
    else /*if (typeChar == '+')*/
        methHead.setStatic(true);

    ++(*_bufor);
    methHead.setType(methodInType());

    objc::MethodName head;
    do {
        objc::MethodHeaderPart part;
        *this >> part;
    } while (_bufor->getSourceChar() != ';' && _bufor->getSourceChar() != '{');
    methHead.setPartsHeaderList(head);

    setEndPos(methHead);
    return *this;
}

Parser &Parser::operator >>(objc::MethodDeclaration &methHead)
{
    setStartPos(methHead);
    objc::MethodHeader mh;
    *this >> mh;
    methHead.setHeader(mh);
    ++(*_bufor);
    setEndPos(methHead);
    return *this;
}

Parser &Parser::operator >>(objc::MethodDefinition &method)
{
    setStartPos(method);
    objc::MethodHeader mh;
    *this >> mh;
    method.setHeader(mh);
    expectedChar('{', "MethiodDefinition");
    ++(*_bufor);
    _bufor->getSourceChar();
    unsigned level = 1;
    std::string body;
    while ( !(isActualChar('}', false) && level == 1) ){
        if(isActualChar( '{',false))
            ++level;
        else if (isActualChar( '}', false))
            --level;
        body += _bufor->getSourceChar(false);
        ++(*_bufor);
    }
    expectedChar('}', "MethiodDefinition");
    ++(*_bufor);
    method.setBody(body);
    setEndPos(method);
    return *this;
}

void Parser::setStartPos(objc::CodeObject &object)
{
    _bufor->getSourceChar();
    object.setStartPos(_bufor->pos());
}

void Parser::setEndPos(objc::CodeObject &object)
{
    object.setEndPos(_bufor->pos());
}

bool Parser::isActualChar(char ch, bool skipBlanks) const
{
    return (_bufor->getSourceChar(skipBlanks) == ch);
}

bool Parser::isActualChar(string chars) const
{
    char ch = _bufor->getSourceChar();
    return (chars.find(ch) == string::npos);
}

void Parser::expectedChar(char ch, string parsedObject)
{
    if(!isActualChar(ch))
        throw ParserExpectedChar(_bufor, _bufor->pos(), parsedObject, ch);
}

void Parser::expectedChar(string chars, string parsedObject)
{
    if(isActualChar(chars)){
        std::string msg("Oczekiwano {");
        msg += chars;
        msg += " } podczas parsowania ";
        msg += parsedObject;
        throw ParserException(_bufor, _bufor->pos(), msg);
    }
}
