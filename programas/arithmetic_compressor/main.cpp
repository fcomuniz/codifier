//
// Created by francisco on 31/03/18.
//
#include <fstream>
#include "ArithmeticEncoder.h"
using arithmetic_compressor::ArithmeticEncoder;

int main(int argc, char ** argv){
    if(argc < 3){
        return 1;
    }
    std::ifstream f(argv[1]);
    std::ofstream of(argv[2]);
    utils::DataFrequency freq;
    freq.setFrequencyVector(f);
    utils::MessageHeader header;
    header.calculateMessageSize(freq);
    of << freq << header;
    f.clear();
    f.seekg(0,std::ios_base::beg);
    ArithmeticEncoder encoder;
    encoder.encodeAndSend(f,of,freq);
    return 0;
}
