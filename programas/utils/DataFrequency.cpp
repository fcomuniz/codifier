//
// Created by pacocas on 3/30/18.
//

#include "DataFrequency.h"

namespace utils{

    DataFrequency::DataFrequency() {
        frequencyVector = std::vector<unsigned int>(utils::SIZE_OF_BYTES,0);
        nOfBytes=0;
    }

    void DataFrequency::setFrequencyVector(std::istream &is) {
        utils::byte currentByte;
        while(is >> currentByte){
            if(currentByte != ' '){
                frequencyVector[currentByte]++;
                nOfBytes++;
            }
        }
    }

    const std::vector<unsigned int> &DataFrequency::getFrequencyVector() {
        return frequencyVector;
    }

    const size_t DataFrequency::getNOfBytes() {
        return nOfBytes;
    }

    void DataFrequency::reset() {
        for(int i = 0; i < frequencyVector.size();i++){
            frequencyVector[i]=0;
        }
        nOfBytes=0;
    }
}

