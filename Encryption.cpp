//
// Created by cyunrei on 2/10/20.
//

#include "Encryption.h"

void Encryption::caesar(std::string &str,int n) {
   for (char & ch : str) {
       ch = ch + n;
    }

}
