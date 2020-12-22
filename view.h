//
// Created by cyunrei on 2/11/20.
//

#ifndef STUDENTSCOREMANAGER_VIEW_H
#define STUDENTSCOREMANAGER_VIEW_H

#include "Data.h"
#include "Layout.h"
#include "Check.h"

#define INITIAL 0
#define MISMATCHED 1

#define REGISTER_AC_INPUT -1
#define FORGET_PW_AC_INPUT -8
#define LOGIN_AC_INPUT -17

#define TEACHER_CODE 100
#define STUDENT_CODE 101

#define TEACHER_REGISTER_SUCCESS 200
#define STUDENT_REGISTER_SUCCESS 201

#define TEACHER_GET_BACK_PW_SUCCESS 300
#define STUDENT_GET_BACK_PW_SUCCESS 301

#define TEACHER_LOGIN_SUCCESS 400
#define STUDENT_LOGIN_SUCCESS 401

#define STRING_STUDENT_SCORE_MANAGER "学生成绩管理系统"
#define STRING_MAIN_PAGE "首页"
#define STRING_TEACHER_LOGIN "教师登录"
#define STRING_STUDENT_LOGIN "学生登录"
#define STRING_REGISTER_ACCOUNT "注册账号"
#define STRING_FORGET_PASSWORD "忘记密码"
#define STRING_EXIT_PROGRAM "退出程序"
#define STRING_INPUT_ACCOUNT "请输入账号"
#define STRING_LOGIN_TIP "登陆提示"
#define STRING_ACCOUNT_TIP "账号:6-12位数字"
#define STRING_PASSWORD_TIP "密码:6-18位数字字母混合"
#define STRING_RETURN "返回上一级"
#define STRING_NEXT "进行下一步"
#define STRING_ACCOUNT_LOGIN_SUCCESS "登录成功！"
#define STRING_RETURN_MAIN_PAGE "返回首页"
#define STRING_SELECT_REGISTER_OBJECT "请选择注册对象"
#define STRING_TEACHER "教师"
#define STRING_STUDENT "学生"
#define STRING_TEACHER_REGISTER "教师注册"
#define STRING_REGISTER_TIP "注册提示"
#define STRING_STUDENT_REGISTER "学生注册"
#define STRING_REGISTER_SUCCESS "注册成功"
#define STRING_SELECT_FORGET_PASSWORD_OBJECT "请选择忘记密码对象"
#define STRING_TEACHER_GET_BACK_PASSWORD "教师找回密码"
#define STRING_GET_BACK_PASSWORD_TIP "找回提示"
#define STRING_GET_BACK_PASSWORD_SUCCESS "找回密码成功！"
#define STRING_STUDENT_GET_BACK_PASSWORD "学生找回密码"
#define STRING_QUEST_EXIT_PROGRAM "是否退出程序?"
#define STRING_YES "是"
#define STRING_NO "否"

Layout layout;

void welcome(int);

void teacher_login_id(int);

void teacher_login_success(int);

void student_login_success(int);

void student_login_id(int);

void register_select(int);

void teacher_register(int);

void teacher_register_success(int);

void student_register(int);

void student_register_success(int);

void forget_pw(int);

void teacher_forget_pw(int);

void teacher_get_back_pw_success(int);

void student_forget_pw(int);

void student_get_back_pw_success(int);

void welcome_exit(int);

void home(int);

void list_student(int value);

void home_logout(int);

void welcome(int value) {

    std::string title_top = STRING_STUDENT_SCORE_MANAGER;
    std::vector<std::string> context = {STRING_TEACHER_LOGIN, STRING_STUDENT_LOGIN, STRING_REGISTER_ACCOUNT,
                                        STRING_FORGET_PASSWORD,
                                        STRING_EXIT_PROGRAM};
    std::string title_bottom = STRING_MAIN_PAGE;

    if (Data::token_exist()) {
        home(0);
        return;
    }

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, welcome);


    switch (Check::input()) {
        case 1:
            return teacher_login_id(INITIAL);
        case 2:
            return student_login_id(INITIAL);
        case 3:
            return register_select(INITIAL);
        case 4:
            return forget_pw(INITIAL);
        case 5:
            return welcome_exit(INITIAL);
        default:
            return welcome(MISMATCHED);
    }

}

