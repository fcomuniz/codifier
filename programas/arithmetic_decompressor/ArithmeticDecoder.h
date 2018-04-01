//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_ARITHMETICDECODER_H
#define MY_LIB_ARITHMETICDECODER_H

#include <iostream>
#include <sstream>
#include <programas/utils/FileWriter.h>
#include "utils/DataFrequency.h"
#include "utils/MessageHeader.h"
#include "utils/FileWriter.h"

namespace arithmetic_decompressor{
class ArithmeticDecoder {
public:
    void decodeFromStream(std::istream & is, const utils::DataFrequency & freq, const utils::MessageHeader & messageSize);
    void decodeFromStreamToOutputStream(std::istream & is, std::ostream & os, const utils::DataFrequency & freq, const utils::MessageHeader & messageSize);
    std::string getDecodedMessage();

private:
    std::stringstream decodedMessage;
    long long readBits(std::istream & is, long long n);
    void initializeValues(const utils::MessageHeader & messageSize);
    void updateLimits(utils::byte x, const utils::DataFrequency & freq);
    bool readFromBuffer(std::istream & is);
    bool haveSameMSB();
    bool getMSB(unsigned long long v);
    bool hasE3Cond();

    void complementMSB(unsigned long long & i);
    void limitValue(unsigned long long & i);
    void shiftL(bool withComplement);
    void shiftU(bool withComplement);
    void shiftT(std::istream & is, bool withComplement);
    unsigned long long m, l, u, t;
    long long msb;
    long long currentNumber;
    utils::byte buffer;
    bool canRead;
    long long bufferBitsRead;
    utils::FileWriter writer;
};
}



#endif //MY_LIB_ARITHMETICDECODER_H
