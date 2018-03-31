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
        void setFrequencyVector(const std::vector<utils::byte> & bytes);
        const std::vector<unsigned int> & getFrequencyVector() const ;
        const std::vector<unsigned int> & getAcummulatedFrequency()const ;
        const size_t getNOfBytes() const;
        void reset();
    private:
        void setAcummulatedFrequency();
        std::vector<unsigned int> frequencyVector;
        std::vector<unsigned int> acummulatedFrequency;
        std::vector<double> acummulatedProbabilityVector;
        size_t nOfBytes;
    };

}


#endif //MY_LIB_DATAFREQUENCY_H
