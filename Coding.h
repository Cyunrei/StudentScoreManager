//
// Created by cyunrei on 2/11/20.
//

#ifndef STUDENTSCOREMANAGER_CODING_H
#define STUDENTSCOREMANAGER_CODING_H

#include <string>

class Coding {
public:
    static std::string base64_encode(unsigned char const *, unsigned int len);

    static std::string base64_decode(std::string const &s);
};

#endif //STUDENTSCOREMANAGER_CODING_H
