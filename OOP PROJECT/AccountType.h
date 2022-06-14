//
// Created by Administrator on 5/20/2022.
//

#ifndef ACCOUNT_HOLDER_ACCOUNTTYPE_H
#define ACCOUNT_HOLDER_ACCOUNTTYPE_H


class AccountType {

protected:
    double serviceCharges;
    double govtTax;
public:
    double getServiceCharges() const;

    void setServiceCharges(double serviceCharges);

    double getGovtTax() const;

    void setGovtTax(double govtTax);


//friend void checkForServiceCharges(int withdrawalAmount);

};
#endif //ACCOUNT_HOLDER_ACCOUNTTYPE_H
