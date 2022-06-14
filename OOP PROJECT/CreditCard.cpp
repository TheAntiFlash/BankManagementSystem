//
// Created by Administrator on 5/20/2022.
//

#include "CreditCard.h"

int objCount = 0;

double CreditCard::getUpperLimit() const {
    return upperLimit;
}

void CreditCard::setUpperLimit(double upperLimit) {
    CreditCard::upperLimit = upperLimit;
}

double CreditCard::getInterestRate() const {
    return interestRate;
}

void CreditCard::setInterestRate(double interestRate) {
    CreditCard::interestRate = interestRate;
}

const std::string &CreditCard::getCardNumber() const {
    return cardNumber;
}

void CreditCard::setCardNumber(const std::string &cardNumber) {
    CreditCard::cardNumber = cardNumber;
}


