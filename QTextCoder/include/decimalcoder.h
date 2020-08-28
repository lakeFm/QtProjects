#ifndef DECIMALCODER_H
#define DECIMALCODER_H

#include "coder.h"

class DecimalCoder : Coder{
public:
    DecimalCoder();

    QString decode(QString data);
    QString encode(QString data);

};

#endif // DECIMALCODER_H
