#include <QString>
#include <QtTest>

#include "../../Refactorer/Parser/parser.h"
#include "../macrostest.h"

#define CREATE_PARSER( par )     QFETCH(QString, data); \
    SourceBufor bufor(data.toStdString()); \
    Parser par(&bufor);

#define NEW_DATA_ROW( a )     QTest::newRow( a ) << QString( a );

using namespace objc;

class ParserTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void parseString();
    void parseString_data();
    void parseStringList();
    void parseStringList_data();
    void parseVariableNotPointer();
    void parseVariableNotPointer_data();
    void parseVariableDeclaration();
    void parseVariableDeclaration_data();
    void parsePositioning();
    void parsePositioning_data();
    void parsePropertyDeclarationException();
    void parsePropertyDeclarationException_data();
    void parsePropertyDeclaration();
    void parsePropertyDeclaration_data();
    void parseMethodHeaderPart();
    void parseMethodHeaderPart_data();
    void parseMethodHeader();
    void parseMethodHeader_data();
    void parseMethodHeaderDeclaration();
    void parseMethodHeaderDeclaration_data();
    void parseMethodDefinition();
    void parseMethodDefinition_data();
    void parseSynthesizedVariable();
    void parseSynthesizedVariable_data();
    void parseSynthesizeBlock();
    void parseSynthesizeBlock_data();
    void parseClassInterface();
    void parseClassInterface_data();
    void parseClassImplementation();
    void parseClassImplementation_data();
    void parseFile();
    void parseFile_data();

};

void ParserTest::parseString()
{
    CREATE_PARSER( par );
    std::string par_str;
    par >> par_str;
    QFETCH(QString, result);
    COMPARE_STRING(par_str, result);
}

void ParserTest::parseString_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<QString>("result");

    QTest::newRow("string") << QString("string") << "string";
    QTest::newRow("string:qs") << QString("string:qs") << "string";
    QTest::newRow("_12string:qs") << QString("_12string:qs") << "_12string";
    QTest::newRow("_12string#qs") << QString("_12string#qs") << "_12string";
    QTest::newRow("_12string qs") << QString("_12string qs") << "_12string";
    QTest::newRow(" string qs") << QString(" _12string qs") << "_12string";
    QTest::newRow("/* kom */ string qs") << QString("/* kom */ string qs") << "string";

}

void ParserTest::parseStringList()
{
    CREATE_PARSER( par );
    stringList list;
    par >> list;
    QCOMPARE((int)(list.size()), 3);
    stringList::iterator it(list.begin());
    COMPARE_STRING(*it, "string" );
    ++it;
    COMPARE_STRING(*it, "_string" );
    ++it;
    COMPARE_STRING(*it, "STR1NG" );

}

void ParserTest::parseStringList_data()
{
    QTest::addColumn<QString>("data");
    NEW_DATA_ROW("string, _string, STR1NG");
    NEW_DATA_ROW(" string , _string/**** ssss */ ,STR1NG:");
}

void ParserTest::parseVariableNotPointer()
{
    CREATE_PARSER( par );
    VariableType var;
    par >> var;
    QFALSE( var.isPointer() );
}

void ParserTest::parseVariableNotPointer_data()
{
    QTest::addColumn<QString>("data");
    NEW_DATA_ROW("int");
}

void ParserTest::parseVariableDeclaration()
{
    CREATE_PARSER( par );
    VariableDeclaration var;
    par >> var;
    COMPARE_STRING(var.type().name(), "NSData***");
    QCOMPARE((int)var.type().starNumber(), 3);
    QTRUE(var.type().isPointer());
    COMPARE_STRING(var.objectName(), "data");
}

void ParserTest::parseVariableDeclaration_data()
{
    QTest::addColumn<QString>("data");
    NEW_DATA_ROW("NSData*** data;");
    NEW_DATA_ROW("NSData ***data;");
    NEW_DATA_ROW("NSData* * * data;");
    NEW_DATA_ROW("NSData** * data;");
    NEW_DATA_ROW("NSData *** data;");
}

