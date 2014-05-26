#include "descriptioncreator.h"

DescriptionCreator::DescriptionCreator()
{
}

string DescriptionCreator::operator ()(const objc::VariableType &type)
{
    return type.name();
}

string DescriptionCreator::operator ()(const objc::VariableDeclaration &varDec)
{
    std::string description((*this)(varDec.type()));
    description += " ";
    description += varDec.objectName();

    return description;
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
    description += "}";

    return description;
}

string DescriptionCreator::operator ()(const objc::PropertyDeclaration &propertyDeclaration)
{
    std::string description("@property ");

    if(propertyDeclaration.attributes().size()){
        description += "(";
        for(const string str : propertyDeclaration.attributes()){
            description += " ";
            description += str;
            description += ",";
        }
        description.erase(--description.end());
        description += " ) ";
    }

    description += (*this)(propertyDeclaration.variableDeclaration());
    description += ";";

    return description;
}

string DescriptionCreator::operator ()(const objc::SynthesizeBlock &synthesizeBlock)
{
    std::string description("@synthesize");
    for(const objc::SynthesizedVariable &synVar : synthesizeBlock.propertyList()){
        description += ' ';
        description += (*this)(synVar);
        description += ',';
    }
    description.erase(description.end() - 1);
    description += ';';

    return description;
}

string DescriptionCreator::operator ()(const objc::SynthesizedVariable &synthesizedVariable)
{
    std::string description;

    description += synthesizedVariable.propertyName();
    description += ' ';
    if(synthesizedVariable.propertyName() != synthesizedVariable.variableName()){
        description += "= ";
        description += synthesizedVariable.variableName();
    }

    return description;
}
