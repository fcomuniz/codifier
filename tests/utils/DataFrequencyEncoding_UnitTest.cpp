//
// Created by francisco on 31/03/18.
//

#include <gtest/gtest.h>
#include "utils/DataFrequency.h"
TEST(DataFrequencyEnconding, simpleEncoding){
    std::vector<unsigned int> bytes(utils::SIZE_OF_BYTES,0);
    bytes['1'] = 40;
    bytes['2'] = 1;
    bytes['3'] = 9;
    utils::DataFrequency freq;
    freq.setFrequencyVector(bytes);
    std::cout << freq << std::endl;

}
TEST(DataFrequencyEncoding, simpleDecoding){
    std::vector<unsigned int> bytes(utils::SIZE_OF_BYTES,0);
    bytes['1'] = 40;
    bytes['2'] = 1;
    bytes['3'] = 9;
    utils::DataFrequency freq;
    freq.setFrequencyVector(bytes);
    std::stringstream ss;
    ss << freq;
    utils::DataFrequency freq2;
    ss >> freq2;
    ASSERT_EQ(freq,freq2);

}
