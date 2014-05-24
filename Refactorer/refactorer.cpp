#include "refactorer.h"

using namespace objc;

Refactorer::Refactorer() :
_interfaceBufor(nullptr),
  _implementationBufor(nullptr)
{
}


void Refactorer::setUp(string &interface, string &implementation)
{
    _interfaceBufor = new SourceBufor(interface);
    _implementationBufor= new SourceBufor(implementation);

    {
        Parser par(_interfaceBufor);
        par >> _interfaceFile;
    }

    {
        Parser par(_implementationBufor);
        par >> _implementationFile;
    }

}

void Refactorer::cleanUp()
{
    delete _interfaceBufor;
    _interfaceBufor = nullptr;
    delete _implementationBufor;
    _implementationBufor = nullptr;
}


