//
// Created by cyunrei on 2/9/20.
//

#include "Layout.h"

#ifdef linux

#define CLEAR "clear"

#endif

#ifdef WIN32

#define CLEAR "cls"

#include <conio.h>

static std::string getpass(const char[1]) {
    char *password;
    int length = 16;
    password = new char[length + 1];
    char *p = NULL;
    int count = 0;
    p = password;

    while (((*p = getch()) != 13) && count < length)
    {

        putch('*');
        fflush(stdin);
        p++;
        count++;
    }
    password[count] = '\0';
    std::string password_str(password);
    return password_str;

}

#endif

#define INITIAL 0
#define MISMATCHED 1

#define REGISTER_AC_INPUT -1
#define REGISTER_AC_FORMAT_ERROR -2
#define REGISTER_PW_FORMAT_ERROR -3
#define REGISTER_ACTIVE_CONFIRM_PW -4
#define REGISTER_PW_INPUT -5
#define REGISTER_AC_ALREADY_EXIST -6
#define REGISTER_AC_PW_MISMATCHED -7

#define FORGET_PW_AC_INPUT -8
#define FORGET_PW_AC_FORMAT_ERROR -9
#define FORGET_PW_AC_NOT_EXIST -10
#define FORGET_PW_CAPTCHA_INPUT -11
#define FORGET_PW_PW_INPUT -12
#define FORGET_PW_CAPTCHA_ERROR -13
#define FORGET_PW_PW_FORMAT_ERROR -14
#define FORGET_ACTIVE_CONFIRM_PW -15
#define FORGET_PW_PW_MISMATCHED -16

#define LOGIN_AC_INPUT -17
#define LOGIN_AC_FORMAT_ERROR -18
#define LOGIN_AC_NOT_EXIST -19
#define LOGIN_PW_INPUT -20
#define LOGIN_PW_FORMAT_ERROR -21
#define LOGIN_PW_MISMATCHED -22

#define TEACHER_REGISTER_SUCCESS 200
#define STUDENT_REGISTER_SUCCESS 201

#define TEACHER_GET_BACK_PW_SUCCESS 300
#define STUDENT_GET_BACK_PW_SUCCESS 301

#define TEACHER_LOGIN_SUCCESS 400
#define STUDENT_LOGIN_SUCCESS 401

#define TEACHER_CODE 100
#define STUDENT_CODE 101

#ifdef linux
#define TEACHER_ACCOUNTS_FILE_PATH "./.data/teacher_accounts.dat"
#define STUDENT_ACCOUNTS_FILE_PATH "./.data/student_accounts.dat"
#define TEACHER_ACCOUNTS_FILE_TEMP_PATH "./.data/teacher_accounts.dat.temp"
#define STUDENT_ACCOUNTS_FILE_TEMP_PATH "./.data/student_accounts.dat.temp"
#endif

#ifdef WIN32
#define TEACHER_ACCOUNTS_FILE_PATH ".\\.data\\teacher_accounts.dat"
#define STUDENT_ACCOUNTS_FILE_PATH ".\\.data\\student_accounts.dat"
#define TEACHER_ACCOUNTS_FILE_TEMP_PATH ".\\.data\\teacher_accounts.dat.temp"
#define STUDENT_ACCOUNTS_FILE_TEMP_PATH ".\\.data\\student_accounts.dat.temp"
#endif