void ParserTest::parsePositioning()
{
    CREATE_PARSER(par);
    VariableDeclaration var;
    par >> var;
    QFETCH(int, start);
    QCOMPARE(var.startPos(), start);
    QFETCH(int, end);
    QCOMPARE(var.endPos(), end);
}

void ParserTest::parsePositioning_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<int>("start");
    QTest::addColumn<int>("end");
    QTest::newRow("Bez komentarzy i bialych znakow") << "NSData*** data;" << 0 << 15;
    QTest::newRow("Biale znaki") << "   NSData**  * data;" << 3 << 20;
    QTest::newRow("Komentarze") << "// komentarz1 \n   NSData**/** komentarz 2 */  * data;" << 18 << 53;

}

void ParserTest::parsePropertyDeclarationException()
{
    CREATE_PARSER(par);
    QFETCH(int, pos);
    QFETCH(char, ch);
    bool isException = false;
    try{
        PropertyDeclaration propDec;
        par >> propDec;
    } catch (ParserExpectedChar pe){
        isException = true;
        COMPARE_STRING(pe.parsingType(), "PropertyDeclaration");
        QCOMPARE(pe.parsingPosition(), pos);
        QCOMPARE(pe.expectedChar(), ch);
    }
    QTRUE(isException);

}

void ParserTest::parsePropertyDeclarationException_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<int>("pos");
    QTest::addColumn<char>("ch");

    QTest::newRow(")") << "@property (dos, sd, asd d" << 24 << ')';
    QTest::newRow(";") << "@property (dos, sd, asd ) NSData* data d" << 39 << ';';

}

void ParserTest::parsePropertyDeclaration()
{
    CREATE_PARSER(par);
    PropertyDeclaration propDec;
    par >> propDec;

    COMPARE_STRING(propDec.variableDeclaration().objectName(), "data");
    COMPARE_STRING(propDec.variableDeclaration().type().name(), "NSData*");
    QTRUE(propDec.variableDeclaration().type().isPointer());
    QCOMPARE(propDec.variableDeclaration().type().starNumber(), 1U);

}

void ParserTest::parsePropertyDeclaration_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("Z atrybutami") << "@property (nonatomic, readonly, assign) NSData* data;";
    QTest::newRow("Bez atrybutami") << "@property NSData* data;";

}

void ParserTest::parseMethodHeaderPart()
{
    CREATE_PARSER(par);
    MethodHeaderPart headerPart;
    par >> headerPart;

    QFETCH(QString, name);
    QFETCH(int, start);
    QFETCH(int, end);

    COMPARE_STRING(headerPart.name(), name);
    QCOMPARE(headerPart.startPos(), start);
    QCOMPARE(headerPart.endPos(), end);
}

void ParserTest::parseMethodHeaderPart_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<QString>("name");
    QTest::addColumn<int>("start");
    QTest::addColumn<int>("end");

    QTest::newRow("") << "metodaTestowa:(NSData*)firstPatametr" << "metodaTestowa" << 0 << 36;
}

void ParserTest::parseMethodHeader()
{
    CREATE_PARSER(par);
    MethodHeader header;
    par >> header;
    QTRUE(header.isStatic());
    COMPARE_STRING(header.type().name(), "NSData*");
    QCOMPARE((int)header.partsHeaderList().size(), 2);
}

void ParserTest::parseMethodHeader_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("") << "+(NSData*)getDataFromURL:(NSURL*)url andObject:(NSObject*)object;";
}

void ParserTest::parseMethodHeaderDeclaration()
{
    CREATE_PARSER(par);
    MethodDeclaration header;
    par >> header;
    QTRUE(header.header().isStatic());
    COMPARE_STRING(header.header().type().name(), "NSData*");
}

void ParserTest::parseMethodHeaderDeclaration_data()
{
    parseMethodHeader_data();
}

void ParserTest::parseMethodDefinition()
{
    CREATE_PARSER(par);
    MethodDefinition method;
    par >> method;
    QFETCH(QString, body);
    COMPARE_STRING(method.body(), body);
    QFETCH(int, startPos);
    QCOMPARE(method.startPos(), startPos);
    QFETCH(int, endPos);
    QCOMPARE(method.endPos(), endPos);
}

