//
// Created by francisco on 31/03/18.
//


#include <gtest/gtest.h>
#include <bitset>
#include "arithmetic_decompressor/ArithmeticDecoder.h"
#include "arithmetic_compressor/ArithmeticEncoder.h"
#include "ArithmeticCompressorDataGenerator.h"

TEST(ArithmeticDecoder, decodingTest){
    std::string stringToDecompress = "1223334444";
    std::stringstream ss(stringToDecompress);
    std::vector<unsigned int> freqV(utils::SIZE_OF_BYTES,0);
    for(auto c : stringToDecompress){
        freqV[c]++;
    }
    utils::DataFrequency freq;
    utils::MessageHeader messageSize;
    freq.setFrequencyVector(freqV);
    messageSize.calculateMessageSize(freq);
    ASSERT_EQ(messageSize.getMessageSize(),stringToDecompress.size());
    arithmetic_compressor::ArithmeticEncoder encoder;
    std::stringstream sequence (stringToDecompress);
    encoder.encode(sequence,freq);
    for(auto & b : encoder.getEncodedMessage()){
        std::cout << std::bitset<8>(b) << " ";
    }
    std::cout << std::endl;
    std::stringstream inputForDecoder(encoder.getEncodedMessage());
    arithmetic_decompressor::ArithmeticDecoder decoder;
    decoder.decodeFromStream(inputForDecoder, freq, messageSize);
    ASSERT_EQ(stringToDecompress, decoder.getDecodedMessage());
}