#define INPUT_YOUR_OPTION "请输入你的选项：\n"
#define INPUT_OPTION_MISMATCHED "选项错误！请重新输入你的选项：\n"
#define INPUT_ACCOUNT "请输入账号：\n"
#define INPUT_PASSWORD "请输入密码：\n"
#define INPUT_CONFIRM_PASSWORD "请输入确认密码：\n"
#define INPUT_FORGET_ACCOUNT "请输入忘记账号：\n"
#define INPUT_CAPTCHA_L "请输入验证码("
#define INPUT_CAPTCHA_R ")：\n"
#define INPUT_NEW_PASSWORD "请输入新的密码：\n"
#define INPUT_CONFIRM_NEW_PASSWORD "请确认输入新的密码：\n"
#define ACCOUNT_FORMAT_ERROR "账号格式有误！请重新输入账号：\n"
#define ACCOUNT_ALREADY_EXIST "账号已存在！请重新输入账号：\n"
#define ACCOUNT_NOT_EXIST "账号不存在！请重新输入账号：\n"
#define FORGET_ACCOUNT_FORMAT_ERROR "账号格式错误！请重新请输入忘记账号：\n"
#define FORGET_ACCOUNT_NOT_EXIST "账号不存在！请重新请输入忘记账号：\n"
#define PASSWORD_FORMAT_ERROR "密码格式错误！请重新输入：\n"
#define PASSWORD_ERROR "密码错误！请重新输入密码：\n"
#define CONFIRM_PASSWORD_MISMATCHED "确认密码不匹配！请重新输入新的密码：\n"
#define CAPTCHA_ERROR_L "验证码错误！请重新输入验证码("
#define CAPTCHA_ERROR_R ")：\n"

void Layout::clear() {
    system(CLEAR);
}

#ifdef WIN32

void Layout::init()
{
    //    char command[255];
//    sprintf(command,"mode %d,%d",56,14);
//    system(command);
    system("color 9F");
}


#endif

#ifdef linux

void Layout::init() {
}

#endif

void Layout::page_top(const std::string &str) {
    unsigned int len = 30 - str.size();
    for (int i = 0; i < 18; i++)
        std::cout << '=';
    for (int i = 0; i < len / 4; i++)
        std::cout << '=';
    std::cout << str;
    for (int i = 0; i < len / 4; i++)
        std::cout << '=';
    for (int i = 0; i < 18; i++)
        std::cout << '=';
    std::cout << "\n\n" << std::endl;
}

void Layout::page_context(std::vector<std::string> str, int height, bool center) {

    if (center) {
        unsigned int width_len = width - str.size() * 2 + 1;
        for (int i = 0; i < width_len / 2; i++)
            std::cout << std::endl;

        for (auto &i : str) {
            unsigned int len = 32 - i.size();
            for (int j = 0; j < 18; j++)
                std::cout << ' ';
            for (int j = 0; j < len / 4; j++)
                std::cout << ' ';
            std::cout << i;
            std::cout << '\n' << std::endl;
        }

        for (int i = 0; i < width_len / 2 + height; i++)
            std::cout << std::endl;

    } else {
        unsigned int width_len = width - str.size() * 2 + 1;
        unsigned int length_len = (length - str[0].size() - 3) / 2;
        for (int i = 0; i < width_len / 2; i++)
            std::cout << std::endl;
        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < length_len; j++)
                std::cout << ' ';
            std::cout << '[' << i + 1 << ']' << str[i] << '\n' << std::endl;
        }
        for (int i = 0; i < width_len / 2 + height; i++)
            std::cout << std::endl;
    }
}

void Layout::page_button(const std::string &str_1, int value_1, const std::string &str_2, int value_2, int context) {

    switch (context) {
        case REGISTER_AC_INPUT:
        case REGISTER_AC_FORMAT_ERROR:
        case REGISTER_PW_FORMAT_ERROR:
        case REGISTER_ACTIVE_CONFIRM_PW:
        case REGISTER_PW_INPUT:
        case REGISTER_AC_ALREADY_EXIST:
        case REGISTER_AC_PW_MISMATCHED:
        case FORGET_PW_PW_INPUT:
        case FORGET_PW_CAPTCHA_ERROR:
        case FORGET_PW_CAPTCHA_INPUT:
        case FORGET_PW_AC_NOT_EXIST:
        case FORGET_PW_AC_FORMAT_ERROR:
        case FORGET_PW_AC_INPUT:
        case FORGET_ACTIVE_CONFIRM_PW:
        case FORGET_PW_PW_MISMATCHED:
        case LOGIN_AC_INPUT:
        case LOGIN_AC_FORMAT_ERROR:
        case LOGIN_AC_NOT_EXIST:
        case LOGIN_PW_INPUT:
        case LOGIN_PW_FORMAT_ERROR:
        case LOGIN_PW_MISMATCHED:
            std::cout << std::endl;
            return;
        default:
            break;
    }
    std::cout << '<';
    for (int i = 0; i < 5; i++)
        std::cout << '-';
    if (str_2 == "none" && value_2 == -1)std::cout << '[' << value_1 << ']' << str_1 << std::endl;
    else {
        std::cout << '[' << value_1 << ']' << str_1;
        for (int i = 0; i < 14; i++)
            std::cout << ' ';
        std::cout << '[' << value_2 << ']' << str_2;
        for (int i = 0; i < 5; i++)
            std::cout << '-';
        std::cout << '>' << std::endl;
    }
}

