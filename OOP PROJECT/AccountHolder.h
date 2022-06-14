//
// Created by Administrator on 5/20/2022.
//

#ifndef ACCOUNT_HOLDER_ACCOUNTHOLDER_H
#define ACCOUNT_HOLDER_ACCOUNTHOLDER_H
#include <string>
#include "AccountType.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "CreditCard.h"
#include "MasterCard.h"
#include "VisaCard.h"
#include "LocalCard.h"
#include "Date.h"
#include "Person.h"
//#include "BankUser.cpp"
//#include "Employee.h"
//#include "Customer.h"
/*#include "Employee.cpp"
#include "Customer1.cpp"*/

class AccountHolder : public Person {

protected:

    static int objCount;
    int accountNumber;
    long double currentbalance;
    int accType;
    int cType;
public:
    int getAccountType() const;

    int getCardType() const;

    std::string getAccountType(int);
    std::string getCardType(int);

    AccountType *accountType;

    CreditCard *cardType;

    static int getObjCount();

    static void setObjCount(int objCount);

    double getCurrentbalance() const;

    void setCurrentbalance(double currentbalance);

    AccountHolder();

    AccountHolder(std::string,std::string,std::string,std::string,const Date &,int,int,int,int,int);


    void setAccountType(int accountType);

    void setCardType(int cardType);

    int getAccountNumber();

    void setAccountNumber(int accountNumber);

    void deductServiceCharges(int withdrawalAmount);

    void deductGovernmentTax(int withdrawalAmount);

    void setCurrentbalance1(long double currentbalance);

    // friend void checkForServiceCharges(int withdrawalAmount);
};

#endif //ACCOUNT_HOLDER_ACCOUNTHOLDER_H
