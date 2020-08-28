#include "include/binarycoder.h"


BinaryCoder::BinaryCoder(){}

QString BinaryCoder::decode(QString data){
    std::string std_data = data.toStdString();
    std::stringstream ss(std_data);
    std::string output;
    while(ss.good())
    {
        std::bitset<8> bits;
        ss >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }
    QString out(output.c_str());
    return out;
}


QString BinaryCoder::encode(QString data){
    stringstream ss;
    string stdStr = data.toStdString();
    for(int a = 0; a < data.size(); a++){
        ss << bitset<8>(stdStr[a]);
    }
    QString encoded(ss.str().c_str());
    return encoded;
}

