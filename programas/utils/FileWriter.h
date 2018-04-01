//
// Created by francisco on 31/03/18.
//

#ifndef MY_LIB_FILEWRITER_H
#define MY_LIB_FILEWRITER_H

#include <fstream>

namespace utils{
class FileWriter {
public:
    template<class T>
    bool writeToFile(std::ostream & os, const T & v){
        bool retV = false;
        for(int i = sizeof(T)-1; i>=0; i--){
            os.put(((v>>8*i)&0xff));
            retV |= os.bad() || os.eof();
        }
        return retV;
    }

    template<class T>
    bool readFromFile(std::istream & is, T & v){
        if(is.eof()) return false;
        v = 0;
        for(int i = sizeof(T)-1; i >=0; i--){
            v = (v<<8) | is.get();
            if(is.bad() || is.eof()) return false;
        }
        return true;
    }

};

}


#endif //MY_LIB_FILEWRITER_H
