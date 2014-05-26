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
    _bufor->put(des);
}
