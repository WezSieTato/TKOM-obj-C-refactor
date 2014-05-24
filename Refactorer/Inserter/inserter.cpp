#include "inserter.h"
#include "descriptioncreator.h"

Inserter::Inserter(SourceBufor *bufor, objc::File file) :
    _bufor(bufor),
    _file(file)
{

}

Inserter &Inserter::operator <<(objc::MethodDefinition &definition)
{

}
