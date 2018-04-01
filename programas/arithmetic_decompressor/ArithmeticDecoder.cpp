//
// Created by francisco on 31/03/18.
//

#include <structures/MyBitManipulation.h>
#include <bitset>
#include "ArithmeticDecoder.h"

namespace arithmetic_decompressor{
long long arithmetic_decompressor::ArithmeticDecoder::readBits(std::istream & is, long long n) {
    long long retNumber = 0;
    for(long long i = 0; i < n; i++){
        retNumber = retNumber<<1 | readFromBuffer(is);
    }
    return retNumber;
}

bool ArithmeticDecoder::readFromBuffer(std::istream &is) {
    if(bufferBitsRead == 8){
        canRead = writer.readFromFile(is,buffer);
        bufferBitsRead = 0;
    }
    bool retBit = ((buffer >> (8-bufferBitsRead-1)) & 1) == 1;
    bufferBitsRead++;
    return retBit;
}

void
ArithmeticDecoder::decodeFromStreamToOutputStream(std::istream &is, std::ostream &os, const utils::DataFrequency &freq,
                                                  const utils::MessageHeader &messageSize) {
    initializeValues(messageSize);
    long long readBytes = 0;
    t = readBits(is,m);
    while(canRead && readBytes <messageSize.getMessageSize()){
        utils::byte k = 0;
        while(((t-l+1)*freq.getNOfBytes() -1 )/(u-l+1) >= freq.getAcummulatedFrequency()[k])k++;
        writer.writeToFile(os,k);
        readBytes++;
        updateLimits(k,freq);
        while(haveSameMSB() || hasE3Cond()){
            if(haveSameMSB()){
                shiftL(false);
                shiftU(false);
                shiftT(is,false);
            }
            if(hasE3Cond()){
                shiftL(true);
                shiftU(true);
                shiftT(is,true);
            }
        }
    }
}

void ArithmeticDecoder::initializeValues(const utils::MessageHeader &messageSize) {
    buffer = 0;
    bufferBitsRead=8;
    m = messageSize.getMessageBytesSize();
    l = 0;
    u = (1<<m)-1;
    msb = m-1;
    bool canRead = true;
}

void ArithmeticDecoder::updateLimits(utils::byte x, const utils::DataFrequency & freq) {
    long long prevL = l;
    long long prevU = u;
    long long cumVal = 0;
    if(x != 0)
        cumVal = freq.getAcummulatedFrequency()[x-1];
    l = prevL + ((prevU-prevL+1)*cumVal)/freq.getNOfBytes();
    u = prevL + ((prevU-prevL+1)*freq.getAcummulatedFrequency()[x])/freq.getNOfBytes() - 1;
}

bool ArithmeticDecoder::haveSameMSB() {
    return getMSB(l) == getMSB(u);
}

bool ArithmeticDecoder::getMSB(unsigned long long l) {
    return getBit(l,msb);
}

void ArithmeticDecoder::shiftL(bool withComplement) {
    l = l << 1;
    if(withComplement)
        complementMSB(l);
    limitValue(l);
}

void ArithmeticDecoder::shiftU(bool withComplement) {
    u = (u<<1) | 1;
    if(withComplement)
        complementMSB(u);
    limitValue(u);
}

void ArithmeticDecoder::shiftT(std::istream & is, bool withComplement) {
    t = t<<1 | readBits(is,1);
    if(withComplement)
        complementMSB(t);
    limitValue(t);
}

void ArithmeticDecoder::complementMSB(unsigned long long & i) {
    i = flipBit(i,msb);
}

bool ArithmeticDecoder::hasE3Cond() {
    return (getBit(u,msb-1)== 0 && getBit(l,msb-1)==1);
}

void ArithmeticDecoder::decodeFromStream(std::istream &is, const utils::DataFrequency &freq,
                                         const utils::MessageHeader &messageSize) {
    decodeFromStreamToOutputStream(is,decodedMessage,freq,messageSize);

}

std::string ArithmeticDecoder::getDecodedMessage() {
    return decodedMessage.str();
}

void ArithmeticDecoder::limitValue(unsigned long long & i) {
   if(i >= (1 << (m))){
        i = (i%((1)<<(m)));
   }
}

}

