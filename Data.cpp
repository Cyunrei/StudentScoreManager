//
// Created by cyunrei on 2/10/20.
//
/***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Student Score Manager                                        *
 *                                                                                             *
 *                    File Name : Data.cpp                                                     *
 *                                                                                             *
 *                   Programmer : Cyunrei                                                      *
 *                                                                                             *
 *                   Start Date : February 10, 2020                                            *
 *                                                                                             *
 *                  Last Update : July 4, 2020                                                 *
 *                                      Determines                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   Data::init -- Initialize data file                                                        *
 *   Data::write_data --  Write data in file                                                   *
 *   Data::read_line --  Read a specified line of data in the specified file                   *
 *   Data::get_file_line --  Get specified file line count                                     *
 *   Data::change_password --  Change specified account password                               *
 *   Data::token --  Create login token                                                        *
 *   Data::token_decode --  Decode token                                                       *
 *   Data::token_exist --  Check if the token exists                                           *
 *   Data::token_remove --  Remove token                                                       *
 *   Data::student_list --  Get student data account list                                      *
 *   Data::add --  Add student information                                                     *
 *   Data::find --  Search specified student id information                                    *
 *   Data::list --  List all students information                                              *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "Data.h"


#define BASE_DIR "./.data"
#define TOKEN "./.data/token"
#define TEACHER_ACCOUNTS_FILE_PATH "./.data/teacher_accounts.dat"
#define STUDENT_ACCOUNTS_FILE_PATH "./.data/student_accounts.dat"
#define CSV_TEACHER_ACCOUNTS_FILE_PATH "./.data/teacher_accounts.csv"
#define CSV_STUDENT_ACCOUNTS_FILE_PATH "./.data/student_accounts.csv"

#define ID_NOT_FOUND "Not matching ID found"

#define ID  "id"
#define MATH "math"
#define PROGRAM "program"
#define IDEOLOGICAL "ideological"
#define ENGLISH "english"
#define SPORT "sport"
#define SUM "sum"
#define AVERAGE "average"

#define LIST_LOOP for (iterator = stu.begin(); iterator != stu.end(); iterator++)


typedef struct student_information {
    long id{};
    std::string name;
    unsigned int math{};
    unsigned int program{};
    unsigned int ideological{};
    unsigned int english{};
    unsigned int sport{};
    unsigned int sum{};
    double average{};

} student_information;


/***********************************************************************************************
 * Data::init -- Initialize data file                                                          *
 *                                                                                             *
 *    This is function will create teacher and student dat format file if no data file in      *
 *    .data directory.                                                                         *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    02/10/2020 Cyunrei: Created.                                                             *
 *    07/02/2020 Cyunrei: Last Update.                                                         *
 *=============================================================================================*/

void Data::init() {

    std::string dir = BASE_DIR;
    if (access(dir.c_str(), 0) == -1) {
        std::clog << dir << " does not exist" << std::endl;
        std::clog << "Create" << dir << std::endl;
#ifdef WIN32
        int flag=mkdir(dir.c_str());
#endif
#ifdef linux
        int flag = mkdir(dir.c_str(), 0777);
#endif
        if (flag == 0) std::clog << "Create " << dir << " successful" << std::endl;
        else std::clog << "Create " << dir << " failed" << std::endl;

    } else std::clog << dir << " already exist" << std::endl;

    std::fstream _file;
    _file.open(TEACHER_ACCOUNTS_FILE_PATH, std::ios::in);
    if (!_file) _file.open(TEACHER_ACCOUNTS_FILE_PATH, std::fstream::out);
    _file.close();
    _file.open(STUDENT_ACCOUNTS_FILE_PATH, std::ios::in);
    if (!_file) _file.open(STUDENT_ACCOUNTS_FILE_PATH, std::fstream::out);
    _file.close();
    _file.open(CSV_TEACHER_ACCOUNTS_FILE_PATH, std::ios::in);
    if (!_file) _file.open(CSV_TEACHER_ACCOUNTS_FILE_PATH, std::fstream::out);
    _file.close();
    _file.open(CSV_STUDENT_ACCOUNTS_FILE_PATH, std::ios::in);
    if (!_file) _file.open(CSV_STUDENT_ACCOUNTS_FILE_PATH, std::fstream::out);
    _file.close();


}