void Layout::page_bottom(const std::string &str) {
    unsigned int len = 30 - str.size();
    for (int i = 0; i < 19; i++)
        std::cout << '=';
    for (int i = 0; i < len / 4; i++)
        std::cout << '=';
    std::cout << str;
    for (int i = 0; i < len / 4; i++)
        std::cout << '=';
    for (int i = 0; i < 19; i++)
        std::cout << '=';
    std::cout << "\n\n" << std::endl;
}

void Layout::tip(int value, const std::function<void(int)> &func, int code) {

    static std::string password;
    static std::string account;
    if (value == INITIAL) std::cout << INPUT_YOUR_OPTION << std::endl;
    else if (value == MISMATCHED) std::cout << INPUT_OPTION_MISMATCHED << std::endl;
    else if (value == REGISTER_AC_ALREADY_EXIST) {
        if (code == TEACHER_CODE) Protection::tempFile(TEACHER_ACCOUNTS_FILE_PATH);
        else if (code == STUDENT_CODE) Protection::tempFile(STUDENT_ACCOUNTS_FILE_PATH);
        std::cout << ACCOUNT_ALREADY_EXIST << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(REGISTER_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);
                if (code == TEACHER_CODE) {
                    switch (Check::check_account_exist(account, TEACHER_ACCOUNTS_FILE_TEMP_PATH)) {
                        case 0:
                            Data::write_data(account, TEACHER_ACCOUNTS_FILE_TEMP_PATH);
                            break;
                        case 1:
                            return func(REGISTER_AC_ALREADY_EXIST);
                    }
                } else if (code == STUDENT_CODE) {
                    switch (Check::check_account_exist(account, STUDENT_ACCOUNTS_FILE_PATH)) {
                        case 0:
                            return Data::write_data(account, STUDENT_ACCOUNTS_FILE_TEMP_PATH);
                        case 1:
                            return func(REGISTER_AC_ALREADY_EXIST);
                    }
                }
                return func(REGISTER_PW_INPUT);
        }
    } else if (value == REGISTER_AC_INPUT) {
        if (code == TEACHER_CODE) Protection::tempFile(TEACHER_ACCOUNTS_FILE_PATH);
        else if (code == STUDENT_CODE) Protection::tempFile(STUDENT_ACCOUNTS_FILE_PATH);
        std::cout << INPUT_ACCOUNT << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(REGISTER_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);
                if (code == TEACHER_CODE) {
                    switch (Check::check_account_exist(account, TEACHER_ACCOUNTS_FILE_TEMP_PATH)) {
                        case 0:
                            Data::write_data(account, TEACHER_ACCOUNTS_FILE_TEMP_PATH);
                            break;
                        case 1:
                            return func(REGISTER_AC_ALREADY_EXIST);
                    }
                } else if (code == STUDENT_CODE) {
                    switch (Check::check_account_exist(account, STUDENT_ACCOUNTS_FILE_TEMP_PATH)) {
                        case 0:
                            Data::write_data(account, STUDENT_ACCOUNTS_FILE_TEMP_PATH);
                            break;
                        case 1:
                            return func(REGISTER_AC_ALREADY_EXIST);
                    }
                }
                return func(REGISTER_PW_INPUT);
        }
    } else if (value == REGISTER_AC_FORMAT_ERROR) {
        std::cout << ACCOUNT_FORMAT_ERROR << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(REGISTER_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);
                if (code == TEACHER_CODE) Data::write_data(account, TEACHER_ACCOUNTS_FILE_PATH);
                else if (code == STUDENT_CODE) Data::write_data(account, STUDENT_ACCOUNTS_FILE_PATH);
                return func(REGISTER_PW_INPUT);
        }
    } else if (value == REGISTER_PW_INPUT) {
        std::cout << INPUT_PASSWORD << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(REGISTER_PW_FORMAT_ERROR);
            case 1:
                return func(REGISTER_ACTIVE_CONFIRM_PW);
        }
    } else if (value == REGISTER_PW_FORMAT_ERROR) {

        std::cout << PASSWORD_FORMAT_ERROR << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(REGISTER_PW_FORMAT_ERROR);
            case 1:
                return func(REGISTER_ACTIVE_CONFIRM_PW);
        }
    } else if (value == REGISTER_ACTIVE_CONFIRM_PW) {
        std::string confirm_password;
        std::cout << INPUT_CONFIRM_PASSWORD << std::endl;

        confirm_password = getpass("");
        if (password == confirm_password) {

            password = Coding::base64_encode(reinterpret_cast<const unsigned char *>(password.c_str()),
                                             password.length());
            Encryption::caesar(password);

            if (code == TEACHER_CODE) {
                Data::write_data(password, TEACHER_ACCOUNTS_FILE_TEMP_PATH, true);
                Protection::tempFileRemove(TEACHER_ACCOUNTS_FILE_PATH);
                return func(TEACHER_REGISTER_SUCCESS);
            } else if (code == STUDENT_CODE) {
                Data::write_data(password, STUDENT_ACCOUNTS_FILE_TEMP_PATH, true);
                Protection::tempFileRemove(STUDENT_ACCOUNTS_FILE_PATH);
                return func(STUDENT_REGISTER_SUCCESS);
            }
        } else {
            return func(REGISTER_AC_PW_MISMATCHED);
        }
    } else if (value == REGISTER_AC_PW_MISMATCHED) {
        std::cout << CONFIRM_PASSWORD_MISMATCHED << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(REGISTER_PW_FORMAT_ERROR);
            case 1:
                return func(REGISTER_ACTIVE_CONFIRM_PW);
        }
    } else if (value == FORGET_PW_AC_INPUT) {
        if (code == TEACHER_CODE) Protection::tempFile(TEACHER_ACCOUNTS_FILE_PATH);
        else if (code == STUDENT_CODE) Protection::tempFile(STUDENT_ACCOUNTS_FILE_PATH);
        std::cout << INPUT_FORGET_ACCOUNT << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(FORGET_PW_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);

                switch (Check::check_account_exist(account, (code == TEACHER_CODE) ? TEACHER_ACCOUNTS_FILE_TEMP_PATH
                                                                                   : STUDENT_ACCOUNTS_FILE_TEMP_PATH)) {
                    case 0:
                        return func(FORGET_PW_AC_NOT_EXIST);
                    case 1:
                        return func(FORGET_PW_CAPTCHA_INPUT);
                }
        }
    } else if (value == FORGET_PW_AC_FORMAT_ERROR) {
        if (code == TEACHER_CODE) Protection::tempFile(TEACHER_ACCOUNTS_FILE_PATH);
        else if (code == STUDENT_CODE) Protection::tempFile(STUDENT_ACCOUNTS_FILE_PATH);
        std::cout << FORGET_ACCOUNT_FORMAT_ERROR << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(FORGET_PW_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);

                switch (Check::check_account_exist(account, (code == TEACHER_CODE) ? TEACHER_ACCOUNTS_FILE_TEMP_PATH
                                                                                   : STUDENT_ACCOUNTS_FILE_TEMP_PATH)) {
                    case 0:
                        return func(FORGET_PW_AC_NOT_EXIST);
                    case 1:
                        return func(FORGET_PW_CAPTCHA_INPUT);
                }
        }
    } else if (value == FORGET_PW_AC_NOT_EXIST) {
        if (code == TEACHER_CODE) Protection::tempFile(TEACHER_ACCOUNTS_FILE_PATH);
        else if (code == STUDENT_CODE) Protection::tempFile(STUDENT_ACCOUNTS_FILE_PATH);
        std::cout << FORGET_ACCOUNT_NOT_EXIST << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(FORGET_PW_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);

                switch (Check::check_account_exist(account, (code == TEACHER_CODE) ? TEACHER_ACCOUNTS_FILE_TEMP_PATH
                                                                                   : STUDENT_ACCOUNTS_FILE_TEMP_PATH)) {
                    case 0:
                        return func(FORGET_PW_AC_NOT_EXIST);
                    case 1:
                        return func(FORGET_PW_CAPTCHA_INPUT);
                }
        }
    } else if (value == FORGET_PW_CAPTCHA_INPUT) {
        int captcha = Protection::captcha();
        int t_captcha;
        std::cout << INPUT_CAPTCHA_L << captcha << INPUT_CAPTCHA_R << std::endl;
        std::cin >> t_captcha;
        if (captcha == t_captcha) return func(FORGET_PW_PW_INPUT);
        else return func(FORGET_PW_CAPTCHA_ERROR);
    } else if (value == FORGET_PW_CAPTCHA_ERROR) {
        int captcha = Protection::captcha();
        int t_captcha;
        std::cout << CAPTCHA_ERROR_L << captcha << CAPTCHA_ERROR_R << std::endl;
        std::cin >> t_captcha;
        if (captcha == t_captcha) return func(FORGET_PW_PW_INPUT);
        else return func(FORGET_PW_CAPTCHA_ERROR);
    } else if (value == FORGET_PW_PW_INPUT) {
        std::cout << INPUT_NEW_PASSWORD << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(FORGET_PW_AC_FORMAT_ERROR);
            case 1:
                return func(FORGET_ACTIVE_CONFIRM_PW);
        }
    } else if (value == FORGET_ACTIVE_CONFIRM_PW) {
        std::cout << INPUT_CONFIRM_NEW_PASSWORD << std::endl;
        std::string confirm_password;
        confirm_password = getpass("");
        if (password == confirm_password) {
            password = Coding::base64_encode(reinterpret_cast<const unsigned char *>(password.c_str()),
                                             password.length());
            Encryption::caesar(password);
            if (code == TEACHER_CODE) {
                Data::change_password(account, password, TEACHER_ACCOUNTS_FILE_TEMP_PATH);
                Protection::tempFileRemove(TEACHER_ACCOUNTS_FILE_PATH);
                return func(TEACHER_GET_BACK_PW_SUCCESS);
            } else if (code == STUDENT_CODE) {
                Data::change_password(account, password, STUDENT_ACCOUNTS_FILE_TEMP_PATH);
                Protection::tempFileRemove(STUDENT_ACCOUNTS_FILE_PATH);
                return func(STUDENT_GET_BACK_PW_SUCCESS);
            }
        } else {
            return func(FORGET_PW_PW_MISMATCHED);
        }
    } else if (value == FORGET_PW_PW_FORMAT_ERROR) {
        std::cout << PASSWORD_FORMAT_ERROR << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(FORGET_PW_AC_FORMAT_ERROR);
            case 1:
                return func(FORGET_ACTIVE_CONFIRM_PW);
        }
    } else if (value == FORGET_PW_PW_MISMATCHED) {
        std::cout << CONFIRM_PASSWORD_MISMATCHED << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(FORGET_PW_AC_FORMAT_ERROR);
            case 1:
                return func(FORGET_ACTIVE_CONFIRM_PW);
        }
    } else if (value == LOGIN_AC_INPUT) {
        std::cout << INPUT_ACCOUNT << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(LOGIN_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);
                switch ((int) Check::check_account_exist(account,
                                                         (code == TEACHER_CODE) ? TEACHER_ACCOUNTS_FILE_PATH
                                                                                : STUDENT_ACCOUNTS_FILE_PATH)) {
                    case 0:
                        return func(LOGIN_AC_NOT_EXIST);
                    case 1:
                        return func(LOGIN_PW_INPUT);
                }
        }
    } else if (value == LOGIN_AC_FORMAT_ERROR) {
        std::cout << ACCOUNT_FORMAT_ERROR << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(LOGIN_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);
                switch ((int) Check::check_account_exist(account,
                                                         (code == TEACHER_CODE) ? TEACHER_ACCOUNTS_FILE_PATH
                                                                                : STUDENT_ACCOUNTS_FILE_PATH)) {
                    case 0:
                        return func(LOGIN_AC_NOT_EXIST);
                    case 1:
                        return func(LOGIN_PW_INPUT);
                }
        }

    } else if (value == LOGIN_AC_NOT_EXIST) {
        std::cout << ACCOUNT_NOT_EXIST << std::endl;
        std::cin >> account;
        switch ((int) Check::check_account_fm(account)) {
            case 0:
                return func(LOGIN_AC_FORMAT_ERROR);
            case 1:
                account = Coding::base64_encode(reinterpret_cast<const unsigned char *>(account.c_str()),
                                                account.length());
                Encryption::caesar(account);
                switch ((int) Check::check_account_exist(account,
                                                         (code == TEACHER_CODE) ? TEACHER_ACCOUNTS_FILE_PATH
                                                                                : STUDENT_ACCOUNTS_FILE_PATH)) {
                    case 0:
                        return func(LOGIN_AC_NOT_EXIST);
                    case 1:
                        return func(LOGIN_PW_INPUT);
                }
        }
    } else if (value == LOGIN_PW_INPUT) {
        std::cout << INPUT_PASSWORD << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(LOGIN_PW_FORMAT_ERROR);
            case 1:
                password = Coding::base64_encode(reinterpret_cast<const unsigned char *>(password.c_str()),
                                                 password.length());
                Encryption::caesar(password);
                switch ((int) Check::match_password(account, password, (code == TEACHER_CODE)
                                                                       ? TEACHER_ACCOUNTS_FILE_PATH
                                                                       : STUDENT_ACCOUNTS_FILE_PATH)) {
                    case 0:
                        return func(LOGIN_PW_MISMATCHED);
                    case 1:
                        Data::token(account, password);
                        return func((code == TEACHER_CODE)
                                    ? TEACHER_LOGIN_SUCCESS
                                    : STUDENT_LOGIN_SUCCESS);
                }
        }
    } else if (value == LOGIN_PW_FORMAT_ERROR) {
        std::cout << PASSWORD_FORMAT_ERROR << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(LOGIN_PW_FORMAT_ERROR);
            case 1:
                password = Coding::base64_encode(reinterpret_cast<const unsigned char *>(password.c_str()),
                                                 password.length());
                Encryption::caesar(password);
                switch ((int) Check::match_password(account, password, (code == TEACHER_CODE)
                                                                       ? TEACHER_ACCOUNTS_FILE_PATH
                                                                       : STUDENT_ACCOUNTS_FILE_PATH)) {
                    case 0:
                        return func(LOGIN_PW_MISMATCHED);
                    case 1:
                        Data::token(account, password);
                        return func((code == TEACHER_CODE)
                                    ? TEACHER_LOGIN_SUCCESS
                                    : STUDENT_LOGIN_SUCCESS);
                }
        }
    } else if (value == LOGIN_PW_MISMATCHED) {
        std::cout << PASSWORD_ERROR << std::endl;
        password = getpass("");
        switch ((int) Check::check_password_fm(password)) {
            case 0:
                return func(LOGIN_PW_FORMAT_ERROR);
            case 1:
                password = Coding::base64_encode(reinterpret_cast<const unsigned char *>(password.c_str()),
                                                 password.length());
                Encryption::caesar(password);
                switch ((int) Check::match_password(account, password, (code == TEACHER_CODE)
                                                                       ? TEACHER_ACCOUNTS_FILE_PATH
                                                                       : STUDENT_ACCOUNTS_FILE_PATH)) {
                    case 0:
                        return func(LOGIN_PW_MISMATCHED);
                    case 1:
                        Data::token(account, password);
                        return func((code == TEACHER_CODE)
                                    ? TEACHER_LOGIN_SUCCESS
                                    : STUDENT_LOGIN_SUCCESS);
                }
        }
    }

}

