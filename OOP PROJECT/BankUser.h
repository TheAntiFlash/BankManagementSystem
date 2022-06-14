//
// Created by Yahya on 5/21/2022.
//

#ifndef ACCOUNT_HOLDER_BANKUSER_H
#define ACCOUNT_HOLDER_BANKUSER_H

#include <fstream>
#include "AccountHolder.h"


class BankUser {
protected:
    AccountHolder holder;
    std::string username;
    std::string password;
    bool loggedIn;
    std::string userInfo_txt;

    void getAccountHoldersInfo(std::string username = "notSet");
    void findUser(std::string username, std::string password);
    void updateBalance(double balance, std::string user = "notSet");

    void logTransaction(double withdrawn, double current, std::string user = "notSet", int dummy = 0);

public:

    const std::string &getUsername() const;

    const std::string &getPassword() const;

    bool isLoggedIn() const;


    virtual bool withdraw(std::string, double amount);
};


#endif //ACCOUNT_HOLDER_BANKUSER_H
