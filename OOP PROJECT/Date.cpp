//
// Created by Yahya on 5/16/2022.
//

#include <string>
#include "Date.h"



Date::Date(int day, int month, int year) {

    this->year = year;
    this->month = month;
    this->day = day;

}

std::string Date::getDate() {

    return std::to_string(this->day) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}


