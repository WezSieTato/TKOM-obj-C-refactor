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

unsigned ClassImplementation::putSynthesizedBlock(SynthesizeBlock &block, unsigned size)
{
    unsigned startPos;

    if(_methodDefinitions.size()){
       startPos = _methodDefinitions.front().startPos();
    } else {
        startPos = endPos() - 4;
    }

    block.setStartPos(startPos);
    block.setEndPos(startPos + size);
    SynthesizeList list = block.propertyList();
    list.front().setStartPos(startPos + 12);
    list.front().setEndPos(block.endPos() - 1);
    block.setPropertyList(list);

    setSynthesizeBlock(block);

    return startPos;
}

unsigned ClassImplementation::addSynthesizedVariable(SynthesizedVariable &synthesizedVariable, unsigned size)
{
    unsigned startPos;

    startPos = _synthesizeBlock.propertyList().front().startPos();
//    startPos += 3;

    synthesizedVariable.setStartPos(startPos);
    synthesizedVariable.setEndPos(startPos + size);

    _synthesizeBlock.propertyList().push_front(synthesizedVariable);

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

bool ClassImplementation::isSynthesizedVariable(const VariableDeclaration &variable) const
{
    for(const SynthesizedVariable &synVariable : _synthesizeBlock.propertyList()){
        if(synVariable.propertyName() == variable.objectName())
                return true;
    }
    return false;
}

bool ClassImplementation::isSynthetizeBlock() const
{
    return _synthesizeBlock.propertyList().size();
}
