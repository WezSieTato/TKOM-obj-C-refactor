#include "inserter.h"
#include "descriptioncreator.h"

Inserter::Inserter(SourceBufor *bufor, objc::File *file) :
    _bufor(bufor),
    _file(file)
{

}

Inserter &Inserter::operator <<(objc::MethodDefinition &definition)
{
    DescriptionCreator creator;
    std::string des;
    des = creator(definition);

    unsigned delta = des.length();
//    ++delta;

    objc::ClassImplementation classImpl = _file->getClassImplementation(currentClass());

    unsigned pos = classImpl.addDefinition(definition, delta);
    _bufor->setPos(pos);


    _bufor->put(des);
    _bufor->put('\n');

    return *this;
}

Inserter &Inserter::operator <<(objc::PropertyDeclaration &propertyDeclaration)
{
        DescriptionCreator creator;
        std::string des;
        des = creator(propertyDeclaration);

        unsigned delta = des.length();

        objc::ClassInterface classIntr = _file->getClassInterface(currentClass());

        unsigned pos = classIntr.addPropertyDeclaration(propertyDeclaration, delta);
        _bufor->setPos(pos - 1);
        if(_bufor->getChar() != '\n'){
            ++(*_bufor);
            _bufor->put('\n');
            propertyDeclaration.setStartPos(pos + 1);
            propertyDeclaration.setEndPos( propertyDeclaration.endPos() + 1);
        } else {
            ++(*_bufor);
        }

        _bufor->put(des);
        _bufor->put('\n');

        return *this;
}

Inserter &Inserter::operator <<(objc::SynthesizeBlock &block)
{
    DescriptionCreator creator;
    std::string des;
    des = creator(block);

    unsigned pos = _file->getClassImplementation(currentClass()).putSynthesizedBlock(block, des.length());

    _bufor->setPos(pos);
    _bufor->put(des);
    _bufor->put('\n');

    return *this;
}

Inserter &Inserter::operator <<(objc::SynthesizedVariable &synthesizedVariable)
{
    DescriptionCreator creator;
    std::string des;
    des = creator(synthesizedVariable);

    unsigned pos = _file->getClassImplementation(currentClass()).addSynthesizedVariable(synthesizedVariable, des.length());

    _bufor->setPos(pos);
    _bufor->put(des);
    _bufor->put(",\n ");

    return *this;
}
std::string Inserter::currentClass() const
{
    return _currentClass;
}

void Inserter::setCurrentClass(const std::string &currentClass)
{
    _currentClass = currentClass;
}

