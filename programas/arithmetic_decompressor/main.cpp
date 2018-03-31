//
// Created by francisco on 31/03/18.
//

#include "utils/DataFrequency.h"
#include "utils/MessageHeader.h"
#include "ArithmeticDecoder.h"
#include <fstream>

int main(int argc, char ** argv){
    if(argc < 3) {
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream of(argv[2]);
    utils::DataFrequency freq;
    utils::MessageHeader header;
    inputFile >> freq >> header;
    arithmetic_decompressor::ArithmeticDecoder decoder;
    decoder.decodeFromStreamToOutputStream(inputFile,of,freq,header);
    return 0;
}
