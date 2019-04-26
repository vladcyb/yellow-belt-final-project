#include "database.h"

void Database::Add(const Date& date, const string& name) {
    data_[date].push_back(name);
}

void Database::Print(ostream& os) const {
    for(const auto& [date, events] : data_){
        for(const auto& event_name : events){
            os << date << ' ' << event_name << endl;
        }
    }
}

const Event& Database::Last(const Date& date) const {
    auto date_item = data_.find(date);
    return { date, (*date_item).second.back() };
}
