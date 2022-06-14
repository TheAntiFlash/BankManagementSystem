//
// Created by Administrator on 5/20/2022.
//

#include "Person.h"

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getMiddleName() const {
    return middleName;
}

void Person::setMiddleName(const std::string &middleName) {
    Person::middleName = middleName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

std::string Person::getCnic() const {
    return cnic;
}

void Person::setCnic(std::string cnic) {
    Person::cnic = cnic;
}

const std::string &Person::getTeleNum() const {
    return teleNum;
}

void Person::setTeleNum(std::string teleNum) {
    Person::teleNum = teleNum;
}

const std::string &Person::getAddress() const {
    return address;
}

void Person::setAddress(const std::string &address) {
    Person::address = address;
}

const Date &Person::getDateOfBirth() const {
    return dateOfBirth;
}

void Person::setDateOfBirth(const Date &dateOfBirth) {
    Person::dateOfBirth = dateOfBirth;
}



