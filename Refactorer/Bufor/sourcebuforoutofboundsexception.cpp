#include "sourcebuforoutofboundsexception.h"

SourceBuforOutOfBoundsException::SourceBuforOutOfBoundsException(SourceBufor *bufor, int pos) :
    SourceBuforException(bufor, "Proba dostania sie poza granice bufora!"),
    _pos(pos)
{
    _description += "Proba dostania sie do pozycji: " + std::to_string(pos);
}
int SourceBuforOutOfBoundsException::pos() const
{
    return _pos;
}

