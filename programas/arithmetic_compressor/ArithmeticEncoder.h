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
#include <programas/utils/FileWriter.h>

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
    bool haveSameMSB(long long l, long long u);
    bool hasE3Condition(long long l, long long u);
    bool getMostSignificantBit(long long v);
    void shiftU(bool withFlip);
    void shiftL(bool withFlip);
    std::stringstream encodedMessage;
    utils::MessageHeader messageSize;
    utils::FileWriter writer;
    utils::byte buffer;
    long long bufferSize;
    long long l, u, m;
    long long msb;

};
}



#endif //MY_LIB_ARITHMETICENCODER_H
