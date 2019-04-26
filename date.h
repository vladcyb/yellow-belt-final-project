#pragma once
#include <iostream>
using namespace std;

struct Date{
    const int year;
    const int month;
    const int day;
};

ostream& operator << (ostream& stream, const Date& date);
Date ParseDate(istream& is);
bool operator < (const Date& lhs, const Date& rhs);
