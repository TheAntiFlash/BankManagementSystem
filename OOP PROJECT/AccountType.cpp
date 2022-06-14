//
// Created by Administrator on 5/20/2022.
//

#include "AccountType.h"
#include "AccountHolder.h"

//void checkForServiceCharges(int withdrawalAmount){
double AccountType::getServiceCharges() const {
    return serviceCharges;
}

void AccountType::setServiceCharges(double serviceCharges) {
    AccountType::serviceCharges = serviceCharges;
}

double AccountType::getGovtTax() const {
    return govtTax;
}

void AccountType::setGovtTax(double govtTax) {
    AccountType::govtTax = govtTax;
}