/***********************************************************************************************
 * Data::write_data --  Write data in file                                                     *
 *                                                                                             *
 *    This is function will write the specified string to the file in the specified directory. *
 *                                                                                             *
 * INPUT:   data -- The string will to be written to the file                                  *
 *          path -- The path that will to written file path                                    *
 *          end -- Determine whether to write a line break                                     *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    02/10/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

void Data::write_data(const std::string &data, const std::string &path, bool end) {

    std::string slice = data;
    slice.append(", ");
    std::ofstream outfile;
    outfile.open(path, std::ios::out | std::ios::app);
    if (end) outfile << slice << std::endl;
    else outfile << slice;
    outfile.close();
}

/***********************************************************************************************
 * Data::read_line --  Read a specified line of data in the specified file                     *
 *                                                                                             *
 *    This is function is used to read a line of string in the specified directory file.       *
 *                                                                                             *
 * INPUT:   data -- The string will to be written to the file                                  *
 *          path -- The path that will to written file path                                    *
 *          end -- Determine whether to write a line break                                     *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    02/10/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

char *Data::read_line(char *filename, int whichLine) {
    if (whichLine < 0 || nullptr == filename) {
        return nullptr;
    }
    FILE *fp = fopen(filename, "r");
    if (nullptr == fp) {
        return nullptr;
    }
    int reachWhichLine = 0;
    int curLine = 1;
#define LINE_SIZE 256
    char *data = nullptr;
    data = (char *) malloc(LINE_SIZE);
    while (!feof(fp)) {
        memset(data, 0, LINE_SIZE);
        fgets(data, LINE_SIZE - 1, fp);
        curLine++;
        if (curLine > whichLine) {
            reachWhichLine = 1;
            break;
        }
    }
    fclose(fp);

    return 0 == reachWhichLine ? nullptr : data;
}

/***********************************************************************************************
 * Data::get_file_line --  Get specified file line count                                       *
 *                                                                                             *
 *    This is function is used to statistics line count in the specified directory file.       *
 *                                                                                             *
 * INPUT:   path -- The path that will statistics line file path                               *
 *                                                                                             *
 * OUTPUT:  Returns the file line count.                                                       *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    02/10/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

int Data::get_file_line(const std::string &file_path) {

    std::fstream fin(file_path, std::ios::in);
    if (!fin) {
        std::cerr << "Get File Line: can not open file" << std::endl;
        exit(-1);
    }
    char c;
    int lineCnt = 1;
    while (fin.get(c)) {
        if (c == '\n') lineCnt++;
    }
    fin.close();
    return lineCnt;

}

/***********************************************************************************************
 * Data::change_password --  Change specified account password                                 *
 *                                                                                             *
 *    This is function is used to change specified account password in specified data path.    *
 *                                                                                             *
 * INPUT:   account -- Target account                                                          *
 *          password -- Changed password                                                       *
 *          file_path -- Specified data path                                                   *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    02/10/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

void Data::change_password(const std::string &account, const std::string &password, const std::string &file_path) {

    static int line = 0;
    for (int i = 1; i < Data::get_file_line(file_path); i++) {
        std::string line_data = Data::read_line((char *) file_path.c_str(), i);
        if (account == line_data.substr(0, account.length()) && line_data[account.length() + 1] == ' ') {
            line = i;
            break;
        }
    }
    std::fstream file;
    file.open(file_path, std::ios::in);
    std::string data_1;
    std::string data_2;
    std::string temp_1;
    std::string temp_2;
    for (int i = 1; !file.eof(); i++) {

        if (i >= line) {
            getline(file, temp_2);
            data_2.append(temp_2);
            data_2.append("\n");
        } else {
            getline(file, temp_1);
            data_1.append(temp_1);
            data_1.append("\n");
        }
    }
    unsigned short int index = 0;
    for (int i = 0, cnt = 0; i < data_2.length(); i++) {
        if (data_2[i] == ',' && data_2[i + 1] == ' ') cnt++;
        if (cnt == 2) {
            index = ++i;
            break;
        }
    }
    file.close();
    file.open(file_path, std::ios::out);
    file << data_1;
    file << account << ", ";
    file << password << ", ";
    file << data_2.substr(index);
    file.close();
}

/***********************************************************************************************
 * Data::token --  Create login token                                                          *
 *                                                                                             *
 *    This is function is used to create login token                                           *
 *    Method:Obtain the system time, perform the arithmetic square root number residue to      *
 *    obtain the Caesar offset, encrypt the acquisition time by default Caesar and then Base64 *
 *    encode it, and connect it with the obtained offset Caesar and then Base64 incoming       *
 *    account and password string  Write token.                                                *
 *                                                                                             *
 * INPUT:   account -- login account                                                           *
 *          password -- login password                                                         *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The login account and password is a encrypt string as the parameter.            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    06/30/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

void Data::token(const std::string &account, const std::string &password) {
    std::time_t t = std::time(nullptr);
    std::fstream file;
    file.open(TOKEN, std::ios::out);
    std::string t_str = std::to_string(t);
    Encryption::caesar(t_str);
    std::string data_1 = Coding::base64_encode(reinterpret_cast<const unsigned char *>(t_str.c_str()),
                                               t_str.length());
    t = (int) sqrt(t);
    t %= 10;
    std::string data_2 = account + ", " + password;
    Encryption::caesar(data_2, t);
    file << data_1 + Coding::base64_encode(reinterpret_cast<const unsigned char *>(data_2.c_str()),
                                           data_2.length());
    file.close();
}

/***********************************************************************************************
 * Data::token_decode --  Decode token                                                         *
 *                                                                                             *
 *    This is function is used to decode token.                                                *
 *    Method:Data::token reverse operation.                                                    *
 *                                                                                             *
 * INPUT:   account -- none                                                                    *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The login account and password in token need to second decrypt.                 *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    06/30/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

std::string Data::token_decode() {
    std::fstream file;
    file.open(TOKEN, std::ios::in);
    std::string token;
    file >> token;
    std::string time = token.substr(0, 15);
    std::string data = token.substr(16, token.length() - 1);
    time = Coding::base64_decode(time);
    Encryption::caesar(time, -8);
    int t = atoi(time.c_str());
    t = (int) sqrt(t);
    t %= 10;
    t = ~t + 1;
    data = Coding::base64_decode(data);
    Encryption::caesar(data, t);
    std::string ac = data.substr(0, data.find(", "));
    Encryption::caesar(ac, -8);
    ac = Coding::base64_decode(ac);
    return ac;
}

/***********************************************************************************************
 * Data::token_exist --  Check if the token exists                                             *
 *                                                                                             *
 *    This is function is used to check if the token exists.                                   *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Return a bool value exists(1)  or (0)                                              *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    06/30/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

bool Data::token_exist() {
    std::ifstream fin(TOKEN);
    return !!fin;
}

/***********************************************************************************************
 * Data::token_remove --  Remove token                                                         *
 *                                                                                             *
 *    This is function is used to remove token.                                                *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    06/30/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

void Data::token_remove() {
    remove(TOKEN);
}

/***********************************************************************************************
 * Data::student_list --  Get student data account list                                        *
 *                                                                                             *
 *    This is function is used to get student data account list.                               *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Return the student account array(list)                                             *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    06/30/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

int *Data::student_list() {

    int line = Data::get_file_line(STUDENT_ACCOUNTS_FILE_PATH) - 1;
    int *list = new int[line];
    length = line;
    for (int i = 0; i < line; i++) {
        std::string data = Data::read_line(STUDENT_ACCOUNTS_FILE_PATH, i + 1);
        std::string ac = data.substr(0, data.find(", "));
        Encryption::caesar(ac, -8);
        ac = Coding::base64_decode(ac);
        list[i] = atoi(ac.c_str());
    }

    return list;

}

/***********************************************************************************************
 * Data::add --  Add student information                                                       *
 *                                                                                             *
 *    This is function is used to add student information to student csv file.                 *
 *                                                                                             *
 * INPUT:   data -- The string that will add in csv file                                       *
 *                                                                                             *
 * OUTPUT:  Return the add status (0 Add failed / 1 Add success)                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    06/30/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

int Data::add(const std::string &data) {

    std::string data_id = data.substr(0, data.find(", "));
    std::string id;
    std::ifstream file(CSV_STUDENT_ACCOUNTS_FILE_PATH);
    if (file.is_open())
        while (std::getline(file, id)) {
            if (id.substr(0, id.find(", ")) == data_id) return 0;
        }
    file.close();
    std::fstream outfile;
    outfile.open(CSV_STUDENT_ACCOUNTS_FILE_PATH, std::ios::out | std::ios::app);
    outfile << data << std::endl;
    outfile.close();
    return 1;
}

/***********************************************************************************************
 * Data::list --  List all students information                                                *
 *                                                                                             *
 *    This is function is used to list all students information in student csv file.           *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   This is a command line function.                                                *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    07/03/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

void Data::list() {
//    std::ifstream file(CSV_STUDENT_ACCOUNTS_FILE_PATH);
//    std::string line;
//    if (file.is_open())
//        while (std::getline(file, line)) {
//            std::cout << line << std::endl;
//        }
    Data::sort(ID);

}

/***********************************************************************************************
 * Data::find --  Search specified student id information                                    *
 *                                                                                             *
 *    This is function is used to find specified student id information in student csv file. *
 *                                                                                             *
 * INPUT:   id -- The id that will find in csv file                                          *
 *                                                                                             *
 * OUTPUT:  Return the matched student id that line data(information).                         *
 *                                                                                             *
 * WARNINGS:   This is a command line function.                                                *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    07/03/2020 Cyunrei: Created.                                                             *
 *=============================================================================================*/

