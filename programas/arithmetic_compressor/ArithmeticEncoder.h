//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_ARITHMETICENCODER_H
#define MY_LIB_ARITHMETICENCODER_H

#include <iostream>
#include <utils/DataTypes.h>
#include "utils/DataFrequency.h"
#include "utils/MessageHeader.h"
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
    void updateLimits(utils::byte currentByte, const utils::DataFrequency & freq);
    bool haveSameMSB(int l, int u);
    bool hasE3Condition(int l, int u);
    bool getMostSignificantBit(int v);
    void shiftU(bool withFlip);
    void shiftL(bool withFlip);
    std::stringstream encodedMessage;
    utils::MessageHeader messageSize;
    utils::byte buffer;
    int bufferSize;
    int l, u, m;
    int msb;

};
}



#endif //MY_LIB_ARITHMETICENCODER_H
