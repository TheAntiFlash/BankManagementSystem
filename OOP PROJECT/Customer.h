//
// Created by User on 5/21/2022.
//

#ifndef ACCOUNT_HOLDER_CUSTOMER_H
#define ACCOUNT_HOLDER_CUSTOMER_H


//#include "AccountHolder.h"
#include "BankUser.h"

class Customer : public BankUser{
public:


    Customer(std::string username, std::string password);

    bool withdraw(std::string creditCardNumber, double amount);

    bool withdraw(int accNum, std::string cnic, double amount);

    void balanceInquiry(int accNum, std::string cnic);

    //void logTransaction(double withdrawn, double current);

    void getMiniStatement(int accNum, std::string cnic);

    void getTransactionHistory(int accNum, std::string cnic);
};



#endif //ACCOUNT_HOLDER_CUSTOMER_H
