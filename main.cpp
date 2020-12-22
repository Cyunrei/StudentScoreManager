#include <getopt.h>
#include <cstdlib>
#include "view.h"

#define VERSION "0.0.1"

#define PLATFORM "linux"
#ifdef win32
#define PLATFORM "win32"
#endif

#define ADD (std::string) argv[2] + ", " + argv[3] + ", " + argv[4] + ", " + argv[5] + ", " + argv[6] + ", " + argv[7] + ", " + argv[8]


int main(int argc, char *argv[]) {

    std::string logo = " ____  _             _            _     ____                     \n"\
                       "/ ___|| |_ _   _  __| | ___ _ __ | |_  / ___|  ___ ___  _ __ ___ \n"\
                       "\\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| \\___ \\ / __/ _ \\| '__/ _ \\\n"\
                       " ___) | |_| |_| | (_| |  __/ | | | |_   ___) | (_| (_) | | |  __/\n"\
                       "|____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| |____/ \\___\\___/|_|  \\___|" +
                       (std::string) "\tLanguage: en-US"\
                       "                                                                 \n"\
                       " __  __                                   \t\t\t\tProgramed by: cyunrei\n"\
                       "|  \\/  | __ _ _ __   __ _  __ _  ___ _ __ \n"\
                       "| |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|\t\t\t\t" + (std::string) VERSION + " base on " +
                       PLATFORM + "\n"\
                       "| |  | | (_| | | | | (_| | (_| |  __/ |   \n"\
                       "|_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|   \t\t\t<compile date: " + (std::string) __DATE__ +
                       ' ' + __TIME__ + ">\n"\
                       "                          |___/           ";

    std::string sum = std::to_string((atoi(argv[4]) + atoi(argv[5]) + atoi(argv[6]) + atoi(argv[7]) + atoi(argv[8])));
    std::string average = std::to_string((atoi(argv[4]) + atoi(argv[5]) + atoi(argv[6]) + atoi(argv[7]) + atoi(argv[8]))
                                         / 5.0);
    std::string append = ", " + sum + ", " + average;
    const std::string help = "StudentScoreManger " + (std::string) VERSION + "(" + PLATFORM + ")\n"\
                        "Usage: StudentScoreManager [options] command\n"\
                        "Most used commands:\n"\
                        "  add - add student information\n"\
                        "  enter - enter character interface\n"\
                        "  find - find student information\n"\
                        "  help - show help information\n"\
                        "  list - list all students information\n"\
                        "  modify - modify students information\n"\
                        "  remove - remove student information\n"\
                        "  sort - list all students information by sort\n"\
                        "  version - show studentscoremanager version";
    int c;
    static struct option long_options[] =
            {
                    {"add",     required_argument, nullptr, 'a'},
                    {"enter",   no_argument,       nullptr, 'e'},
                    {"find",    required_argument, nullptr, 'f'},
                    {"help",    no_argument,       nullptr, 'h'},
                    {"list",    no_argument,       nullptr, 'l'},
                    {"modify",  required_argument, nullptr, 'm'},
                    {"remove",  required_argument, nullptr, 'r'},
                    {"sort",    required_argument, nullptr, 's'},
                    {"version", no_argument,       nullptr, 'v'}
            };

    while (true) {
        int opt_index = 0;
        c = getopt_long(argc, argv, "a:cdf:hlm:r:s:v", long_options, &opt_index);
        if (-1 == c) {
            break;
        }
        switch (c) {
            case 'a':
                if (argc != 9) std::cerr << "arguments error" << std::endl;
                else {
                    if (Data::add(ADD + append)) std::cout << "Add Successful!" << std::endl;
                    else std::cerr << "ID already exists" << std::endl;
                }
                break;
            case 'e':
                Data::init();
                Layout::init();
                welcome(0);
                break;
            case 'f':
                Data::find(argv[2]);
                break;
            case 'h':
                std::cout << help << std::endl;
                break;
            case 'l':
                Data::list();
                break;
            case 'm':
                if (argc!=5) std::cerr << "arguments error" << std::endl;
                else { Data::modify(argv[2], argv[3], argv[4]); }
                break;
            case 'r':
                Data::remove(argv[2]);
                break;
            case 's':
                Data::sort(argv[2]);
                break;
            case 'v':
                std::cout << logo << std::endl;
                break;
            default:
                std::cout << "Try 'StudentScoreManager --help' for more information." << std::endl;
                break;
        }
    }
    return 0;

}
