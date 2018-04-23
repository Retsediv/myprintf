#include "mprintf.h"


uintmax_t number_size(int n) {
    uintmax_t number_of_digits = 0;

    do {
        ++number_of_digits;
        n /= 10;
    } while (n);

    return number_of_digits;
}

void mprintf(const char *frm, ...) {
    string format(frm);

    const char *s;
    int n, i = 0;
    double f;
    int width = 0;
    int precision = 0;
    stringstream ss;
    bool prev_is_format = false;
    bool prev_is_dot = false;

    va_list arglist;
    va_start (arglist, format);

    while (format[i]) {
        if (prev_is_format) {

            // case for dot in format
            if (format[i] == '.') {
                ++i;
                prev_is_dot = true;
                continue;
            }

            // get width and precision
            if (isdigit(format[i]) or format[i] == '-') {
                ss << format.substr(i, format.size() - i - 1);

                if (prev_is_dot) {
                    ss >> precision;
                    prev_is_dot = false;
                    i += number_size(precision);
                } else {
                    ss >> width;
                    prev_is_dot = true;
                    i += number_size(width);
                }

                prev_is_format = true;
                ss.str("");
                continue;
            }

            // we have already read all numbers(width and precision)
            // and can say that this letter is last in formatting part
            // e.g "some here %10.5f something here"
            prev_is_format = false;

            // set width and precision params to cout
            // if left alighting
            if (width >= 0) {
                cout.width(width);
            }
            cout.precision(precision);

            // switch type to correctly detect the type of data and print arg
            switch (format[i]) {
                case 's': {
                    s = va_arg(arglist, const char *);
                    cout << s;
                    break;
                }
                case 'd': {
                    n = va_arg(arglist, int);
                    cout << n;
                    break;
                }
                case 'f': {
                    f = va_arg(arglist, double);
                    cout << f;
                    break;
                }
                default: {
                    break;
                }

            }
        } else if (format[i] == '%') {
            prev_is_format = true;
        } else {
            cout << format[i];
        }

        // if right alighting
        // TODO: refactor it
        if (width < 0) {
            for (int x = 0; x < abs(width); ++x) {
                cout << " ";
            }
//            cout.width(width);
        }

        // go to the next char
        ++i;

        // reset width and precision
        width = 0;
        precision = 10;
    }

    cout << endl;
    va_end(arglist);
}
