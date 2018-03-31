//
// Created by francisco on 31/03/18.
//

#include <gtest/gtest.h>
#include <bitset>
#include "arithmetic_compressor/ArithmeticEncoder.h"
#include "utils/DataFrequency.h"
using namespace arithmetic_compressor;


TEST(ArithmeticEncoder, simpleSequence){
    utils::DataFrequency freq;
    std::vector<unsigned int> freqVec(utils::SIZE_OF_BYTES,0);
    std::string toEncode("1333435");
    for(auto & c : toEncode){
        freqVec[(unsigned char)c]++;
    }
    freq.setFrequencyVector(freqVec);
    ArithmeticEncoder encoder;
    std::stringstream ss(toEncode);
    //11001010 00000000
    encoder.encode(ss,freq);
    std::bitset<8*sizeof(utils::byte)> b;
    ss.clear();
    ss.str(encoder.getEncodedMessage());
    for(auto currentByte : encoder.getEncodedMessage()){
        b = std::bitset<8*sizeof(utils::byte)>(currentByte);
        std::cout << b << " ";
    }
    std::cout << std::endl;
}


