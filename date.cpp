#include <iomanip>
#include <tuple>
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

tuple<int, int, int>
GetDateRank(const Date& date){
    return tie(date.year, date.month, date.day);
}

bool operator < (const Date& lhs, const Date& rhs) {
    return GetDateRank(lhs) < GetDateRank(rhs);
}
