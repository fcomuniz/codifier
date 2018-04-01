//
// Created by francisco on 31/03/18.
//

#include "ArithmeticEncoder.h"
#include <cmath>
#include <bitset>
#include "structures/MyBitManipulation.h"
namespace arithmetic_compressor{

void ArithmeticEncoder::encode(std::istream &is, const utils::DataFrequency &freq) {
    encodeAndSend(is,encodedMessage,freq);
}

void ArithmeticEncoder::initilizeValues(const utils::DataFrequency & freq) {
    messageSize.calculateMessageSize(freq);
    m = messageSize.getMessageBytesSize();
    l = 0;
    u = (1<<m)-1;
    msb = m-1;

}

std::string ArithmeticEncoder::getEncodedMessage() {
    return encodedMessage.str();
}

void ArithmeticEncoder::encodeAndSend(std::istream &is, std::ostream &os, const utils::DataFrequency &freq) {
    initilizeValues(freq);
    utils::byte symbol;
   long long scale3 =0;
    long long nOfSymbols = 0;
    while(writer.readFromFile(is,symbol)){
        nOfSymbols++;
        updateLimits(symbol,freq);
        while(haveSameMSB(l,u) || hasE3Condition(l,u)){
            if(haveSameMSB(l,u)){
                bool bit = getBit(l,msb);
                sendInBuffer(os,bit);
                shiftL(false);
                shiftU(false);
                while(scale3>0){
                    sendInBuffer(os,!bit);
                    scale3--;
                }
            }
            if(hasE3Condition(l,u)){
                shiftL(true);
                shiftU(true);
                scale3++;
            }
        }
    }
    for(long long i = 1; i <= m; i++){
        sendInBuffer(os,getBit(l,m-i));
        if(scale3){
            sendInBuffer(os,true);
            scale3--;
        }
    }
    while(bufferSize != 0){
        sendInBuffer(os,false);
    }
}

ArithmeticEncoder::ArithmeticEncoder() {
    buffer=0;
    bufferSize = 0;
    l = 0;
    m = 0;
    u = 0;


}

void ArithmeticEncoder::sendInBuffer(std::ostream &os, bool bit) {
    buffer = buffer<<1 | bit;
    bufferSize++;
    if(bufferSize == 8){
        writer.writeToFile(os,buffer);
        buffer=0;
        bufferSize=0;
    }
}

void ArithmeticEncoder::sendIncompleteBuffer(std::ostream &os) {
    if(bufferSize != 0){
        os << (utils::byte)(buffer<<(8-bufferSize));
    }
}

void ArithmeticEncoder::updateLimits(utils::byte symbol, const utils::DataFrequency & freq){
	long long prevL = l;
	long long prevU = u;
    long long acuCountBefore = 0;
    if(symbol !=0){
        acuCountBefore = freq.getAcummulatedFrequency()[symbol-1];
    }
    l = prevL + ((prevU-prevL+1)*acuCountBefore)/freq.getNOfBytes();
    u = prevL + ((prevU-prevL+1)*freq.getAcummulatedFrequency()[symbol])/freq.getNOfBytes() -1;
}

bool ArithmeticEncoder::haveSameMSB(long long l, long long u) {
    return getMostSignificantBit(l) == getMostSignificantBit(u);
}

bool ArithmeticEncoder::getMostSignificantBit(long long v) {
    return getBit(v,msb);
}

bool ArithmeticEncoder::hasE3Condition(long long l, long long u) {
    return getBit(l,msb-1) == true && getBit(u,msb-1) == false;
}

void ArithmeticEncoder::shiftU(bool withflip) {
    u = (u<<1)|1;
    if(withflip)
        u = flipBit(u,msb);
    u = clearBit(u,msb+1);
}

void ArithmeticEncoder::shiftL(bool withFlip) {
    l = l<<1;
    if(withFlip)
        l =flipBit(l,msb);
    l = clearBit(l,msb+1);
}


}
