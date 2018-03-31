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
        void setFrequencyVector(const std::vector<unsigned int> & freqV);
        const std::vector<unsigned int> & getFrequencyVector() const ;
        const std::vector<unsigned int> & getAcummulatedFrequency()const ;
        const size_t getNOfBytes() const;
        void reset();

        friend std::istream &operator>>(std::istream & is, DataFrequency & d);
        friend std::ostream &operator<<(std::ostream & os, const DataFrequency & d);

    private:
        void setAcummulatedFrequency();
        std::vector<unsigned int> frequencyVector;
        std::vector<unsigned int> acummulatedFrequency;
        std::vector<double> acummulatedProbabilityVector;
        size_t nOfBytes;
    };
    std::istream &operator>>(std::istream & is, DataFrequency & d);
    std::ostream &operator<<(std::ostream & os, const DataFrequency & d);

}


#endif //MY_LIB_DATAFREQUENCY_H
