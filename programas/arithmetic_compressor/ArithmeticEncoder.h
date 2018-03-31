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
    ArithmeticEncoder();
    void encode(std::istream & is, const utils::DataFrequency & freq);
    void encodeAndSend(std::istream & is, std::ostream & os, const utils::DataFrequency & freq);
    std::string getEncodedMessage();
private:
    void initilizeValues(const utils::DataFrequency & freq);
    void sendInBuffer(std::ostream & os, bool bit);
    void sendIncompleteBuffer(std::ostream & os);
    std::stringstream encodedMessage;
    utils::MessageSize messageSize;
    utils::byte buffer;
    int bufferSize;
    int l, u, m;

};
}



#endif //MY_LIB_ARITHMETICENCODER_H