void ParserTest::parseMethodDefinition_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<QString>("body");
    QTest::addColumn<int>("startPos");
    QTest::addColumn<int>("endPos");


    QTest::newRow("Bez zagniezdzen") << "+(NSData*)getDataFromURL:(NSURL*)url{ body = siema }"
                                     << "body = siema " << 0 << 52;
    QTest::newRow("Z zagniedzeniami") << "/** siema **/+(NSData*)getDataFromURL:(NSURL*)url{ body = siema  { {;} } }"
                                      << "body = siema  { {;} } " << 13 << 74 ;
}

void ParserTest::parseSynthesizedVariable()
{
    CREATE_PARSER(par);
    SynthesizedVariable synth;
    par >> synth;
    QFETCH(QString, property);
    QFETCH(QString, variable);
    COMPARE_STRING(synth.propertyName(), property);
    COMPARE_STRING(synth.variableName(), variable);
}

void ParserTest::parseSynthesizedVariable_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<QString>("property");
    QTest::addColumn<QString>("variable");

    QTest::newRow("Samo property") << "data" << "data" << "data";
    QTest::newRow("property = variable") << "data = _data" << "data" << "_data";

}

void ParserTest::parseSynthesizeBlock()
{
    CREATE_PARSER(par);
    SynthesizeBlock block;
    par >> block;
    QFETCH(int, ilosc);
    QCOMPARE((unsigned int)block.propertyList().size(), (unsigned int)ilosc);

}

void ParserTest::parseSynthesizeBlock_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<int>("ilosc");

    QTest::newRow("puste") << "@synthesize;" << 0;
    QTest::newRow("1") << "@synthesize data;" << 1;
    QTest::newRow("3") << "@synthesize data, date = _date, halo = siema;" << 3;
}

void ParserTest::parseClassInterface()
{
    CREATE_PARSER(par);
    ClassInterface classInterface;
    par >> classInterface;
    COMPARE_STRING(classInterface.className(), "MyClass");
    COMPARE_STRING(classInterface.baseClass(), "NSObject");
}

void ParserTest::parseClassInterface_data()
{
    QTest::addColumn<QString>("data");

    QTest::newRow("Pusta") << "@interface MyClass : NSObject @end";
    QTest::newRow("Protocols") << "@interface MyClass : NSObject < DataDelegates, TKOMProject > @end";
    QTest::newRow("{}") << "@interface MyClass : NSObject{} @end";
    QTest::newRow("property") << "@interface MyClass : NSObject{} @property () NSData* data; @end";
    QTest::newRow("method") << "@interface MyClass : NSObject +(NSData*)getDataFromURL:(NSURL*)url andObject:(NSObject*)object; @end";
    QTest::newRow("method i property") << "@interface MyClass : NSObject @property () NSData* data; +(NSData*)getDataFromURL:(NSURL*)url andObject:(NSObject*)object; @end";

}

void ParserTest::parseClassImplementation()
{
    CREATE_PARSER(par);
    ClassImplementation classInterface;
    par >> classInterface;
    COMPARE_STRING(classInterface.className(), "MyClass");
}

void ParserTest::parseClassImplementation_data()
{
    QTest::addColumn<QString>("data");

    QTest::newRow("Pusta") << "@implementation MyClass @end";
    QTest::newRow("Synthesize") << "@implementation MyClass @synthesize data, tkom = _tkom; @end";
    QTest::newRow("Synthesize i method") << "@implementation MyClass @synthesize data, tkom = _tkom; +(NSData*)getDataFromURL:(NSURL*)url andObject:(NSObject*)object{} @end";
    QTest::newRow("method") << "@implementation MyClass +(NSData*)getDataFromURL:(NSURL*)url andObject:(NSObject*)object{} @end";


}

void ParserTest::parseFile()
{
    CREATE_PARSER(par);
    File file;
    par >> file;
    int count = 0;
    count += file.classImplementations().size() + file.classInterfaces().size();
    QCOMPARE(count, 1);
}

void ParserTest::parseFile_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("InterFace") << INTERFACE_FILE;
    QTest::newRow("Implementation") << IMPLEMENTATION_FILE;

}

QTEST_APPLESS_MAIN(ParserTest)

#include "tst_parsertest.moc"
