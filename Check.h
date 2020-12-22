//
// Created by cyunrei on 2/9/20.
//

#ifndef STUDENTSCOREMANAGER_CHECK_H
#define STUDENTSCOREMANAGER_CHECK_H

#include <iostream>
#include <regex>

class Check {
public:


    static int input();

    static int _input();

    static bool check_account_fm(const std::string &);

    static bool check_password_fm(const std::string &);

    static bool check_account_exist(const std::string &, const std::string &);

    static bool match_password(const std::string &, const std::string &, const std::string &);

};


#endif //STUDENTSCOREMANAGER_CHECK_H