void teacher_login_id(int value) {

    if (value == TEACHER_LOGIN_SUCCESS) return teacher_login_success(INITIAL);

    std::string title_top = STRING_INPUT_ACCOUNT;
    std::vector<std::string> context = {STRING_LOGIN_TIP, STRING_ACCOUNT_TIP, STRING_PASSWORD_TIP};
    std::string title_button_1 = STRING_RETURN;
    std::string title_button_2 = STRING_NEXT;
    std::string title_bottom = STRING_TEACHER_LOGIN;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1, title_button_2, 2, value);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, teacher_login_id, TEACHER_CODE);
    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        case 2:
            return teacher_login_id(LOGIN_AC_INPUT);
        default:
            return teacher_login_id(MISMATCHED);
    }
}

void teacher_login_success(int value) {

    std::string title_top = STRING_TEACHER_LOGIN;
    std::vector<std::string> context = {STRING_ACCOUNT_LOGIN_SUCCESS};
    std::string title_button_1 = STRING_RETURN_MAIN_PAGE;
    std::string title_bottom = STRING_TEACHER_LOGIN;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, teacher_login_success);

    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        default:
            return teacher_login_success(MISMATCHED);
    }
}

void student_login_id(int value) {

    if (value == STUDENT_LOGIN_SUCCESS) return student_login_success(INITIAL);

    std::string title_top = STRING_INPUT_ACCOUNT;
    std::vector<std::string> context = {STRING_LOGIN_TIP, STRING_ACCOUNT_TIP, STRING_PASSWORD_TIP};
    std::string title_button_1 = STRING_RETURN;
    std::string title_button_2 = STRING_NEXT;
    std::string title_bottom = STRING_STUDENT_LOGIN;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1, title_button_2, 2, value);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, student_login_id, STUDENT_CODE);
    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        case 2:
            return student_login_id(LOGIN_AC_INPUT);
        default:
            return student_login_id(MISMATCHED);
    }
}

void student_login_success(int value) {

    std::string title_top = STRING_STUDENT_LOGIN;
    std::vector<std::string> context = {STRING_ACCOUNT_LOGIN_SUCCESS};
    std::string title_button_1 = STRING_RETURN_MAIN_PAGE;
    std::string title_bottom = STRING_STUDENT_LOGIN;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, student_login_success);

    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        default:
            return student_login_success(MISMATCHED);
    }
}

void register_select(int value) {

    std::string title_top = STRING_SELECT_REGISTER_OBJECT;
    std::vector<std::string> context = {STRING_TEACHER, STRING_STUDENT};
    std::string title_button = STRING_RETURN;
    std::string title_bottom = STRING_REGISTER_ACCOUNT;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1);
    Layout::page_button(title_button, 3);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, register_select);

    switch (Check::input()) {
        case 1:
            return teacher_register(INITIAL);
        case 2:
            return student_register(INITIAL);
        case 3:
            return welcome(INITIAL);
        default:
            return register_select(MISMATCHED);
    }
}

void teacher_register(int value) {

    if (value == TEACHER_REGISTER_SUCCESS) return teacher_register_success(INITIAL);
    std::string title_top = STRING_TEACHER_REGISTER;
    std::vector<std::string> context = {STRING_REGISTER_TIP, STRING_ACCOUNT_TIP, STRING_PASSWORD_TIP};
    std::string title_button_1 = STRING_RETURN;
    std::string title_button_2 = STRING_NEXT;
    std::string title_bottom = STRING_REGISTER_ACCOUNT;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1, title_button_2, 2, value);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, teacher_register, TEACHER_CODE);

    switch (Check::input()) {
        case 1:
            return register_select(INITIAL);
        case 2:
            return teacher_register(REGISTER_AC_INPUT);
        default:
            return teacher_register(MISMATCHED);
    }
}

void teacher_register_success(int value) {
    std::string title_top = STRING_TEACHER_REGISTER;
    std::vector<std::string> context = {STRING_REGISTER_SUCCESS};
    std::string title_button_1 = STRING_RETURN_MAIN_PAGE;
    std::string title_bottom = STRING_REGISTER_ACCOUNT;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, teacher_register_success);

    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        default:
            return teacher_register_success(MISMATCHED);
    }
}

