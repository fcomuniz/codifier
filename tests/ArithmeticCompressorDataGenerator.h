//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_ARITHMETICCOMPRESSORDATAGENERATOR_H
#define MY_LIB_ARITHMETICCOMPRESSORDATAGENERATOR_H
#include "utils/DataTypes.h"

std::vector<unsigned int> getExampleFrequency(){
    std::vector<unsigned int> retValue(utils::SIZE_OF_BYTES, 0);
    retValue['1'] = 40;
    retValue['2'] = 1;
    retValue['3'] = 9;
    return retValue;
}

#endif //MY_LIB_ARITHMETICCOMPRESSORDATAGENERATOR_H