#undef INITIAL
#undef MISMATCHED

#undef REGISTER_AC_INPUT
#undef REGISTER_AC_FORMAT_ERROR
#undef REGISTER_PW_FORMAT_ERROR
#undef REGISTER_ACTIVE_CONFIRM_PW
#undef REGISTER_PW_INPUT
#undef REGISTER_AC_ALREADY_EXIST
#undef REGISTER_AC_PW_MISMATCHED

#undef FORGET_PW_AC_INPUT
#undef FORGET_PW_AC_FORMAT_ERROR
#undef FORGET_PW_AC_NOT_EXIST
#undef FORGET_PW_CAPTCHA_INPUT
#undef FORGET_PW_PW_INPUT
#undef FORGET_PW_CAPTCHA_ERROR
#undef FORGET_PW_PW_FORMAT_ERROR
#undef FORGET_ACTIVE_CONFIRM_PW
#undef FORGET_PW_PW_MISMATCHED

#undef LOGIN_AC_INPUT
#undef LOGIN_AC_FORMAT_ERROR
#undef LOGIN_AC_NOT_EXIST
#undef LOGIN_PW_INPUT
#undef LOGIN_PW_FORMAT_ERROR
#undef LOGIN_PW_MISMATCHED

#undef TEACHER_REGISTER_SUCCESS
#undef STUDENT_REGISTER_SUCCESS

