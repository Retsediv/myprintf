#include <iostream>
#include <cstdarg>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "mprintf.h"

using std::string;
using std::cout;
using std::endl;
using std::stringstream;
using std::setw;

int main() {
    stringstream ss;
    mprintf(ss, "My %-10.12f test here is a string: %s", 1.1312312312312312312312312312312321312312, "TEST STRING!");

    cout << ss.str() << endl;
    return 0;
}