//
// Created by Yahya on 5/21/2022.
//

#include <iostream>
#include <iomanip>
#include "BankUser.h"

void BankUser::findUser(std::string username, std::string password) {
    this->username = username;
    this->password = password;
    std::string usersInfo;
    std::ifstream readCred;
    std::string preUser = "username:";
    std::string prePass = "password:";
    loggedIn = false;
    bool userFound = false;
    bool passFound = false;
    readCred.open(userInfo_txt);




    username = preUser + username;
    password = prePass + password;

    std::cout << usersInfo;
    while(readCred >> usersInfo){
        if(!userFound){
            userFound = username == usersInfo;
        }
        if(!passFound){
            passFound = password == usersInfo;
        }
        if(userFound && passFound){
            break;
        }
    }

    if(userFound && passFound){
        loggedIn = true;
        std::cout <<"\nWelcome " + this->username + "!";
    }
    else {
        std::cout << "\nIncorrect Username or Password";
    }

}

void BankUser::logTransaction(double withdrawn, double current, std::string user, int dummy) {
    std::fstream file;

    if(user == "notSet"){
        file.open(this->username + ".txt", std::ios::app);
    }
    else{
        file.open(user + ".txt", std::ios::app);
    }

    if(file.is_open()){

        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        tt = localtime(&t);

        file << "\nDate: " << asctime(tt);

        if (dummy == 0){
            file << "Withdrawn Amount: " << withdrawn;

        }
        else{
            file << "Deposit Amount: " << withdrawn;

        }
        file << "\nBalance: " << current;
        file << "\n******************************";

    }

}
void BankUser::updateBalance(double balance, string user) {


    std::ostringstream text;
    std::ifstream in_file;
    std::ofstream out_file;
    if(user == "notSet"){
        in_file.open(this->username + ".txt");
    }
    else{
        in_file.open(user + ".txt");
    }

    text << in_file.rdbuf();
    std::string str = text.str();

    std::string str_search = std::to_string(this->holder.getCurrentbalance());
    str_search.erase( str_search.find_last_not_of('0') + 1, std::string::npos );

    std::string str_replace = std::to_string(balance);
    str_replace.erase( str_replace.find_last_not_of('0') + 1, std::string::npos );

    //std::cout << str_replace;
    int pos = str.find(str_search);
    //std::cout << pos << std::endl << str_search;
    str.replace(pos, std::string(str_search).length(), str_replace);
    in_file.close();

    if(user == "notSet"){
        out_file.open(this->username + ".txt");
    }
    else{
        out_file.open(user + ".txt");
    }
    out_file << str;

}

const string &BankUser::getUsername() const {
    return username;
}

const string &BankUser::getPassword() const {
    return password;
}

bool BankUser::isLoggedIn() const {
    return loggedIn;
}

bool BankUser::withdraw(std::string user, double amount) {

    if(amount > holder.getCurrentbalance()){
        std::cout << "\nWithdraw Amount Greater Than Balance -> Please Try Again\n";
        return false;
    }
    else if(amount > holder.cardType->getUpperLimit()){
        std::cout << "\nWithdraw Amount Greater Than Credit Card Limit -> Please Try Again\n";
        return false;
    }
    else{
        if(amount > 5000){
            holder.accountType->setServiceCharges(amount*0.002);
        }
        else{
            holder.accountType->setServiceCharges(0);
        }
        if(amount > 50000){
            holder.accountType->setGovtTax(amount*0.025);
        }
        else{
            holder.accountType->setGovtTax(0);

        }
        std:: cout <<  + holder.accountType->getServiceCharges();// + holder.accountType->getGovtTax()) );

        updateBalance(holder.getCurrentbalance() - ( amount + holder.accountType->getServiceCharges() + holder.accountType->getGovtTax()) );
        holder.setCurrentbalance(holder.getCurrentbalance() - ( amount + holder.accountType->getServiceCharges() + holder.accountType->getGovtTax()) );

        logTransaction(amount + (holder.accountType->getServiceCharges() + holder.accountType->getGovtTax()) ,holder.getCurrentbalance() );

        std::cout << "\nWithdrawn Amount: " << amount << "\nTaxes: " << (holder.accountType->getServiceCharges() + holder.accountType->getGovtTax())
                  << "\nTotal Deducted: " << amount + (holder.accountType->getServiceCharges() + holder.accountType->getGovtTax())  << "\nCurrentBalance: " << holder.getCurrentbalance();
        return true;
        //MAKE SURE TO ADD CHECKS FOR ALL THINGS HERE5
    }

}

void BankUser::getAccountHoldersInfo(std::string mUsername) {
    std::string usersInfo;
    std::ifstream readCred;
    //std::string preUser = "username:";
    //std::string prePass = "password:";

    if(mUsername == "notSet") {
        readCred.open(this->username +".txt");
    }
    else {
        readCred.open(mUsername +".txt");
    }
    //std::cout << readCred.is_open() << this->username;


    Date dateOfBirth;
    while(readCred >> usersInfo){
        //std::cout << std::endl << usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()) << std::endl;
        if("FirstName:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setFirstName( usersInfo.substr( usersInfo.find(":")+1,usersInfo.size() ) );
            //std::cout<< std::endl << holder.getFirstName();
        }
        else if("MiddleName:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setMiddleName(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            //std::cout<< std::endl<< holder.getMiddleName();
        }
        else if("LastName:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setLastName(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< "Name: " << holder.getFirstName() << " " << holder.getMiddleName() << " " << holder.getLastName();
        }
        else if("Address:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setAddress(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< "Address: " <<holder.getAddress();
        }
        else if("DayOfBirth:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            dateOfBirth.setDay(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
        }
        else if("MonthOfBirth:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            dateOfBirth.setMonth(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
        }
        else if("YearOfBirth:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            dateOfBirth.setYear(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
            std::cout << std::endl<< "Date Of Birth:" <<dateOfBirth.getDate();
            holder.setDateOfBirth(dateOfBirth);
        }
        else if("PhoneNumber:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setTeleNum(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl << "Phone Number: " << holder.getTeleNum();
        }
        else if("CNIC:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setCnic(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl << "CNIC: "<< holder.getCnic();
        }
        else if("AccountType:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setAccountType(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
            std::cout<< std::endl << "Account Type: "<< holder.getAccountType(1);
        }
        else if("CardType:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setCardType(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
            std::cout<< std::endl << "Card Type: "<< holder.getCardType(1);
        }
        else if("AccountNumber:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setAccountNumber(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
            std::cout<< std::endl << "Account Number: " << holder.getAccountNumber();

        }
        else if("CardNumber:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.cardType->setCardNumber(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< "Credit Card Number: " <<holder.cardType->getCardNumber();
        }
        else if("CurrentBalance:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setCurrentbalance(std::stold((usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()))));
            std::cout<< std::endl << "Current Balance: "<<   std::fixed << std::setprecision(2) << holder.getCurrentbalance();
        }

    }


}


