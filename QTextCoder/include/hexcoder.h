#ifndef HEXCODER_H
#define HEXCODER_H

#include "coder.h"

class HexCoder : Coder{
public:
    HexCoder();

    // Coder interface
public:
    QString decode(QString data);
    QString encode(QString data);
};

#endif // HEXCODER_H
