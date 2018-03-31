//
// Created by francisco on 31/03/18.
//


#include <gtest/gtest.h>
#include "arithmetic_decompressor/ArithmeticDecoder.h"
#include "arithmetic_compressor/ArithmeticEncoder.h"
#include "ArithmeticCompressorDataGenerator.h"

TEST(ArithmeticDecoder, decodingTest){
    auto freqV = getExampleFrequency();
    utils::DataFrequency freq;
    utils::MessageHeader messageSize;
    freq.setFrequencyVector(freqV);
    messageSize.calculateMessageSize(freq);
    arithmetic_compressor::ArithmeticEncoder encoder;
    std::string stringToDecompress = "1321111123";
    messageSize.setMessageSize(stringToDecompress.size());
    std::stringstream sequence (stringToDecompress);
    encoder.encode(sequence,freq);
    std::stringstream inputForDecoder(encoder.getEncodedMessage());
    arithmetic_decompressor::ArithmeticDecoder decoder;
    decoder.decodeFromStream(inputForDecoder, freq, messageSize);
    ASSERT_EQ(stringToDecompress, decoder.getDecodedMessage());
}