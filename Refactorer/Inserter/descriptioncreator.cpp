#include "descriptioncreator.h"

DescriptionCreator::DescriptionCreator()
{
}

string DescriptionCreator::operator ()(const objc::VariableType &type)
{
    return type.name();
}

string DescriptionCreator::operator ()(const objc::MethodHeaderPart &headerPart)
{
    std::string description(headerPart.name());
    if(headerPart.isParameter()){
        description += ":(";
        description += (*this)(headerPart.variable().type());
        description += ")";
        description += headerPart.variable().objectName();
    }

    return description;
}

string DescriptionCreator::operator ()(const objc::MethodHeader &header)
{
    std::string description;
    if(header.isStatic())
        description += '+';
    else
        description += '-';

    description += '(';
    description += (*this)(header.type());
    description += ')';

    for(const objc::MethodHeaderPart &part : header.partsHeaderList()){
        description += (*this)(part);
        description += ' ';
    }

    return description;
}

string DescriptionCreator::operator ()(const objc::MethodDefinition &definition)
{
    std::string description;

    description += (*this)(definition.header());
    description += "\n{";
    description += definition.body();
    description += "}\n";

    return description;
}