inline int value_slice(std::string &line) {
    int value = atoi(line.substr(0, line.find(", ")).c_str());
    line = line.substr(line.find(", ") + 2);
    return value;
}

void Data::find(const std::string &id) {
    std::string line;
    std::ifstream file(CSV_STUDENT_ACCOUNTS_FILE_PATH);
    int flag = 0;
    if (file.is_open())
        while (std::getline(file, line)) {
            if (line.substr(0, line.find(", ")) == id) {
                std::cout << "Find a match information:" << std::endl;
                flag = 1;
                std::string str(84, '-');
                std::cout << str << std::endl;
                std::cout << setiosflags(std::ios::left) << std::setw(8) << "ID" << resetiosflags(std::ios::left)
                          << setiosflags(std::ios::right) << std::setw(8) << "NAME" << std::setw(8) << "MATH"
                          << setiosflags(std::ios::right) << std::setw(10) << "PROGRAM" << std::setw(14)
                          << "IDEOLOGICAL"
                          << setiosflags(std::ios::right) << std::setw(10) << "ENGLISH" << std::setw(9) << "SPORT"
                          << setiosflags(std::ios::right) << std::setw(7) << "SUM" << std::setw(10) << "AVERAGE"
                          << resetiosflags(std::ios::right) << std::endl;
                std::cout << str << std::endl;
                std::cout << setiosflags(std::ios::left) << std::setw(8) << value_slice(line)
                          << resetiosflags(std::ios::left)
                          << setiosflags(std::ios::right) << std::setw(8) << line.substr(0, line.find(", ")) << std::setw(8);
                line = line.substr(line.find(", ") + 2);
                std::cout << value_slice(line)
                          << setiosflags(std::ios::right) << std::setw(10) << value_slice(line) << std::setw(14)
                          << value_slice(line)
                          << setiosflags(std::ios::right) << std::setw(10) << value_slice(line)<< std::setw(9)
                          << value_slice(line)
                          << setiosflags(std::ios::right) << std::setw(7) << value_slice(line) << std::setw(10)
                          << value_slice(line)
                          << resetiosflags(std::ios::right) << std::endl;
                std::cout << str << std::endl;
                break;
            }
        }
    file.close();
    if (flag == 1) return;
    std::cout << ID_NOT_FOUND << std::endl;
}



