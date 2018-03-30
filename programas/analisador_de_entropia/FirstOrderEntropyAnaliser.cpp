//
// Created by pacocas on 3/30/18.
//

#include "FirstOrderEntropyAnaliser.h"
#include <cmath>

namespace entropy_analiser{
    FirstOrderEntropyAnaliser::FirstOrderEntropyAnaliser(): entropy(0){

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
        dataFrequency.reset();
    }

    void FirstOrderEntropyAnaliser::loadFrequencyValues(std::istream &is) {
        dataFrequency.setFrequencyVector(is);
    }

    void FirstOrderEntropyAnaliser::setEntropyValue() {
        if(dataFrequency.getNOfBytes()==0){
            entropy = 0;
            return;
        }
        for(int i = 0; i < utils::SIZE_OF_BYTES; i++){
            if(dataFrequency.getFrequencyVector()[i] != 0){
                double probability = ((double)dataFrequency.getFrequencyVector()[i])/dataFrequency.getNOfBytes();
                entropy -= probability*log2(probability);
            }
        }
    }

}