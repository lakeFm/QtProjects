#ifndef BINARYCODER_H
#define BINARYCODER_H

#include "coder.h"

class BinaryCoder : Coder{

public:
    BinaryCoder();

    QString decode(QString data);

    QString encode(QString data);

};

#endif // BINARYCODER_H
