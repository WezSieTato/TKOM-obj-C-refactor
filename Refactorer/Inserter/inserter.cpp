#include "inserter.h"
#include "descriptioncreator.h"

Inserter::Inserter(SourceBufor *bufor, objc::File file) :
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
    ++delta;

    for(objc::ClassImplementation impl : _file.classImplementations()){
        if(impl.className() == currentClass()){
            unsigned pos = impl.addDefinition(definition, delta);
            _bufor->setPos(pos);
        }
    }

    _bufor->put(des);
    _bufor->put('\n');

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

