#ifndef DESCRIPTIONCREATOR_H
#define DESCRIPTIONCREATOR_H

#include "inserter.h"

class DescriptionCreator
{
public:
    DescriptionCreator();

    std::string operator () (const objc::VariableType &type);
    std::string operator () (const objc::MethodHeaderPart &headerPart);
    std::string operator () (const objc::MethodHeader &header);
    std::string operator () (const objc::MethodDefinition &definition);
};

#endif // DESCRIPTIONCREATOR_H