void student_register(int value) {

    if (value == STUDENT_REGISTER_SUCCESS) return student_register_success(INITIAL);

    std::string title_top = STRING_STUDENT_REGISTER;
    std::vector<std::string> context = {STRING_REGISTER_TIP, STRING_ACCOUNT_TIP, STRING_PASSWORD_TIP};
    std::string title_button_1 = STRING_RETURN;
    std::string title_button_2 = STRING_NEXT;
    std::string title_bottom = STRING_REGISTER_ACCOUNT;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1);
    Layout::page_button(title_button_1, 1, title_button_2, 2, value);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, student_register, STUDENT_CODE);

    switch (Check::input()) {
        case 1:
            return register_select(INITIAL);
        case 2:
            return student_register(REGISTER_AC_INPUT);
        default:
            return student_register(MISMATCHED);
    }
}

void student_register_success(int value) {
    std::string title_top = STRING_STUDENT_REGISTER;
    std::vector<std::string> context = {STRING_REGISTER_SUCCESS};
    std::string title_button_1 = STRING_RETURN_MAIN_PAGE;
    std::string title_bottom = STRING_REGISTER_ACCOUNT;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, student_register_success);

    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        default:
            return student_register_success(MISMATCHED);
    }
}

void forget_pw(int value) {

    std::string title_top = STRING_SELECT_FORGET_PASSWORD_OBJECT;
    std::vector<std::string> context = {STRING_TEACHER, STRING_STUDENT};
    std::string title_button = STRING_RETURN;
    std::string title_bottom = STRING_FORGET_PASSWORD;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1);
    Layout::page_button(title_button, 3);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, forget_pw);

    switch (Check::input()) {
        case 1:
            return teacher_forget_pw(INITIAL);
        case 2:
            return student_forget_pw(INITIAL);
        case 3:
            return welcome(INITIAL);
        default:
            return forget_pw(MISMATCHED);
    }
}

void teacher_forget_pw(int value) {

    if (value == TEACHER_GET_BACK_PW_SUCCESS) {
        return teacher_get_back_pw_success(INITIAL);
    }
    std::string title_top = STRING_TEACHER_GET_BACK_PASSWORD;
    std::vector<std::string> context = {STRING_GET_BACK_PASSWORD_TIP, STRING_ACCOUNT_TIP, STRING_PASSWORD_TIP};
    std::string title_button_1 = STRING_RETURN;
    std::string title_button_2 = STRING_NEXT;
    std::string title_bottom = STRING_FORGET_PASSWORD;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1, title_button_2, 2, value);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, teacher_forget_pw, TEACHER_CODE);

    switch (Check::input()) {
        case 1:
            return forget_pw(INITIAL);
        case 2:
            return teacher_forget_pw(FORGET_PW_AC_INPUT);
        default:
            return teacher_forget_pw(MISMATCHED);
    }
}

void teacher_get_back_pw_success(int value) {

    std::string title_top = STRING_TEACHER_GET_BACK_PASSWORD;
    std::vector<std::string> context = {STRING_GET_BACK_PASSWORD_SUCCESS};
    std::string title_button_1 = STRING_RETURN_MAIN_PAGE;
    std::string title_bottom = STRING_FORGET_PASSWORD;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, teacher_get_back_pw_success);

    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        default:
            return teacher_get_back_pw_success(MISMATCHED);
    }
}

void student_forget_pw(int value) {


    if (value == STUDENT_GET_BACK_PW_SUCCESS) {
        return student_get_back_pw_success(INITIAL);
    }
    std::string title_top = STRING_STUDENT_GET_BACK_PASSWORD;
    std::vector<std::string> context = {STRING_GET_BACK_PASSWORD_TIP, STRING_ACCOUNT_TIP, STRING_PASSWORD_TIP};
    std::string title_button_1 = STRING_RETURN;
    std::string title_button_2 = STRING_NEXT;
    std::string title_bottom = STRING_FORGET_PASSWORD;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1, title_button_2, 2, value);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, student_forget_pw, STUDENT_CODE);

    switch (Check::input()) {
        case 1:
            return forget_pw(INITIAL);
        case 2:
            return student_forget_pw(FORGET_PW_AC_INPUT);
        default:
            return student_forget_pw(MISMATCHED);
    }
}

void student_get_back_pw_success(int value) {
    std::string title_top = STRING_STUDENT_GET_BACK_PASSWORD;
    std::vector<std::string> context = {STRING_GET_BACK_PASSWORD_SUCCESS};
    std::string title_button_1 = STRING_MAIN_PAGE;
    std::string title_bottom = STRING_FORGET_PASSWORD;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context, -1, true);
    Layout::page_button(title_button_1, 1);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, student_get_back_pw_success);

    switch (Check::input()) {
        case 1:
            return welcome(INITIAL);
        default:
            return student_get_back_pw_success(MISMATCHED);
    }
}

