//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_ARITHMETICDECODER_H
#define MY_LIB_ARITHMETICDECODER_H

#include <iostream>
#include <sstream>
#include "utils/DataFrequency.h"
#include "utils/MessageHeader.h"

namespace arithmetic_decompressor{
class ArithmeticDecoder {
public:
    void decodeFromStream(std::istream & is, const utils::DataFrequency & freq, const utils::MessageHeader & messageSize);
    void decodeFromStreamToOutputStream(std::istream & is, std::ostream & os, const utils::DataFrequency & freq, const utils::MessageHeader & messageSize);
    std::string getDecodedMessage();

private:
    std::stringstream decodedMessage;
    int readBits(std::istream & is, int n);
    void initializeValues(const utils::MessageHeader & messageSize);
    void updateLimits(utils::byte x, const utils::DataFrequency & freq);
    bool readFromBuffer(std::istream & is);
    bool haveSameMSB();
    bool getMSB(int v);
    bool hasE3Cond();

    void complementMSB(int & i);
    void shiftL(bool withComplement);
    void shiftU(bool withComplement);
    void shiftT(std::istream & is, bool withComplement);
    int m, l, u, t;
    int msb;
    int currentNumber;
    utils::byte buffer;
    bool canRead;
    int bufferBitsRead;
};
}



#endif //MY_LIB_ARITHMETICDECODER_H
