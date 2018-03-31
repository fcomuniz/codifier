//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_MESSAGESIZE_H
#define MY_LIB_MESSAGESIZE_H

#include "DataFrequency.h"

namespace utils{
class MessageSize {
public:
    MessageSize();
    void calculateMessageSize(const DataFrequency & frequency);
    int getMessageSize() const ;
    friend std::ostream & operator<<(std::ostream & os, const MessageSize & messageSize);
    friend std::istream & operator>>(std::istream & is, const MessageSize & messageSize);
private:
    int messageSize;
};
std::ostream & operator<<(std::ostream & os, const MessageSize & messageSize);
std::istream & operator>>(std::istream & is, const MessageSize & messageSize);
}


#endif //MY_LIB_MESSAGESIZE_H
