//
// Created by francisco on 31/03/18.
//

#include "ArithmeticEncoder.h"
#include <cmath>
#include "structures/MyBitManipulation.h"
namespace arithmetic_compressor{

void ArithmeticEncoder::encode(std::istream &is) {
    freq.setFrequencyVector(is);
    messageSize.calculateMessageSize(freq);
    initilizeValues();
    is.clear();
    is.seekg(0,std::ios_base::beg);
    utils::byte symbol;
    int acuCountBefore;
    while(is>>symbol){
        if(symbol == 0){
            acuCountBefore=0;
        } else {
            acuCountBefore = freq.getAcummulatedFrequency()[symbol-1];
        }
        l = l +floor(((u-l+1)*acuCountBefore)/freq.getNOfBytes());
        u = l + floor(((u-l+1)*freq.getAcummulatedFrequency()[symbol])/freq.getNOfBytes());
        int msbPos = m-1;
        bool cond1 = !(getBit(l,msbPos) ^ getBit(u,msbPos));
        bool cond2 = (getBit(u,msbPos-1)== 0 && getBit(l,msbPos-1)==1);
        int scale3=0;
        while(cond1 || cond2){
            if(cond1){
                 encodedMessage << getBit(l,msbPos);
                l = (l<<1);
                u = (u<<1) | 1;
                while(scale3>0){
                    encodedMessage << !getBit(l,msbPos);
                    scale3--;
                }
            }
            if(cond2){
                l = l<<1;
                u = (u<<1)|1;
                flipBit(l,msbPos);
                flipBit(u,msbPos);
                scale3++;
            }
           cond1 = !(getBit(l,msbPos) ^ getBit(u,msbPos));
           cond2 = (getBit(u,msbPos-1)== 0 && getBit(l,msbPos-1)==1);
        }
    }

}

void ArithmeticEncoder::initilizeValues() {
    m = 8;
    l = 0;
    u = (1<<m)-1;

}

std::string ArithmeticEncoder::getEncodedMessage() {
    return encodedMessage.str();
}
}
