#include "methodrefactorer.h"



using namespace objc;

MethodRefactorer::MethodRefactorer()
{
}

bool MethodRefactorer::operator ()(std::string &interface, std::string &implementation, unsigned startPos, unsigned endPos)
{
    setUp(interface, implementation);
    bool success = true;
    std::string className = _interfaceFile.getClassNameAtPosition(startPos, endPos);

    if(!className.length()){
        success = false;
    } else {
        MethodDeclarationList list = _interfaceFile.getMethodDeclarationsAtPosition(startPos, endPos);
        if(!list.size()){
            success = false;
        } else {
            for(MethodDeclaration& declaration : list){
                MethodDefinition definition;
                definition.setHeader(declaration.header());
                createBody(definition);
            }
        }
    }

    cleanUp();
    return success;
}

void MethodRefactorer::createBody(MethodDefinition &definition)
{
    std::string body;
    std::string type = definition.header().type().name();
    body.append("\n");
    if(type != "void") {
        body.append("return ");
    } else {
        if(type == "bool" || type == "BOOL")
            body.append("false");
        else if(type == "int")
            body.append("0");
        else if (type == "float")
            body.append("0.0f");
        else if (type == "double")
            body.append("0.0");
        else
            body.append("nil");
        body.append(";\n");
    }
    definition.setBody(body);
}
