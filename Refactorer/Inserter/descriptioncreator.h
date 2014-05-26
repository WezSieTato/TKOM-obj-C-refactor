#ifndef DESCRIPTIONCREATOR_H
#define DESCRIPTIONCREATOR_H

#include "inserter.h"

class DescriptionCreator
{
public:
    DescriptionCreator();

    std::string operator () (const objc::VariableType &type);
    std::string operator () (const objc::VariableDeclaration &varDec);
    std::string operator () (const objc::MethodHeaderPart &headerPart);
    std::string operator () (const objc::MethodHeader &header);
    std::string operator () (const objc::MethodDefinition &definition);
    std::string operator () (const objc::PropertyDeclaration &propertyDeclaration);
    std::string operator () (const objc::SynthesizeBlock &synthesizeBlock);
    std::string operator () (const objc::SynthesizedVariable &synthesizedVariable);

};

#endif // DESCRIPTIONCREATOR_H
