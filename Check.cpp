//
// Created by cyunrei on 2/9/20.
//

#include "Check.h"
#include "Data.h"

#ifdef linux

int Check::input() {
    char str[100];
    std::cin >> str;
    return atoi(str);

}


#endif

#ifdef WIN32
#include <conio.h>
int Check::input() {
    char  ch;
    ch = getch();
    return ch - 48;
}

#endif

int Check::_input() {
    char str[100];
    std::cin >> str;
    return atoi(str);
}

bool Check::check_account_fm(const std::string &account) {
    return regex_match(account, std::regex("\\d{6,12}$"));
}

bool Check::check_password_fm(const std::string &password) {
    return regex_match(password, std::regex("[a-zA-Z0-9]{6,16}$"));
}

bool Check::check_account_exist(const std::string &account, const std::string &file_path) {

    for (int i = 1; i < Data::get_file_line(file_path); i++) {
        std::string line_data = Data::read_line((char *) file_path.c_str(), i);
        if (account == line_data.substr(0, account.length()) && line_data[account.length() + 1] == ' ') return true;
    }

    return false;
}

bool Check::match_password(const std::string &account, const std::string &password, const std::string &file_path) {

    static int line = 0;
    for (int i = 1; i < Data::get_file_line(file_path); i++) {
        std::string line_data = Data::read_line((char *) file_path.c_str(), i);
        if (account == line_data.substr(0, account.length()) && line_data[account.length() + 1] == ' ') {
            line = i;
            break;
        }
    }
    std::fstream file;
    std::string data;
    std::string temp;
    file.open(file_path, std::ios::in);
    for (int i = 1; !file.eof(); i++) {
        if (i == line) {
            getline(file, data);
            break;
        } else {
            getline(file, temp);
        }
    }
    file.close();
    return password == data.substr(account.length() + 2, password.length());
}
