#ifndef SYNTHETIZEDVARIABLE_H
#define SYNTHETIZEDVARIABLE_H

#include "codeobject.h"

namespace objc {

class SynthesizedVariable : public CodeObject
{
public:
    SynthesizedVariable();

    std::string propertyName() const;
    void setPropertyName(const std::string &propertyName);

    std::string variableName() const;
    void setVariableName(const std::string &variableName);

private:
    std::string _propertyName;
    std::string _variableName;
};

}
#endif // SYNTHETIZEDVARIABLE_H
