#include <QString>
#include <QtTest>

#include "../../Refactorer/Parser/parser.h"

#define COMPARE_STRING(a, b) QCOMPARE(QString((a).c_str()), QString(b));
#define CREATE_PARSER( par )     QFETCH(QString, data); \
SourceBufor bufor(data.toStdString()); \
Parser par(&bufor);

#define NEW_DATA_ROW( a )     QTest::newRow( a ) << QString( a );


class ParserTest : public QObject
{
    Q_OBJECT

public:
    ParserTest();
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void parseString();
    void parseString_data();
    void parseStringList();
    void parseStringList_data();
};

ParserTest::ParserTest()
{
}

void ParserTest::initTestCase()
{
}

void ParserTest::cleanupTestCase()
{
}

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

QTEST_APPLESS_MAIN(ParserTest)

#include "tst_parsertest.moc"
