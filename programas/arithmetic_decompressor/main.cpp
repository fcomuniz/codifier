//
// Created by francisco on 31/03/18.
//

#include "utils/DataFrequency.h"
#include "utils/MessageHeader.h"
#include "ArithmeticDecoder.h"
#include <fstream>
#include <bitset>

int main(int argc, char ** argv){
    if(argc < 3) {
        return 1;
    }

    std::ifstream inputFile(argv[1], std::ios_base::binary);
    std::ofstream of(argv[2],std::ios_base::binary);
    utils::DataFrequency freq;
    utils::MessageHeader header;
    inputFile >> freq >> header;
    auto pos = inputFile.tellg();
    //00000010 11101110 11010010
   // while(!inputFile.eof()){
   //     std::cout << std::bitset<8>(b) << " ";
  //      b = inputFile.get();
 //   }
//    inputFile.seekg(pos);
    arithmetic_decompressor::ArithmeticDecoder decoder;
    decoder.decodeFromStreamToOutputStream(inputFile,of,freq,header);
    return 0;
}
