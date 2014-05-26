#ifndef CLASSIMPLEMENTATION_H
#define CLASSIMPLEMENTATION_H

#include "classpart.h"
#include "synthesizeblock.h"
#include "methoddefinition.h"

namespace objc {

typedef std::list< MethodDefinition > MethodDefinitionList;

class ClassImplementation : public ClassPart
{
public:
    ClassImplementation();

    SynthesizeBlock synthesizeBlock() const;
    void setSynthesizeBlock(const SynthesizeBlock &synthesizeBlock);

    MethodDefinitionList methodDefinitions() const;
    void setMethodDefinitions(const MethodDefinitionList &methodDefinitions);

    unsigned addDefinition(MethodDefinition& definition, unsigned size);
    unsigned putSynthesizedBlock(SynthesizeBlock& block, unsigned size);
    unsigned addSynthesizedVariable(SynthesizedVariable& synthesizedVariable, unsigned size);

    bool isDefinition(const MethodHeader& header) const;
    bool isSynthesizedVariable(const VariableDeclaration& variable) const;
    bool isSynthetizeBlock() const;

private:
    SynthesizeBlock _synthesizeBlock;
    MethodDefinitionList _methodDefinitions;
};

}

#endif // CLASSIMPLEMENTATION_H