#undef TEACHER_GET_BACK_PW_SUCCESS
#undef STUDENT_GET_BACK_PW_SUCCESS

#undef TEACHER_LOGIN_SUCCESS
#undef STUDENT_LOGIN_SUCCESS

#undef TEACHER_CODE
#undef STUDENT_CODE

#undef TEACHER_ACCOUNTS_FILE_PATH
#undef STUDENT_ACCOUNTS_FILE_PATH
#undef TEACHER_ACCOUNTS_FILE_TEMP_PATH
#undef STUDENT_ACCOUNTS_FILE_TEMP_PATH

#undef INPUT_YOUR_OPTION
#undef INPUT_OPTION_MISMATCHED
#undef INPUT_ACCOUNT
#undef INPUT_PASSWORD
#undef INPUT_CONFIRM_PASSWORD
#undef INPUT_FORGET_ACCOUNT
#undef INPUT_CAPTCHA_L
#undef INPUT_CAPTCHA_R
#undef INPUT_NEW_PASSWORD
#undef INPUT_CONFIRM_NEW_PASSWORD
#undef ACCOUNT_FORMAT_ERROR
#undef ACCOUNT_ALREADY_EXIST
#undef ACCOUNT_NOT_EXIST
#undef FORGET_ACCOUNT_FORMAT_ERROR
#undef FORGET_ACCOUNT_NOT_EXIST
#undef PASSWORD_FORMAT_ERROR
#undef PASSWORD_ERROR
#undef CONFIRM_PASSWORD_MISMATCHED
#undef CAPTCHA_ERROR_L
#undef CAPTCHA_ERROR_R
