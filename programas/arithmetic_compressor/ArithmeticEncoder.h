//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_ARITHMETICENCODER_H
#define MY_LIB_ARITHMETICENCODER_H

#include <iostream>
#include <utils/DataTypes.h>
#include "utils/DataFrequency.h"
#include "utils/MessageSize.h"
#include <sstream>
#include <vector>

namespace arithmetic_compressor{
class ArithmeticEncoder {
public:
    void encode(std::istream & is);
    void encodeAndSend(std::istream & is, std::ostream & os);
    std::string getEncodedMessage();
private:
    void initilizeValues();
    std::stringstream encodedMessage;
    utils::DataFrequency freq;
    utils::MessageSize messageSize;
    int l, u, m;

};
}



#endif //MY_LIB_ARITHMETICENCODER_H
