//
// Created by Administrator on 5/20/2022.
//

#ifndef ACCOUNT_HOLDER_CHECKINGACCOUNT_H
#define ACCOUNT_HOLDER_CHECKINGACCOUNT_H

#include <iostream>
#include "AccountType.h"

class CheckingAccount: public AccountType{
public:
    CheckingAccount(){
        setServiceCharges(0);
        setGovtTax(0);
    }

};


#endif //ACCOUNT_HOLDER_CHECKINGACCOUNT_H
