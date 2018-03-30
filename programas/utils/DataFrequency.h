//
// Created by pacocas on 3/30/18.
//

#ifndef MY_LIB_DATAFREQUENCY_H
#define MY_LIB_DATAFREQUENCY_H

#include <vector>
#include <iostream>
#include "DataTypes.h"

namespace utils{
    class DataFrequency {
    public:
        DataFrequency();
        void setFrequencyVector(std::istream & is);
        const std::vector<unsigned int> & getFrequencyVector();
        const size_t getNOfBytes();
        void reset();
    private:
        std::vector<unsigned int> frequencyVector;
        std::vector<double> acummulatedProbabilityVector;
        size_t nOfBytes;
    };

}


#endif //MY_LIB_DATAFREQUENCY_H
