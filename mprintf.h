#ifndef MYPRINTF_MPRINTF_H
#define MYPRINTF_MPRINTF_H

#include <iostream>
#include <cstdarg>
#include <cstring>
#include <sstream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;
using std::setw;

void mprintf(const char *frm, ...);

#endif //MYPRINTF_MPRINTF_H
