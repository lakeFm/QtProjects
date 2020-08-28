#include "include/hexcoder.h"

HexCoder::HexCoder(){}

QString HexCoder::decode(QString data){
    stringstream out;
    for(int a = 0; a < data.size(); a += 2){
        u_int x = static_cast<u_int>(data[a].unicode()) % 16;
        u_int y = static_cast<u_int>(data[a+1].unicode())% 16;

        char num = static_cast<char>((x * 16) + y);

        out << num;
    }

    return QString(out.str().c_str());
}

QString HexCoder::encode(QString data){
    stringstream out;
    for(int a = 0; a < data.size(); a++){
        u_int i = (u_int)data[a].unicode();
        out << hex << i;
    }
    return QString(out.str().c_str());
}
