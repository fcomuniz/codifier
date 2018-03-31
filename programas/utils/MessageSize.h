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
    int getMessageSize();
private:
    int messageSize;
};
}


#endif //MY_LIB_MESSAGESIZE_H
