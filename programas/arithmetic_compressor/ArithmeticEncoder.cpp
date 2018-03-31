//
// Created by francisco on 31/03/18.
//

#include "ArithmeticEncoder.h"
#include <cmath>
#include "structures/MyBitManipulation.h"
namespace arithmetic_compressor{

void ArithmeticEncoder::encode(std::istream &is, const utils::DataFrequency &freq) {
    messageSize.calculateMessageSize(freq);
    initilizeValues(freq);
    utils::byte symbol;
    int acuCountBefore;
    int scale3 =0;
    while(is>>symbol){
        if(symbol == 0){
            acuCountBefore=0;
        } else {
            acuCountBefore = freq.getAcummulatedFrequency()[symbol-1];
        }
        int prevU = u;
        int prevL = l;

        l = prevL + ((prevU-prevL+1)*acuCountBefore)/freq.getNOfBytes();
        u = prevL + ((prevU-prevL+1)*freq.getAcummulatedFrequency()[symbol])/freq.getNOfBytes() -1;
        int msbPos = m-1;
        bool cond1 = !(getBit(l,msbPos) ^ getBit(u,msbPos));
        bool cond2 = (getBit(u,msbPos-1)== 0 && getBit(l,msbPos-1)==1);
        while(cond1 || cond2){
            if(cond1){
                bool bit = getBit(l,msbPos);
                 encodedMessage << getBit(l,msbPos);
                l = (l<<1);
                l = clearBit(l,msbPos+1);
                u = (u<<1) | 1;
                u = clearBit(u,msbPos+1);
                while(scale3>0){
                    encodedMessage << !bit;
                    scale3--;
                }
            }
            if(cond2){
                l =flipBit(l,msbPos-1);
                l = l<<1;
                l = clearBit(l,msbPos+1);
                u = flipBit(u,msbPos-1);
                u = (u<<1)|1;
                u = clearBit(u,msbPos+1);
                scale3++;
            }
           cond1 = !(getBit(l,msbPos) ^ getBit(u,msbPos));
           cond2 = (getBit(u,msbPos-1)== 0 && getBit(l,msbPos-1)==1);
        }
    }

}

void ArithmeticEncoder::initilizeValues(const utils::DataFrequency & freq) {
    m = 2+ceil(log2(freq.getNOfBytes()));
    l = 0;
    u = (1<<m)-1;

}

std::string ArithmeticEncoder::getEncodedMessage() {
    return encodedMessage.str();
}


}
