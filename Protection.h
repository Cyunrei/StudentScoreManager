//
// Created by cyunrei on 2/11/20.
//

#ifndef STUDENTSCOREMANAGER_PROTECTION_H
#define STUDENTSCOREMANAGER_PROTECTION_H


#include <string>
#include <ctime>

class Protection {
public:
    static void tempFile(const std::string &);

    static void tempFileRemove(const std::string &);

    static int captcha();
};

#endif //STUDENTSCOREMANAGER_PROTECTION_H
