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
            Inserter ins(_implementationBufor, _implementationFile);
            ins.setCurrentClass(className);

            list.reverse();
            for(objc::VariableDeclaration declaration : list){


                success = true;
            }
        }
    }



    cleanUp();
    return success;
}