bool compare_id(student_information &s1, student_information &s2) {
    if (s1.id == s2.id) {
        return s1.id > s2.id;
    } else {
        return s1.id < s2.id;
    }
}

bool compare_math(student_information &s1, student_information &s2) {
    if (s1.math == s2.math) {
        return s1.math < s2.math;
    } else {
        return s1.math > s2.math;
    }
}

bool compare_program(student_information &s1, student_information &s2) {
    if (s1.program == s2.program) {
        return s1.program < s2.program;
    } else {
        return s1.program > s2.program;
    }
}

bool compare_ideological(student_information &s1, student_information &s2) {
    if (s1.ideological == s2.ideological) {
        return s1.ideological < s2.ideological;
    } else {
        return s1.ideological > s2.ideological;
    }
}

bool compare_english(student_information &s1, student_information &s2) {
    if (s1.english == s2.english) {
        return s1.english < s2.english;
    } else {
        return s1.english > s2.english;
    }
}

bool compare_sport(student_information &s1, student_information &s2) {
    if (s1.sport == s2.sport) {
        return s1.sport < s2.sport;
    } else {
        return s1.sport > s2.sport;
    }
}

bool compare_sum(student_information &s1, student_information &s2) {
    if (s1.sum == s2.sum) {
        return s1.sum < s2.sum;
    } else {
        return s1.sum > s2.sum;
    }
}

