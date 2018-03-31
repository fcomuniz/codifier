//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_MESSAGESIZE_H
#define MY_LIB_MESSAGESIZE_H

#include "DataFrequency.h"

namespace utils{
class MessageHeader {
public:
    MessageHeader();
    void calculateMessageSize(const DataFrequency & frequency);
    int getMessageBytesSize() const ;
    int getMessageSize() const;
    void setMessageSize(int messageSize);
    friend std::ostream & operator<<(std::ostream & os, const MessageHeader & messageSize);
    friend std::istream & operator>>(std::istream & is, MessageHeader & messageSize);
private:
    int messageSize;
    int messageBytesSize;
};
std::ostream & operator<<(std::ostream & os, const MessageHeader & messageSize);
std::istream & operator>>(std::istream & is, MessageHeader & messageSize);
}


#endif //MY_LIB_MESSAGESIZE_H
