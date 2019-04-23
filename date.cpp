#include <iomanip>
#include "date.h"

ostream& operator << (ostream& stream, const Date& date){
    return stream << setfill('0') << setw(4) << date.year <<
        '-' << setw(2) << date.month << '-' << setw(2) << date.day;
}

Date ParseDate(istream& is){
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    return {year, month, day};

}