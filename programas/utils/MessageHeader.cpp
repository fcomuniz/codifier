//
// Created by francisco on 31/03/18.
//

#include "MessageHeader.h"
#include "FileWriter.h"
#include <math.h>

namespace utils{
void MessageHeader::calculateMessageSize(const utils::DataFrequency &frequency) {
    messageBytesSize = 2+ceil(log2(frequency.getNOfBytes()));
    messageSize = frequency.getNOfBytes();
}

int MessageHeader::getMessageBytesSize() const{
    if(messageBytesSize == -1) throw std::runtime_error("hasn't calculated message size yet");
    return messageBytesSize;
}

MessageHeader::MessageHeader() : messageSize(-1), messageBytesSize(-1){

}
std::ostream & operator<<(std::ostream & os, const MessageHeader & messageSize){
    utils::FileWriter writer;
    writer.writeToFile(os,messageSize.messageSize);
    writer.writeToFile(os,messageSize.messageBytesSize);
    return os;
}
std::istream & operator>>(std::istream & is, MessageHeader & messageSize){
    utils::FileWriter writer;
    writer.readFromFile(is,messageSize.messageSize);
    writer.readFromFile(is,messageSize.messageBytesSize);
    return is;
}

int MessageHeader::getMessageSize() const {
    return messageSize;
}

void MessageHeader::setMessageSize(int messageSize) {
    this->messageSize = messageSize;
}
}

