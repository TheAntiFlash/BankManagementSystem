//
// Created by Administrator on 5/20/2022.
//

#include "AccountHolder.h"

int AccountHolder::objCount = 0;
AccountHolder::AccountHolder() {

    firstName = "NULL";
    middleName = "NULL";
    lastName = "NULL";
    address = "NULL";
    Date NoDate;
    dateOfBirth = NoDate;
    teleNum = "NULL";
    //accountType = nullptr;
    accountNumber = 0;
    //cardType = nullptr;
    cnic = "NULL";
    currentbalance = 0;
    //accountNumber = ++objCount;

}

/*AccountHolder::AccountHolder(const AccountHolder &rhs) {
    this->firstName = rhs.firstName;
    this->middleName = rhs.middleName;
    this->lastName = rhs.lastName;
    this->address = rhs.address;
    this->dateOfBirth = rhs.dateOfBirth;
    this->cnic = rhs.cnic;
    this->teleNum = rhs.teleNum;
    this->accountNumber = rhs.accountNumber;
    this->accountType = rhs.accountType;
    this->cardType = rhs.cardType;

    if(accType == 1){
        this->accountType = new SavingAccount;
    }
    else if(accType == 2){
        this->accountType = new CheckingAccount;
    }
    else{
        //this->accountType = nullptr;
    }
    if(cType == 1){
        this->cardType = new MasterCard;
    }
    else if(cType == 2){
        this->cardType = new VisaCard;
    }
    else if(cType == 3){
        this->cardType = new LocalCard;
    }
    else{
        //this->cardType = nullptr;
    }


}*/

AccountHolder::AccountHolder(std::string firstName, std::string middleName, std::string lastName, std::string address, const Date &date, int teleNum, int cnic, int accountType, int cardType, int accountNumber) {

    this->firstName = firstName;
    this->middleName = middleName;
    this->lastName = lastName;
    this->address = address;
    this->dateOfBirth = date;
    this->teleNum = teleNum;
    this->cnic = cnic;
    this->accountNumber = accountNumber;
    this->accType = accountType;
    this->cType = cardType;

    if(accountType == 1){
        this->accountType = new SavingAccount;
    }
    else if(accountType == 2){
        this->accountType = new CheckingAccount;
    }
    else{
        //this->accountType = nullptr;
    }
    if(cardType == 1){
        this->cardType = new MasterCard;
    }
    else if(cardType == 2){
        this->cardType = new VisaCard;
    }
    else if(cardType == 3){
        this->cardType = new LocalCard;
    }
    else{
        //this->cardType = nullptr;
    }

}


int AccountHolder::getAccountNumber() {
    return accountNumber;
}

void AccountHolder::setAccountNumber(int accountNumber) {
    AccountHolder::accountNumber = accountNumber;
}

void AccountHolder::deductServiceCharges(int withdrawalAmount) {
    if(withdrawalAmount > 5000){
        currentbalance -= (withdrawalAmount * 0.2);
    }

}

void AccountHolder::setAccountType(int accountType) {
    this->accType = accountType;
    if(accountType == 1){
        this->accountType = new SavingAccount;
    }
    else if(accountType == 2){
        this->accountType = new CheckingAccount;
    }
    else{
        //this->accountType = nullptr;
    }
}

void AccountHolder::setCardType(int cardType) {
    this->cType = cardType;

    if(cardType == 1){
        this->cardType = new MasterCard;
    }
    else if(cardType == 2){
        this->cardType = new VisaCard;
    }
    else if(cardType == 3){
        this->cardType = new LocalCard;
    }
    else{
        //this->cardType = nullptr;
    }
}

int AccountHolder::getObjCount() {
    return objCount;
}

void AccountHolder::setObjCount(int objCount) {
    AccountHolder::objCount = objCount;
}

double AccountHolder::getCurrentbalance() const {
    return currentbalance;
}

void AccountHolder::setCurrentbalance(double currentbalance) {
    AccountHolder::currentbalance = currentbalance;
}

void AccountHolder::setCurrentbalance1(long double currentbalance) {
    AccountHolder::currentbalance = currentbalance;
}

int AccountHolder::getAccountType() const {
    return accType;
}

int AccountHolder::getCardType() const {
    return cType    ;
}

std::string AccountHolder::getAccountType(int) {
    if(accType == 1){
        return "Saving Account";
    }
    else if(accType == 2){
        return "Checking Account";
    }
    else{
        return "Invalid Type";
    }
}

std::string AccountHolder::getCardType(int) {
    if(cType == 1){
        return "Mastercard";
    }
    else if(cType == 2){
        return "Visa Card";
    }
    else if(cType == 3){
        return "Local Card";
    }
    else{
        return "Invalid Type";
    }
}




