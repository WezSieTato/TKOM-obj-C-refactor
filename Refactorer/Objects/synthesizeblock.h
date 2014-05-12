#ifndef SYNTHETIZEBLOCK_H
#define SYNTHETIZEBLOCK_H

#include "synthesizedvariable.h"

namespace  objc{

typedef std::list< SynthesizedVariable > SynthesizeList;

class SynthesizeBlock : public CodeObject
{
public:
    SynthesizeBlock();

    SynthesizeList propertyList() const;
    void setPropertyList(const SynthesizeList &propertyList);

private:
    SynthesizeList _propertyList;
};

}
#endif // SYNTHETIZEBLOCK_H
