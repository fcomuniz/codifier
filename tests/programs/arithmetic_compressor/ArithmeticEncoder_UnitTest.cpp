//
// Created by francisco on 31/03/18.
//

#include <gtest/gtest.h>
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
    std::stringstream ss("1321");
    encoder.encodeAndSend(ss,std::cout,freq);
}


