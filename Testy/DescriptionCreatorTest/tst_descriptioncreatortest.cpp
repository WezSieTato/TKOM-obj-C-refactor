#include <QString>
#include <QtTest>

#include "../../Refactorer/Inserter/descriptioncreator.h"
#include "../macrostest.h"

using namespace objc;

class DescriptionCreatorTest : public QObject
{
    Q_OBJECT

public:
    DescriptionCreatorTest();

private Q_SLOTS:
    void variableType();
    void headerPart();

};

DescriptionCreatorTest::DescriptionCreatorTest()
{
}

void DescriptionCreatorTest::variableType()
{
    std::string str("NSData**");
    VariableType type;
    type.setName(str);
    DescriptionCreator des;
    COMPARE_STRING(des(type), str.c_str());
}

void DescriptionCreatorTest::headerPart()
{
    MethodHeaderPart part;
    part.setName("liczProcent");
    DescriptionCreator des;
    COMPARE_STRING(des(part), "liczProcent");

    VariableDeclaration varDec;
    VariableType type;
    type.setName("float");
    varDec.setType(type);
    varDec.setObjectName("procent");
    part.setVariable(varDec);
    COMPARE_STRING(des(part), "liczProcent:(float)procent");

}

QTEST_APPLESS_MAIN(DescriptionCreatorTest)

#include "tst_descriptioncreatortest.moc"
