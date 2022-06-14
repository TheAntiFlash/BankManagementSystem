//
// Created by User on 5/21/2022.
//

#include <sstream>
#include <iomanip>
#include "Customer.h"

Customer::Customer(std::string username, std::string password) {
    this->userInfo_txt = "customer_info.txt";
    this->findUser(username,password);

    //std::cout << isLoggedIn();
    if(isLoggedIn()){
        //std::cout <<"This section ran";
        getAccountHoldersInfo();
    }
}



bool Customer::withdraw(std::string creditCardNumber, double amount){
    if(creditCardNumber != holder.cardType->getCardNumber()){
        std::cout << "\nInvalid Credit Card Number -> Please Try Again\n";
        return false;
    }
    else if(amount > holder.getCurrentbalance()){
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
bool Customer::withdraw(int accNum, std::string cnic, double amount) {
    if (accNum != holder.getAccountNumber()) {
        std::cout << "\nInvalid Account Number -> Please Try Again\n";
        return false;
    } else if (cnic != holder.getCnic()) {
        std::cout << "\nInvalid CNIC Number -> Please Try Again\n";
        return false;
    } else if (amount > holder.getCurrentbalance()) {
        std::cout << "\nWithdraw Amount Greater Than Balance -> Please Try Again\n";
        return false;
    } else if (amount > holder.cardType->getUpperLimit()) {
        std::cout << "\nWithdraw Amount Greater Than Credit Card Limit -> Please Try Again\n";
        return false;
    } else {
        if (amount > 5000) {
            holder.accountType->setServiceCharges(amount * 0.002);
        } else {
            holder.accountType->setServiceCharges(0);
        }
        if (amount > 50000) {
            holder.accountType->setGovtTax(amount * 0.025);
        } else {
            holder.accountType->setGovtTax(0);

        }
        std::cout <<  + holder.accountType->getServiceCharges();// + holder.accountType->getGovtTax()) );

        updateBalance(holder.getCurrentbalance() - ( amount + holder.accountType->getServiceCharges() + holder.accountType->getGovtTax()) );
        holder.setCurrentbalance(holder.getCurrentbalance() - ( amount + holder.accountType->getServiceCharges() + holder.accountType->getGovtTax()) );

        logTransaction(amount + (holder.accountType->getServiceCharges() + holder.accountType->getGovtTax()) ,holder.getCurrentbalance() );

        std::cout << "\nWithdrawn Amount: " << amount << "\nTaxes: " << (holder.accountType->getServiceCharges() + holder.accountType->getGovtTax())
                  << "\nTotal Deducted: " << amount + (holder.accountType->getServiceCharges() + holder.accountType->getGovtTax())  << "\nCurrentBalance: " << holder.getCurrentbalance();
        return true;
    }
}

/*void Customer::getAccountHoldersInfo() {
    std::string usersInfo;
    std::ifstream readCred;
    //std::string preUser = "username:";
    //std::string prePass = "password:";

    readCred.open(this->username +".txt");
    //std::cout << readCred.is_open() << this->username;


    Date dateOfBirth;
    while(readCred >> usersInfo){
        //std::cout << std::endl << usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()) << std::endl;
        if("FirstName:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setFirstName( usersInfo.substr( usersInfo.find(":")+1,usersInfo.size() ) );
            std::cout<< std::endl<< holder.getFirstName();
        }
        else if("MiddleName:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setMiddleName(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< holder.getMiddleName();
        }
        else if("LastName:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setLastName(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< holder.getLastName();
        }
        else if("Address:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setAddress(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< holder.getAddress();
        }
        else if("DayOfBirth:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            dateOfBirth.setDay(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
        }
        else if("MonthOfBirth:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            dateOfBirth.setMonth(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
        }
        else if("YearOfBirth:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            dateOfBirth.setYear(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
            std::cout << std::endl<< dateOfBirth.getDate();
            holder.setDateOfBirth(dateOfBirth);
        }
        else if("PhoneNumber:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setTeleNum(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< holder.getTeleNum();
        }
        else if("CNIC:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setCnic(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< holder.getCnic();
        }
        else if("AccountType:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setAccountType(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
        }
        else if("CardType:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setCardType(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
        }
        else if("AccountNumber:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.setAccountNumber(std::stoi(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())));
            std::cout<< std::endl<< holder.getAccountNumber();
        }
        else if("CardNumber:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            holder.cardType->setCardNumber(usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()));
            std::cout<< std::endl<< holder.cardType->getCardNumber();
        }
        else if("CurrentBalance:" == usersInfo.substr(0,usersInfo.find(":")+1)){
            //std::cout << std::endl << std::strtold((usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())) << std::endl;
            //holder.setCurrentbalance(std::atof((usersInfo.substr(usersInfo.find(":")+1,usersInfo.size())).c_str()));

            holder.setCurrentbalance(std::stold((usersInfo.substr(usersInfo.find(":")+1,usersInfo.size()))));

            std::cout<< std::endl<<  std::fixed << std::setprecision(2) << holder.getCurrentbalance();
        }
        *//*this->holder.accountType->setServiceCharges(0);
        this->holder.accountType->setGovtTax(0);*//*
    }


}*/

void Customer::balanceInquiry(int accNum, std::string cnic) {
    if (accNum != holder.getAccountNumber()) {
        std::cout << "\nInvalid Account Number -> Please Try Again\n";

    } else if (cnic != holder.getCnic()) {
        std::cout << "\nInvalid CNIC Number -> Please Try Again\n";

    }
    else{
        std::cout << "Current Balance: " << this->holder.getCurrentbalance();
    }
}

/*void Customer::logTransaction(double withdrawn, double current) {
    std::fstream file;
    file.open(this->username + ".txt", std::ios::app);
    if(file.is_open()){

        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        tt = localtime(&t);

        file << "\nDate: " << asctime(tt);

        file << "Withdrawn Amount: " << withdrawn;
        file << "\nBalance: " << current;
        file << "\n******************************";

    }

}*/

void Customer::getMiniStatement(int accNum, std::string cnic) {

    if (accNum != holder.getAccountNumber()) {
        std::cout << "\nInvalid Account Number -> Please Try Again\n";

    } else if (cnic != holder.getCnic()) {
        std::cout << "\nInvalid CNIC Number -> Please Try Again\n";

    }
    else {
        std::ifstream file;
        std::string temp;
        file.open(this->username + ".txt");

        int transactionCount = 0;

        if (file.is_open()) {
            while (file >> temp) {
                if (temp == "Date:") {
                    transactionCount++;
                }
            }

            file.close();
            file.open(this->username + ".txt");

            if (transactionCount <= 10) {
                bool transactionsFound = false;

                while (file >> temp) {
                    if(!transactionsFound){

                        if (temp == "Date:") {
                            transactionsFound = true;
                        }

                    }
                    else{
                        std::cout << "**** Transaction History ****" << std::endl;
                        std::cout << "******************************";
                        std::cout << std::endl << temp;
                        while(std::getline(file,temp)){

                            std::cout << temp << std::endl;

                        }

                    }

            }
            }

            else {

                for(int i = 0 ; i< transactionCount -10;){
                    if(temp == "Date:"){
                        i++;
                        if(i>= transactionCount - 10){
                            while(file>>temp){
                                if(temp == "******************************"){
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    file >> temp;
                }
                std::cout << "**** Last 10 Transactions ****" << std::endl;
                std::cout << "******************************";
                while(std::getline(file,temp)){

                    std::cout << temp << std::endl;

                }
            }
        }
    }
}

void Customer::getTransactionHistory(int accNum, std::string cnic) {

    if (accNum != holder.getAccountNumber()) {
        std::cout << "\nInvalid Account Number -> Please Try Again\n";

    } else if (cnic != holder.getCnic()) {
        std::cout << "\nInvalid CNIC Number -> Please Try Again\n";

    } else {

        std::ifstream file;
        std::string temp;
        file.open(this->username + ".txt");

        int transactionCount = 0;

        if (file.is_open()) {
            while (file >> temp) {
                if (temp == "Date:") {
                    transactionCount++;
                }
            }

            file.close();
            file.open(this->username + ".txt");

            bool transactionsFound = false;

            while (file >> temp) {
                if (!transactionsFound) {

                    if (temp == "Date:") {
                        transactionsFound = true;
                    }

                } else {
                    std::cout << "**** Transaction History ****" << std::endl;
                    std::cout << "******************************";
                    std::cout << std::endl << temp;
                    while (std::getline(file, temp)) {

                        std::cout << temp << std::endl;

                    }
                }
            }
        }
    }
}






