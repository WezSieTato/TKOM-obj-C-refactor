#include <QString>
#include <QtTest>
#include <iostream>

#include "../../Refactorer/Bufor/sourcebufor.h"

using namespace std;

#include "../macrostest.h"

#define CREATE_BUFOR( a ) QFETCH(QString, data); \
SourceBufor a(data.toStdString());

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
    void inkrementacjaException();
    void inkrementacjaException_data();
    void dekrementacjaException();
    void dekrementacjaException_data();
    void moveByException();
    void moveByException_data();
    void setPos();
    void setPos_data();
    void getSourceChar();
    void getSourceChar_data();
    void isEnd();
    void isEnd_data();

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
    CREATE_BUFOR(stream);
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

void BuforTest::inkrementacjaException()
{
    CREATE_BUFOR(stream);
    bool isException = false;
    try{
        while(true){
            ++stream;
        }
    } catch (SourceBuforOutOfBoundsException pe){
        isException = true;
        QFETCH(int, pos);
        QCOMPARE(pe.pos(), pos );
    }
    QTRUE(isException);
}

void BuforTest::inkrementacjaException_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<int>("pos");

    QTest::newRow("0") << "" << 1;
    QTest::newRow("1") << "1" << 2;
    QTest::newRow("2") << "//" << 3;
    QTest::newRow("5") << "/* */" << 6;

}

void BuforTest::dekrementacjaException()
{
    CREATE_BUFOR(stream);
    bool isException = false;
    try{
        while(true){
            --stream;
        }
    } catch (SourceBuforOutOfBoundsException pe){
        isException = true;
        QCOMPARE(pe.pos(), -1 );
    }
    QTRUE(isException);
}

void BuforTest::dekrementacjaException_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("") << "";
}

void BuforTest::moveByException()
{
    CREATE_BUFOR(stream);
    bool isException = false;
    try{
        stream.moveBy(10);
    } catch (SourceBuforOutOfBoundsException pe){
        isException = true;
        QCOMPARE(pe.pos(), 10 );
    }
    QTRUE(isException);
}

void BuforTest::moveByException_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("Pusty") << "";
    QTest::newRow("Nie pusty") << "dsfsd";
}

void BuforTest::setPos()
{
    CREATE_BUFOR(stream);
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
    CREATE_BUFOR(stream);
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

void BuforTest::isEnd()
{
    CREATE_BUFOR(stream);
    QFETCH(int, przesuniecie);
    QFETCH(bool, startResult);
    QFETCH(bool, endResult);

    QCOMPARE(stream.isEnd(), startResult);
    stream.moveBy(przesuniecie);
    QCOMPARE(stream.isEnd(), endResult);

}

void BuforTest::isEnd_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<int>("przesuniecie");
    QTest::addColumn<bool>("startResult");
    QTest::addColumn<bool>("endResult");

    QTest::newRow("") << "" << 0 << true << true ;
    QTest::newRow("1") << "1" << 1 << false << true ;
    QTest::newRow("12") << "12" << 1 << false << false ;

}

QTEST_APPLESS_MAIN(BuforTest)

#include "tst_bufortest.moc"
