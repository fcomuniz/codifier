//
// Created by francisco on 31/03/18.
//

#include <gtest/gtest.h>
#include "arithmetic_compressor/ArithmeticEncoder.h"
using namespace arithmetic_compressor;


TEST(ArithmeticEncoder, simpleSequence){
    ArithmeticEncoder encoder;
    std::stringstream ss("1321");
    encoder.encode(ss);
    std::cout << encoder.getEncodedMessage() << std::endl;
}


