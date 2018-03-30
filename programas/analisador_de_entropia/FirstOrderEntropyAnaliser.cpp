//
// Created by pacocas on 3/30/18.
//

#include "FirstOrderEntropyAnaliser.h"
#include <cmath>

namespace entropy_analiser{
    FirstOrderEntropyAnaliser::FirstOrderEntropyAnaliser(): entropy(0) , nOfBytes(0){

    }

    void FirstOrderEntropyAnaliser::analyseEntropy(std::istream &is) {
        resetFrequencyValues();
        loadFrequencyValues(is);
        setEntropyValue();
    }

    double FirstOrderEntropyAnaliser::getEntropy() {
        return entropy;
    }

    void FirstOrderEntropyAnaliser::resetFrequencyValues() {
        nOfBytes=0;
        for(int i = 0; i < utils::SIZE_OF_BYTES; i++){
            frequencyValues[i] = 0;
        }
    }

    void FirstOrderEntropyAnaliser::loadFrequencyValues(std::istream &is) {
        utils::byte currentByte;
        while(is >> currentByte){
            if(currentByte != ' '){
                frequencyValues[currentByte]++;
                nOfBytes++;
            }
        }
    }

    void FirstOrderEntropyAnaliser::setEntropyValue() {
        if(nOfBytes==0){
            entropy = 0;
            return;
        }
        for(int i = 0; i < utils::SIZE_OF_BYTES; i++){
            if(frequencyValues[i] != 0){
                double probability = ((double)frequencyValues[i])/nOfBytes;
                entropy -= probability*log2(probability);
            }
        }
    }

}