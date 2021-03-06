//
// Created by pacocas on 3/30/18.
//

#ifndef MY_LIB_FIRSTORDERENTROPYANALISER_H
#define MY_LIB_FIRSTORDERENTROPYANALISER_H

#include <iostream>
#include <utils/DataTypes.h>
#include <utils/DataFrequency.h>

namespace entropy_analiser{

    class FirstOrderEntropyAnaliser {
    public:
        FirstOrderEntropyAnaliser();
        void analyseEntropy(std::istream & is);

        double getEntropy();

    private:
        void resetFrequencyValues();
        void loadFrequencyValues(std::istream & os);
        void setEntropyValue();
        double entropy;
        utils::DataFrequency dataFrequency;


    };

}



#endif //MY_LIB_FIRSTORDERENTROPYANALISER_H
