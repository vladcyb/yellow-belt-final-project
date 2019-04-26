#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "event.h"
#include "date.h"

using namespace std;
using notes = map<Date, vector<string>>;

class Database{
public:
    void Add(const Date& date, const string& name);
    void Print(ostream& out_stream) const;
    template<class T>
    int RemoveIf(T predicate) {
        int count = 0;
        for(const auto& date_item : data_){
            auto date_date = date_item.first;
            auto date_events = date_item.second;
            for(auto it = begin(date_events); it != end(date_events); ){
                if (predicate(date_date, *it)){
                    date_events.erase(it++);
                    ++count;
                }else{
                    ++it;
                }
            }
        }
        return count;
    }
    template<class T>
    const vector<Event>& FindIf(T predicate) const {
        vector<Event> result;
        for(const auto& [date, events] : data_){
            for(const auto& event : events){
                if (predicate(date, event)){
                    result.push_back({date, event});
                }
            }
        }
        return result;
    }
    const Event& Last(const Date& date) const;
private:
    notes data_;
};
