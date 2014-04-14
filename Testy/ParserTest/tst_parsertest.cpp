#include <QString>
#include <QtTest>

#include "../../Refactorer/Parser/parser.h"

#define COMPARE_STRING(a, b) QCOMPARE(QString(a.c_str()), QString(b));

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
    QFETCH(QString, data);
    QFETCH(QString, result);

    SourceBufor bufor(data.toStdString());
    std::string par_str;
    Parser par(&bufor);
    par >> par_str;
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


}

QTEST_APPLESS_MAIN(ParserTest)

#include "tst_parsertest.moc"
