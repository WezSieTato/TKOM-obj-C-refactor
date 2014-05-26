#include "classimplementation.h"

using namespace objc;

ClassImplementation::ClassImplementation()
{
}

SynthesizeBlock ClassImplementation::synthesizeBlock() const
{
    return _synthesizeBlock;
}

void ClassImplementation::setSynthesizeBlock(const SynthesizeBlock &synthesizeBlock)
{
    _synthesizeBlock = synthesizeBlock;
}

MethodDefinitionList ClassImplementation::methodDefinitions() const
{
    return _methodDefinitions;
}

void ClassImplementation::setMethodDefinitions(const MethodDefinitionList &methodDefinitions)
{
    _methodDefinitions = methodDefinitions;
}

unsigned ClassImplementation::addDefinition(MethodDefinition &definition, unsigned size)
{
    unsigned startPos;

    startPos = endPos() - 4;

    definition.setStartPos(startPos);
    definition.setEndPos(startPos + size);
    _methodDefinitions.push_back(definition);

    return startPos;
}

bool ClassImplementation::isDefinition(const MethodHeader &header) const
{
    for(const MethodDefinition &def : _methodDefinitions){
        if(def.header() == header)
            return true;
    }

    return false;
}
