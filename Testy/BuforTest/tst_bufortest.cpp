#include <QString>
#include <QtTest>
#include <iostream>

#include "../Refactorer/Bufor/sourcestream.h"

using namespace std;

class BuforTest : public QObject
{
    Q_OBJECT

public:
    BuforTest();

    void standardData();
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void inkrementacja();
    void inkrementacja_data();
    void setPos();
    void setPos_data();
    void getSourceChar();
    void getSourceChar_data();

};

BuforTest::BuforTest()
{
}

void BuforTest::initTestCase()
{
}

void BuforTest::cleanupTestCase()
{
}

void BuforTest::inkrementacja()
{
    QFETCH(QString, data);
    SourceStream stream(data.toStdString());
    for (int i = 0; i < 5; ++i) {
        QCOMPARE(stream.getChar(), data.toStdString()[i]);
        ++stream;
    }
}

void BuforTest::standardData()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("Simply string") << "abcdefghijklmnoprstwz";
    QTest::newRow("String with spaces") << "ab cd ef gh ij kl mn op rs twz";
    QTest::newRow("String with spaces and enter") << "a\nb c\nd e\nf g\nh i\nj k\nl m\nn o\np r\ns t\nwz";
    QTest::newRow("String with //") << "abcd//tutaj jest komentarz\nefg//i tu tez jest; \nhijklmnoprstwz";
    QTest::newRow("String with /* */") << "abc/*   komentarz */de/*   ***  */fgh/*********/ijklmnoprstwz";
    QTest::newRow("String with and spaces //") << "abcd//tutaj jest komentarz\n efg//i tu tez jest; \n hijklmnoprstwz";
    QTest::newRow("String with /* */ and spaces") << "abc/*   komentarz */ d e/*   ***  */fgh/*********/ ijklm noprs twz";

}

void BuforTest::inkrementacja_data()
{
    standardData();
}

void BuforTest::setPos()
{
    QFETCH(QString, data);
    SourceStream stream(data.toStdString());
    string str = data.toStdString();
    for (int i = 0; i < 10; ++++i) {
        stream.setPos(i);
        QCOMPARE(stream.getChar(), str[i]);
    }
}

void BuforTest::setPos_data()
{
    standardData();
}

void BuforTest::getSourceChar()
{
    QFETCH(QString, data);
    SourceStream stream(data.toStdString());
    string results("abcdefghijklmnoprstwz");
    for(unsigned int i = 0; i < results.length() ; ++i){
        QCOMPARE(stream.getSourceChar(), results[i]);
        ++stream;
    }
}

void BuforTest::getSourceChar_data()
{
    standardData();
}

QTEST_APPLESS_MAIN(BuforTest)

#include "tst_bufortest.moc"
