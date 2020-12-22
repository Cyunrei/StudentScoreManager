//
// Created by cyunrei on 2/11/20.
//

#include "Protection.h"

void Protection::tempFile(const std::string &str) {
#ifdef linux
    char command[255];
    sprintf(command, "cp -f %s %s.temp", str.c_str(), str.c_str());
    system(command);
#endif
#ifdef WIN32
    char command[255];
    sprintf(command,"copy /y %s %s.temp",str.c_str(),str.c_str());
    system(command);
#endif
}

void Protection::tempFileRemove(const std::string &str) {
#ifdef linux
    char command[255];
    sprintf(command, "cp -f %s.temp %s && rm %s.temp", str.c_str(), str.c_str(), str.c_str());
    system(command);
#endif
#ifdef WIN32
    char command[255];
    sprintf(command,"copy /y  %s.temp %s && del %s.temp",str.c_str(),str.c_str(),str.c_str());
    system(command);
#endif
}

int Protection::captcha() {
    srand((unsigned) time(NULL));
    return rand() % (888889) + 111111;
}
