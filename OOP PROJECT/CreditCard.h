//
// Created by Administrator on 5/20/2022.
//

#ifndef ACCOUNT_HOLDER_CREDITCARD_H
#define ACCOUNT_HOLDER_CREDITCARD_H


#include <string>

class CreditCard {
protected:
    double upperLimit;
    double interestRate;
    static int objCount;
    std::string cardNumber;
public:
    double getUpperLimit() const;

    void setUpperLimit(double upperLimit);

    double getInterestRate() const;

    void setInterestRate(double interestRate);

    const std::string &getCardNumber() const;

    void setCardNumber(const std::string &cardNumber);

};


#endif //ACCOUNT_HOLDER_CREDITCARD_H
