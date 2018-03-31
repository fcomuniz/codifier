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
    freqVec['1']=40;
    freqVec['2'] = 1;
    freqVec['3'] = 9;
    freq.setFrequencyVector(freqVec);
    ArithmeticEncoder encoder;
    std::stringstream ss("1223334444");
    freq.setFrequencyVector(ss);
    ss.clear();
    ss.seekg(0,std::ios_base::beg);
    encoder.encode(ss,freq);
    std::bitset<8*sizeof(utils::byte)> b;
    ss.clear();
    ss.str(encoder.getEncodedMessage());
    std::cout << ss.str()<< std::endl;
    utils::byte currentByte;
    while(ss >> currentByte){
        b = std::bitset<8*sizeof(utils::byte)>(currentByte);
        std::cout << b;
    }
    std::cout << std::endl;
}


