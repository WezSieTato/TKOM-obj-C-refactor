#include <QString>
#include <QtTest>

#include "../../Refactorer/Parser/parser.h"
#include "../macrostest.h"

using namespace objc;

#define FILE_FETCH( file, bufor, data ) QFETCH(QString, data); \
    SourceBufor bufor(data.toStdString()); \
    File file; \
    { \
    Parser par(&bufor); \
    par >> file; \
    }


class InserterTestTest : public QObject
{
    Q_OBJECT

public:
    InserterTestTest();

private Q_SLOTS:
    void insertMethodTest();
    void insertMethodTest_data();

};

InserterTestTest::InserterTestTest()
{
}

void InserterTestTest::insertMethodTest()
{
    FILE_FETCH(fileIntr, buforIntr, dataInt);
    FILE_FETCH(fileImpl, buforImpl, dataImpl);

    COMPARE_STRING(fileIntr.getClassNameAtPosition(390),"DeviceForMapA");


}

void InserterTestTest::insertMethodTest_data()
{
    QTest::addColumn<QString>("dataInt");
    QTest::addColumn<QString>("dataImpl");
    QTest::addColumn<int>("pos");


    QTest::newRow("") << INTERFACE_FILE << IMPLEMENTATION_FILE << 70 ;
}


QTEST_APPLESS_MAIN(InserterTestTest)

#include "tst_insertertesttest.moc"
