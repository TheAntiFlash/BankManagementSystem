//
// Created by Administrator on 5/20/2022.
//

#ifndef ACCOUNT_HOLDER_EMPLOYEE_H
#define ACCOUNT_HOLDER_EMPLOYEE_H


#include "BankUser.h"
//#include "AccountHolder.h"

class Employee : public BankUser {

public:
    Employee(std::string username, std::string password);

    void createAccountHolder();

    void deleteAccountHolder();

    void updateAccountHolderInfo();

    void findAccountHolder();

    void displayAccountHolders();

    void depositAmount();
    
};


#endif //ACCOUNT_HOLDER_EMPLOYEE_H
