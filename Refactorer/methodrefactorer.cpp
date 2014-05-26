#include "methodrefactorer.h"

using namespace objc;

MethodRefactorer::MethodRefactorer()
{
}

bool MethodRefactorer::operator ()(std::string &interface, std::string &implementation, unsigned startPos, unsigned endPos)
{
    setUp(interface, implementation);
    bool success = false;
    std::string className = _interfaceFile.getClassNameAtPosition(startPos, endPos);

    if(className.length()) {
        MethodDeclarationList list = _interfaceFile.getMethodDeclarationsAtPosition(startPos, endPos);
        if(!list.size()){

        } else {
            Inserter ins(_implementationBufor, _implementationFile);
            ins.setCurrentClass(className);

            list.reverse();
            for(MethodDeclaration& declaration : list){
                if(_implementationFile.getClassImplementation(className).isDefinition(declaration.header())){
                  continue;
                }

                MethodDefinition definition;
                definition.setHeader(declaration.header());
                createBody(definition);
                ins << definition;

                success = true;
            }
        }
    }

    implementation = _implementationBufor->bufor();
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
