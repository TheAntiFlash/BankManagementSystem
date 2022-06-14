//
// Created by Yahya on 5/16/2022.
//

#ifndef LAB08_TASK1_DATE_H
#define LAB08_TASK1_DATE_H


class Date {
private:
    int day;
    int month;
    int year;

public:

    Date(int =1, int =1, int=1);

    std::string getDate();

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

};


#endif //LAB08_TASK1_DATE_H
