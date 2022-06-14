//
// Created by Administrator on 5/20/2022.
//

#ifndef ACCOUNT_HOLDER_PERSON_H
#define ACCOUNT_HOLDER_PERSON_H
#include <string>
#include "Date.h"

class Person {
protected:
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string address;
    Date dateOfBirth;
    std::string cnic;
    std::string teleNum;

public:
    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getMiddleName() const;

    void setMiddleName(const std::string &middleName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    std::string getCnic() const;

    void setCnic(std::string cnic);

    const std::string &getTeleNum() const;

    void setTeleNum(std::string teleNum);

    const std::string &getAddress() const;

    void setAddress(const std::string &address);

    const Date &getDateOfBirth() const;

    void setDateOfBirth(const Date &dateOfBirth);
};


#endif //ACCOUNT_HOLDER_PERSON_H
