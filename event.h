#pragma once
#include <iostream>
#include "date.h"

using namespace std;

struct Event{
    const Date date;
    const string name;
};

ostream& operator << (ostream& os, const Event& event){
    return os << event.date << ' ' << event.name;
}