bool compare_average(student_information &s1, student_information &s2) {
    if (s1.average == s2.average) {
        return s1.average < s2.average;
    } else {
        return s1.average > s2.average;
    }
}

template<typename T>
bool compare(student_information &s1, student_information &s2) {
    //TODO
}

void Data::sort(const std::string &flag) {
    std::list<student_information> stu;
    std::ifstream file(CSV_STUDENT_ACCOUNTS_FILE_PATH);
    std::string line;
    if (file.is_open())
        while (std::getline(file, line)) {
            student_information stu_info;
            stu_info.id = value_slice(line);
            stu_info.name = line.substr(0, line.find(", "));
            line = line.substr(line.find(", ") + 2);
            stu_info.math = value_slice(line);
            stu_info.program = value_slice(line);
            stu_info.ideological = value_slice(line);
            stu_info.english = value_slice(line);
            stu_info.sport = value_slice(line);
            stu_info.sum =
                    stu_info.math + stu_info.program + stu_info.ideological + stu_info.english + stu_info.sport;
            stu_info.average = stu_info.sum / 5.0;
            stu.push_back(stu_info);
        }
    file.close();
    std::list<student_information>::iterator iterator;
    if (flag == ID) LIST_LOOP stu.sort(compare_id);
    else if (flag == MATH) LIST_LOOP stu.sort(compare_math);
    else if (flag == PROGRAM) LIST_LOOP stu.sort(compare_program);
    else if (flag == IDEOLOGICAL) LIST_LOOP stu.sort(compare_ideological);
    else if (flag == ENGLISH) LIST_LOOP stu.sort(compare_english);
    else if (flag == SPORT) LIST_LOOP stu.sort(compare_sport);
    else if (flag == SUM) LIST_LOOP stu.sort(compare_sum);
    else if (flag == AVERAGE) LIST_LOOP stu.sort(compare_average);
    else {
        std::cout << "Arguments Error" << std::endl;
    }
    std::string str(84, '-');
    std::cout << str << std::endl;
    std::cout << setiosflags(std::ios::left) << std::setw(8) << "ID" << resetiosflags(std::ios::left)
              << setiosflags(std::ios::right) << std::setw(8) << "NAME" << std::setw(8) << "MATH"
              << setiosflags(std::ios::right) << std::setw(10) << "PROGRAM" << std::setw(14) << "IDEOLOGICAL"
              << setiosflags(std::ios::right) << std::setw(10) << "ENGLISH" << std::setw(9) << "SPORT"
              << setiosflags(std::ios::right) << std::setw(7) << "SUM" << std::setw(10) << "AVERAGE"
              << resetiosflags(std::ios::right) << std::endl;
    std::cout << str << std::endl;
    LIST_LOOP {
        std::cout << setiosflags(std::ios::left) << std::setw(8) << (*iterator).id << resetiosflags(std::ios::left)
                  << setiosflags(std::ios::right) << std::setw(8) << (*iterator).name << std::setw(8)
                  << (*iterator).math
                  << setiosflags(std::ios::right) << std::setw(10) << (*iterator).program << std::setw(14)
                  << (*iterator).ideological
                  << setiosflags(std::ios::right) << std::setw(10) << (*iterator).english << std::setw(9)
                  << (*iterator).sport
                  << setiosflags(std::ios::right) << std::setw(7) << (*iterator).sum << std::setw(10)
                  << (*iterator).average
                  << resetiosflags(std::ios::right) << std::endl;
    }
    std::cout << str << std::endl;
}

