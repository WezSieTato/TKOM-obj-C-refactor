#include "synthesizeblock.h"

using namespace objc;

SynthesizeBlock::SynthesizeBlock()
{
}

SynthesizeList SynthesizeBlock::propertyList() const
{
    return _propertyList;
}

void SynthesizeBlock::setPropertyList(const SynthesizeList &propertyList)
{
    _propertyList = propertyList;
}
