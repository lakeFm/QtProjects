#include "decimalcoder.h"

DecimalCoder::DecimalCoder(){}

QString DecimalCoder::decode(QString data){
    string out;
    for(int a = 0; a < data.size(); a += 3){
        u_int x = static_cast<u_int>(data[a].unicode()) % '0';
        u_int y = static_cast<u_int>(data[a+1].unicode())% '0';
        u_int z = static_cast<u_int>(data[a+2].unicode())% '0';

        char num = static_cast<char>((x * 100) + (y * 10) + z);

        out += num;
    }

    return QString(out.c_str());
}

QString DecimalCoder::encode(QString data){
    string out;
    for(int a = 0; a < data.size(); a++){
        u_int i = (u_int)data[a].unicode();

        if(i < 10)
            out += "00" + to_string(i);
        else if(i >= 10 && i < 100)
            out += "0" + to_string(i);
        else
            out += to_string(i);
    }
    return QString(out.c_str());
}
