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

using namespace objc;

class ParserTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void parseString();
    void parseString_data();
    void parseStringList();
    void parseStringList_data();
    void parseVariableDeclaration();
    void parseVariableDeclaration_data();
    void parsePositioning();
    void parsePositioning_data();
    void parsePropertyDeclarationException();
    void parsePropertyDeclarationException_data();
    void parsePropertyDeclaration();
    void parsePropertyDeclaration_data();

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

void ParserTest::parseVariableDeclaration()
{
    CREATE_PARSER( par );
    VariableDeclaration var;
    par >> var;
    COMPARE_STRING(var.type().type(), "NSData");
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

    COMPARE_STRING(propDec.variableDec().objectName(), "data");
    COMPARE_STRING(propDec.variableDec().type().type(), "NSData");
    QTRUE(propDec.variableDec().type().isPointer());
    QCOMPARE(propDec.variableDec().type().starNumber(), 1U);

}

void ParserTest::parsePropertyDeclaration_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("") << "@property (nonatomic, readonly, assign) NSData* data;";

}

QTEST_APPLESS_MAIN(ParserTest)

#include "tst_parsertest.moc"