void welcome_exit(int value) {

    std::string title_top = STRING_QUEST_EXIT_PROGRAM;
    std::vector<std::string> context = {STRING_YES, STRING_NO};
    std::string title_bottom = STRING_EXIT_PROGRAM;

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, welcome_exit);

    switch (Check::input()) {
        case 1:
            Layout::clear();
            exit(0);
        case 2:
            return welcome(INITIAL);
        default:
            return welcome_exit(MISMATCHED);
    }
}

void home(int value) {

    std::string title_top = "欢迎: " + Data::token_decode();
    std::vector<std::string> context = {"查看学生", "查找学生", "退出程序","退出登陆",};
    std::string title_bottom = "主页";

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, welcome);


    switch (Check::input()) {
        case 1:
            return list_student(INITIAL);
        case 2:
            return student_login_id(INITIAL);
        case 3:
            return welcome_exit(INITIAL);
        case 4:
            return home_logout(INITIAL);
        default:
            return home(MISMATCHED);
    }


}

void list_student(int value){

    Data data;
    std::string title_top = "学生列表";
    std::string title_bottom = "查看学生";
    int *list = data.student_list();
    std::vector<std::string> context(data.length) ;
    for(int i = 0;i<data.length;i++){
       context[i]=std::to_string(list[i]);
    }
    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context);
    Layout::page_bottom(title_bottom);
    Layout::page_button("返回主页", -1, "排序方式", -2, value);
    Layout::tip(value, list_student);
    delete list;
    switch (Check::_input()) {
        case -1:
            return home(INITIAL);
        default:
            return list_student(MISMATCHED);
    }
}

void home_logout(int value) {
    std::string title_top = "是否退出登陆";
    std::vector<std::string> context = {STRING_YES, STRING_NO};
    std::string title_bottom = "退出登录";

    Layout::clear();
    Layout::page_top(title_top);
    layout.page_context(context);
    Layout::page_bottom(title_bottom);
    Layout::tip(value, home_logout);

    switch (Check::input()) {
        case 1:
            Data::token_remove();
            welcome(0);
        case 2:
            return home(INITIAL);
        default:
            return home_logout(MISMATCHED);
    }
}

#undef INITIAL
#undef MISMATCHED

#undef REGISTER_AC_INPUT
#undef FORGET_PW_AC_INPUT

#undef TEACHER_CODE
#undef STUDENT_CODE

#undef TEACHER_REGISTER_SUCCESS
#undef STUDENT_REGISTER_SUCCESS

#undef TEACHER_GET_BACK_PW_SUCCESS
#undef STUDENT_GET_BACK_PW_SUCCESS

#undef TEACHER_LOGIN_SUCCESS
#undef STUDENT_LOGIN_SUCCESS

#undef STRING_STUDENT_SCORE_MANAGER
#undef STRING_MAIN_PAGE
#undef STRING_TEACHER_LOGIN
#undef STRING_STUDENT_LOGIN
#undef STRING_REGISTER_ACCOUNT
#undef STRING_FORGET_PASSWORD
#undef STRING_EXIT_PROGRAM
#undef STRING_INPUT_ACCOUNT
#undef STRING_LOGIN_TIP
#undef STRING_ACCOUNT_TIP
#undef STRING_PASSWORD_TIP
#undef STRING_RETURN
#undef STRING_NEXT
#undef STRING_ACCOUNT_LOGIN_SUCCESS
#undef STRING_RETURN_MAIN_PAGE
#undef STRING_SELECT_REGISTER_OBJECT
#undef STRING_TEACHER
#undef STRING_STUDENT
#undef STRING_TEACHER_REGISTER
#undef STRING_REGISTER_TIP
#undef STRING_STUDENT_REGISTER
#undef STRING_REGISTER_SUCCESS
#undef STRING_SELECT_FORGET_PASSWORD_OBJECT
#undef STRING_TEACHER_GET_BACK_PASSWORD
#undef STRING_GET_BACK_PASSWORD_TIP
#undef STRING_GET_BACK_PASSWORD_SUCCESS
#undef STRING_STUDENT_GET_BACK_PASSWORD
#undef STRING_QUEST_EXIT_PROGRAM
#undef STRING_YES
#undef STRING_NO

#endif //STUDENTSCOREMANAGER_VIEW_H
