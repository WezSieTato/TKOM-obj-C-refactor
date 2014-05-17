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
