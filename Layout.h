//
// Created by cyunrei on 2/9/20.
//

#ifndef STUDENTSCOREMANAGER_LAYOUT_H
#define STUDENTSCOREMANAGER_LAYOUT_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>

#include "Check.h"
#include "Encryption.h"
#include "Coding.h"
#include "Protection.h"
#include "Data.h"

class Layout {
private:
    int length = 56;
    int width = 14;
public:
    static void init();

    static void clear();

    static void page_top(const std::string &);

    void page_context(std::vector<std::string>, int= 0, bool = false);

    static void page_button(const std::string &, int, const std::string & = "none", int = -1, int= 0);

    static void page_bottom(const std::string &);

    static void tip(int, const std::function<void(int)> &, int= 0);
};

#endif //STUDENTSCOREMANAGER_LAYOUT_H
