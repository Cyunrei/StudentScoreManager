//
// Created by cyunrei on 2/10/20.
//

#ifndef STUDENTSCOREMANAGER_DATA_H
#define STUDENTSCOREMANAGER_DATA_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <list>
#include "Coding.h"
#include "Encryption.h"

#ifdef linux

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#endif

#ifdef WIN32

#include <io.h>
#include <direct.h>

#endif


class Data {

public:
    static void init();

    static void write_data(const std::string &, const std::string &, bool = false);

    static char *read_line(char *, int);

    static int get_file_line(const std::string &);

    static void change_password(const std::string &, const std::string &, const std::string &);

    static void token(const std::string &, const std::string &);

    static std::string token_decode();

    static bool token_exist();

    static void token_remove();

    int *student_list();

    int length;

    static int add(const std::string &);

    static void list();

    static void find(const std::string &);

    static void sort(const std::string &);

    static void remove(const std::string &);

    static void modify(const std::string &, const std::string &, const std::string &);
};

#endif //STUDENTSCOREMANAGER_DATA_H