void Data::remove(const std::string &id) {
    std::list<student_information> stu;
    std::ifstream file(CSV_STUDENT_ACCOUNTS_FILE_PATH);
    std::string line;
    if (file.is_open())
        while (std::getline(file, line)) {
            student_information stu_info;
            stu_info.id = value_slice(line);
            stu_info.name = line.substr(0, line.find(", "));
            line = line.substr(line.find(", ") + 2);
            stu_info.math = value_slice(line);
            stu_info.program = value_slice(line);
            stu_info.ideological = value_slice(line);
            stu_info.english = value_slice(line);
            stu_info.sport = value_slice(line);
            stu_info.sum =
                    stu_info.math + stu_info.program + stu_info.ideological + stu_info.english + stu_info.sport;
            stu_info.average = stu_info.sum / 5.0;
            if (stu_info.id == atoi(id.c_str())) {
                std::cout << "Find a match information:" << std::endl;
                std::string str(84, '-');
                std::cout << str << std::endl;
                std::cout << setiosflags(std::ios::left) << std::setw(8) << "ID" << resetiosflags(std::ios::left)
                          << setiosflags(std::ios::right) << std::setw(8) << "NAME" << std::setw(8) << "MATH"
                          << setiosflags(std::ios::right) << std::setw(10) << "PROGRAM" << std::setw(14)
                          << "IDEOLOGICAL"
                          << setiosflags(std::ios::right) << std::setw(10) << "ENGLISH" << std::setw(9) << "SPORT"
                          << setiosflags(std::ios::right) << std::setw(7) << "SUM" << std::setw(10) << "AVERAGE"
                          << resetiosflags(std::ios::right) << std::endl;
                std::cout << str << std::endl;
                std::cout << setiosflags(std::ios::left) << std::setw(8) << stu_info.id
                          << resetiosflags(std::ios::left)
                          << setiosflags(std::ios::right) << std::setw(8) << stu_info.name << std::setw(8)
                          << stu_info.math
                          << setiosflags(std::ios::right) << std::setw(10) << stu_info.program << std::setw(14)
                          << stu_info.ideological
                          << setiosflags(std::ios::right) << std::setw(10) << stu_info.english << std::setw(9)
                          << stu_info.sport
                          << setiosflags(std::ios::right) << std::setw(7) << stu_info.sum << std::setw(10)
                          << stu_info.average
                          << resetiosflags(std::ios::right) << std::endl;
                std::cout << str << std::endl;
                std::cout << "Are you sure to remove it?(y/n)" << std::endl;
                char flag;
                std::cin >> flag;
                if (flag == 'Y' || flag == 'y') continue;
                else {
                    std::cout << "Operation canceled." << std::endl;
                    return;
                }
            }
            stu.push_back(stu_info);
        }
    file.close();
    std::ofstream rewrite(CSV_STUDENT_ACCOUNTS_FILE_PATH, std::ios::trunc);
    std::list<student_information>::iterator iterator;
    LIST_LOOP {
        std::string str;
        str.append(std::to_string((*iterator).id) + ", ");
        str.append((*iterator).name + ", ");
        str.append(std::to_string((*iterator).math) + ", ");
        str.append(std::to_string((*iterator).program) + ", ");
        str.append(std::to_string((*iterator).ideological) + ", ");
        str.append(std::to_string((*iterator).english) + ", ");
        str.append(std::to_string((*iterator).sport) + ", ");
        str.append(std::to_string((*iterator).sum) + ", ");
        str.append(std::to_string((*iterator).average) + "\n");
        rewrite << str;
    }
    std::cout << "Remove successful!" << std::endl;
}

void Data::modify(const std::string &id, const std::string &lesson, const std::string &score){
        std::cout<<"123"<<std::endl;
}