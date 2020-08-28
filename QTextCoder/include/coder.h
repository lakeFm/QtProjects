#ifndef CODER_H
#define CODER_H

#include <QObject>
#include <QMap>
#include <QString>
#include <bitset>

#include <string>
#include <sstream>
#include <iostream>
#define null nullptr
using namespace std;

class Coder{

public:
    virtual QString decode(QString data)=0;
    virtual QString encode(QString data)=0;
    virtual ~Coder(){}
};

#endif // CODER_H
