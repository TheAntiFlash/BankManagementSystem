//
// Created by Administrator on 5/20/2022.
//

#ifndef ACCOUNT_HOLDER_SAVINGACCOUNT_H
#define ACCOUNT_HOLDER_SAVINGACCOUNT_H

#include <iostream>
#include "AccountType.h"

class SavingAccount: public AccountType{
public:
    SavingAccount(){
        //std::cout <<"SavingAccount";
        setServiceCharges(0);
        setGovtTax(0);
    }

};


#endif //ACCOUNT_HOLDER_SAVINGACCOUNT_H
