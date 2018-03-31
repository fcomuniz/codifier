//
// Created by francisco on 31/03/18.
//

#include "MessageSize.h"
#include <math.h>

namespace utils{
void MessageSize::calculateMessageSize(const utils::DataFrequency &frequency) {
    messageSize = 2+ceil(log2(frequency.getNOfBytes()));
}

int MessageSize::getMessageSize() const{
    if(messageSize == -1) throw std::runtime_error("hasn't calculated message size yet");
    return messageSize;
}

MessageSize::MessageSize() : messageSize(-1){

}
std::ostream & operator<<(std::ostream & os, const MessageSize & messageSize){
    os << messageSize <<" ";
    return os;
}
std::istream & operator>>(std::istream & is, const MessageSize & messageSize){
    is >> messageSize;
    return is;
}
}

