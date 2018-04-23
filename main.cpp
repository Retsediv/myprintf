#include <iostream>
#include <cstdarg>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "mprintf.h"

using std::cout;
using std::stringstream;

int main() {
    // just a few tests

    mprintf(cout, "Test string: %s", "TEST STRING!");
    mprintf(cout, "number: %d", 121);
    mprintf(cout, "number with format: %10d aaaaaaaaaaa", 121);
    mprintf(cout, "number with format: %-10d aaaaaaaaaaa", 121);
    mprintf(cout, "float number with format: %4.5f aaaaaaaaaaa", 999.1234567);
    mprintf(cout, "float number with format: %-4.12f aaaaaaaaaaa", 999.1234567);
    mprintf(cout, "My %-10.12f test here is a string: %s", 1.1312312312312312312312312312312321312312, "TEST STRING!");
    mprintf(cout, "My %-10.12f test here is a string: %s", 1.1312312312312312312312312312312321312312, "TEST STRING!");

    return 0;
}