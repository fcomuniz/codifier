//
// Created by pacocas on 3/30/18.
//

#include "DataFrequency.h"

namespace utils{

    DataFrequency::DataFrequency() {
        frequencyVector = std::vector<unsigned int>(utils::SIZE_OF_BYTES,0);
        acummulatedFrequency = std::vector<unsigned int>(utils::SIZE_OF_BYTES,0);
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
        setAcummulatedFrequency();
    }

    const std::vector<unsigned int> &DataFrequency::getFrequencyVector() const {
        return frequencyVector;
    }

    const size_t DataFrequency::getNOfBytes() const{
        return nOfBytes;
    }

    void DataFrequency::reset() {
        for(int i = 0; i < frequencyVector.size();i++){
            frequencyVector[i]=0;
            acummulatedFrequency[i] =0;
        }
        nOfBytes=0;
    }

const std::vector<unsigned int> &DataFrequency::getAcummulatedFrequency() const {
    return acummulatedFrequency;
}

void DataFrequency::setFrequencyVector(const std::vector<utils::byte> &bytes) {
    reset();
    for(const auto & b: bytes){
        frequencyVector[b]++;
        nOfBytes++;
    }
    setAcummulatedFrequency();

}

void DataFrequency::setAcummulatedFrequency() {
    acummulatedFrequency[0] = frequencyVector[0];
    for(int i =1, n = acummulatedFrequency.size(); i < n; i++){
        acummulatedFrequency[i] = acummulatedFrequency[i-1] + frequencyVector[i];
    }
}
}

