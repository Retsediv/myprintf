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

void mprintf(const char *frm, ...) {
    string format(frm);
    int n, i = 0;
    double f;
    string s;
    bool prev_is_format = false;
    bool prev_is_dot = false;

    va_list arglist;
    va_start (arglist, format);

    cout << format << endl;
    while (format[i]) {
        if (prev_is_dot) {
            stringstream ss(format.substr(i, format.size() - 1));
            int temp_f;
            ss >> temp_f;
            cout << setw(temp_f);

            prev_is_format = true;
            prev_is_dot = false;

            cout << endl << "STR:" << ss.str() << endl;
            cout << endl << "TEMP: " << temp_f << endl;
        }

        if (prev_is_format) {
            prev_is_format = false;

            if (isdigit(format[i])) {
                stringstream ss(format.substr(i, format.size() - 1));
                int temp_f;
                ss >> temp_f;
                cout << setw(temp_f);

                prev_is_format = true;
                prev_is_dot = true;

                cout << endl << "STR:" << ss.str() << endl;
                cout << endl << "TEMP: " << temp_f << endl;
            }


            switch (format[i]) {
                case 's': {
                    s = va_arg(arglist, const char *);
                    cout << s;
                }
                    break;
                case 'd': {
                    n = va_arg(arglist, int);
                    cout << n;
                }
                    break;
                case 'f': {
                    f = va_arg(arglist, double);
                    cout << f;
                }
                    break;
                default:
                    break;
            }
        } else if (format[i] == '%') {
            prev_is_format = 1;
        } else {
            cout << format[i];
        }

        ++i;
    }
//    for (size_t i = 0; i < strlen(format); ++i) {
//
//        n = va_arg(arglist, int);
//        cout << n << " ";
//
//    }
    cout << endl;
    va_end(arglist);
}

int main() {
    mprintf("My #%10.5d test here is a string: %s", 1, "TEST STRING!");

    return 0;
}