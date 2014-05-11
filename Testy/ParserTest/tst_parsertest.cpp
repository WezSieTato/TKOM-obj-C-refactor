#include <QString>
#include <QtTest>

#include "../../Refactorer/Parser/parser.h"
#include "../../Refactorer/Objects/codeobjects.h"

#define COMPARE_STRING(a, b) QCOMPARE(QString((a).c_str()), QString(b))
#define CREATE_PARSER( par )     QFETCH(QString, data); \
    SourceBufor bufor(data.toStdString()); \
    Parser par(&bufor);

#define NEW_DATA_ROW( a )     QTest::newRow( a ) << QString( a );

#define QTRUE( a ) QCOMPARE(a, true)
#define QFALSE( a ) QCOMPARE(a, false)

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
    NEW_DATA_ROW("NSData*** data");
    NEW_DATA_ROW("NSData ***data");
    NEW_DATA_ROW("NSData* * * data");
    NEW_DATA_ROW("NSData** * data");
    NEW_DATA_ROW("NSData *** data");
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
    QTest::newRow("Bez komentarzy i bialych znakow") << "NSData*** data" << 0 << 14;
    QTest::newRow("Biale znaki") << "   NSData**  * data" << 3 << 19;
    QTest::newRow("Komentarze") << "// komentarz1 \n   NSData**/** komentarz 2 */  * data" << 18 << 52;

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

QTEST_APPLESS_MAIN(ParserTest)

#include "tst_parsertest.moc"
