#include "propertyrefactorer.h"

PropertyRefactorer::PropertyRefactorer()
{
}

bool PropertyRefactorer::operator ()(string &interface, string &implementation, unsigned startPos, unsigned endPos)
{
    setUp(interface, implementation);

    bool success = false;
    std::string className = _interfaceFile.getClassNameAtPosition(startPos, endPos);

    if(className.length()) {
        objc::VariableDeclarationList list = _interfaceFile.getVariableDeclarationsAtPosition(startPos, endPos);
        if(!list.size()){

        } else {
            Inserter interfaceInserter(_interfaceBufor, &_interfaceFile);
            interfaceInserter.setCurrentClass(className);

            Inserter implementInserter(_implementationBufor,&_implementationFile);
            implementInserter.setCurrentClass(className);
            list.reverse();

            for(objc::VariableDeclaration declaration : list){


                if(_interfaceFile.getClassInterface(className).isProperty(declaration)
                        || _implementationFile.getClassImplementation(className).isSynthesizedVariable(declaration))
                    continue;

                objc::PropertyDeclaration propDec;
                objc::VariableDeclaration varDec = declaration;
                stringList attributes = {"nonatomic", "readonly"};
                if(varDec.type().isPointer())
                    attributes.push_back("strong");

                propDec.setAttributes(attributes);
                std::string name = varDec.objectName();
                name.erase(0, 1);
                varDec.setObjectName(name);
                propDec.setVariableDeclaration(varDec);

                interfaceInserter << propDec;

                objc::SynthesizedVariable synVar;
                synVar.setPropertyName(name);
                synVar.setVariableName(declaration.objectName());
                if(!_implementationFile.getClassImplementation(className).isSynthetizeBlock()){
                    objc::SynthesizeBlock block;
                    objc::SynthesizeList list;
                    list.push_back(synVar);
                    block.setPropertyList(list);

                    implementInserter << block;
                } else {
                    implementInserter << synVar;
                }


                success = true;
            }
            interface = _interfaceBufor->bufor();
            implementation = _implementationBufor->bufor();
        }
    }



    cleanUp();
    return success;
}
