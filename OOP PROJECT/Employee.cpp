//
// Created by Administrator on 5/20/2022.
//

#include <sstream>
#include <cstring>

#include "Employee.h"

Employee::Employee(std::string username, std::string password) {
    this->userInfo_txt = "employee_info.txt";
    this->findUser(username,password);
    if(isLoggedIn()){
        std::cout << "logged in";
    }
    else{
        std::cout << "You are a failure and you will never be loved";
    }

}

void Employee::createAccountHolder() {

    std::string userName;
    std::string passWord;
    std::string  cnic;
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string address;
    int dayOB;
    int monthOB;
    int yearOB;
    std::string phoneNumber;
    unsigned long long int cardNumber;
    long double balance;


    int accountType;
    int cardType;

    std::cout << "Set Username: ";
    std::cin >> userName;
    std::cout << "Set Password: ";
    std::cin >> passWord;

    std::cout << "Set CNIC: ";
    std::cin >> cnic;
    std::cout << "Account Type\n[1 for Saving Account]\n[2 for Checking Account]: ";
    std::cin >> accountType;
    std::cout << "Card Type\n[1 for MasterCard]\n[2 for Visa Card]\n[3 for Local Card]: ";
    std::cin >> cardType;

    std::cout << "Set First Name: ";
    std::cin >> firstName;
    std::cout << "Set Middle Name: ";
    std::cin >> middleName;
    std::cout << "Set Last Name: ";
    std::cin >> lastName;
    std::cout << "Set Address: ";
    std::cin >> address;
    std::cout << "Set Day of Birth: ";
    std::cin >> dayOB;
    std::cout << "Set Month of Birth: ";
    std::cin >> monthOB;
    std::cout << "Set Year of Birth: ";
    std::cin >> yearOB;
    std::cout << "Set Phone Number: ";
    std::cin >> phoneNumber;


    holder.setCnic(cnic);
    holder.setCardType(cardType);
    holder.setAccountType(accountType);
    holder.setAccountNumber((rand() % 219999 + 210000));
    cardNumber = ( rand() % 9999999999999999 + 1000000000000000);
    holder.cardType->setCardNumber(std::to_string(cardNumber));


    std::fstream file;
    file.open("customer_info.txt", std::ios::app);
    if(file.is_open()){

        file << "\nAccountNumber:"  << holder.getAccountNumber() << std::endl;
        file << "CNIC:" << holder.getCnic() << std::endl;
        file << "AccountType:" << holder.getAccountType() << std::endl;
        file << "CardType:" << holder.getCardType() << std::endl;
        file << "username:" << userName << std::endl;
        file << "password:" << passWord << std::endl;
        file << "*********************";

    }
    file.close();


    file.open(userName +".txt", std::ios::app);

    if(file.is_open()){
        std::cout << "\nCongratulations it's a celebration party all night tanananana nation";
        file << "FirstName:" << firstName << std::endl;
        file << "MiddleName:" << middleName << std::endl;
        file << "LastName:" << lastName << std::endl;
        file << "******************************" << std::endl;
        file << "Address:" << address << std::endl;
        file << "******************************" << std::endl;
        file << "DayOfBirth:" << dayOB << std::endl;
        file << "MonthOfBirth:" << monthOB << std::endl;
        file << "YearOfBirth:" << yearOB << std::endl;
        file << "******************************" << std::endl;
        file << "PhoneNumber:" << phoneNumber << std::endl;
        file << "CNIC:" << cnic << std::endl;
        file << "******************************" << std::endl;
        file << "AccountType:" << holder.getAccountType() << std::endl;
        file << "CardType:" << holder.getCardType() << std::endl;
        file << "******************************" << std::endl;
        file << "AccountNumber:" << holder.getAccountNumber() << std::endl;
        file << "******************************" << std::endl;
        file << "CardNumber:" << holder.cardType->getCardNumber() << std::endl;
        file << "******************************" << std::endl;
        file << "CurrentBalance:" << 00.00 << std::endl;
        file << "******************************" << std::endl;

    }


}

void Employee::deleteAccountHolder() {
    std::string accountNumber;
    std::string temp;
    std::string userName;
    std::cout << "Enter Account number For account that You want to delete: ";
    std::cin >> accountNumber;

    std::ostringstream text;
    std::ifstream in_file("customer_info.txt");

    if(in_file.is_open()){
        //int lineNum = 0;
        text << in_file.rdbuf();

        int userNamePos;
        std::string str = text.str();
        int position1 = str.find("AccountNumber:" + accountNumber);
        if(position1 != 0){

            position1--;
        }
        //std::cout << position1;
        //std::cout << str.substr(position1,str.size());
        userNamePos = str.find("username:",position1);
        int userNamePos1 = str.find('\n',userNamePos);

        userName = str.substr(userNamePos,userNamePos1-userNamePos);

        userName = userName.substr(9);
        //std::cout << userName;
        int position2 = (str.substr(position1,str.size())).find_first_of("*********************");
        position2 += 21;
        //std::cout << position2;
        str.replace(position1,  position2, "");

        in_file.close();

        std::ofstream write("customer_info.txt");
        write << str;
        write.close();

        userName =  userName + ".txt";
        //std::cout << userName;
        char arr[userName.length()+1] ;
        strcpy(arr,userName.c_str());
        if(!(std::remove(arr))){
            std::cout<< "Account Holder Successfully Deleted" << std::endl;
        }
        else{
            std::cout<< "Account Holder Unsuccessfully Deleted" << userName << std::endl;
        }
    }


    }

void Employee::updateAccountHolderInfo() {
    std::string temp;
    std::string userName;
    int choice;

    std::cout << "Enter username for account holder you want to edit: ";
    std::cin >> userName;

    std::cout << "What do you want to edit \n[1 for FirstName]\n[2 for MiddleName]\n[3 for LastName]\n[4 for Address]\n[5 for DateOfBirth]\n[6 for PhoneNumber]\n[7 for CNIC]\n[8 for AccountType]\n[9 for CardType]: ";
    std::cin >> choice;
    std::ostringstream text;
    std::ifstream in_file(userName + ".txt");

    if(in_file.is_open()){

        text << in_file.rdbuf();
        std::string str = text.str();


        switch(choice) {
            case 1: {
                std::string str_search = "FirstName:";
                std::string str_replace;
                std::string str_firstName;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_firstName = str.substr(position1, position2);
                //std::cout << str_firstName;


                std::cout << "Replace \"" << str_firstName << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();

                break;
            }
            case 2: {
                std::string str_search = "MiddleName:";
                std::string str_replace;
                std::string str_middleName;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_middleName = str.substr(position1, position2);
                //std::cout << str_middleName;


                std::cout << "Replace \"" << str_middleName << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();


                break;
            }
            case 3: {

                std::string str_search = "LastName:";
                std::string str_replace;
                std::string str_lastName;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_lastName = str.substr(position1, position2);
                //std::cout << str_lastName;


                std::cout << "Replace \"" << str_lastName << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();


                break;
            }
            case 4: {
                std::string str_search = "Address:";
                std::string str_replace;
                std::string str_address;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_address = str.substr(position1, position2);
                //std::cout << str_address;


                std::cout << "Replace \"" << str_address << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();


                break;
            }
            case 5: {
                std::string str_searchDay = "DayOfBirth:";
                std::string str_searchMonth = "MonthOfBirth:";
                std::string str_searchYear = "YearOfBirth:";

                std::string str_replaceDay;
                std::string str_dayOfBirth;

                std::string str_replaceMonth;
                std::string str_monthOfBirth;

                std::string str_replaceYear;
                std::string str_yearOfBirth;


                int position1 = str.find(str_searchDay);
                position1 += str_searchDay.length();
                int position2 = str.substr(position1).find('\n');

                str_dayOfBirth = str.substr(position1, position2);
                //std::cout << str_dayOfBirth;

                std::cout << "Replace Day: \"" << str_dayOfBirth << "\" with: ";
                std::cin >> str_replaceDay;


                str.replace(position1, position2, str_replaceDay);

                position1 = str.find(str_searchMonth);
                position1 += str_searchMonth.length();
                position2 = str.substr(position1).find('\n');

                str_monthOfBirth = str.substr(position1, position2);
                //std::cout << str_monthOfBirth;

                std::cout << "Replace Month: \"" << str_monthOfBirth << "\" with: ";
                std::cin >> str_replaceMonth;





                str.replace(position1, position2, str_replaceMonth);

                position1 = str.find(str_searchYear);
                position1 += str_searchYear.length();
                position2 = str.substr(position1).find('\n');

                str_yearOfBirth = str.substr(position1, position2);
                //std::cout << str_dayOfBirth;

                std::cout << "Replace Year: \"" << str_yearOfBirth << "\" with: ";
                std::cin >> str_replaceYear;




                str.replace(position1, position2, str_replaceYear);

                in_file.close();


                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();



                break;
            }
            case 6: {
                std::string str_search = "PhoneNumber:";
                std::string str_replace;
                std::string str_phoneNumber;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_phoneNumber = str.substr(position1, position2);
                //std::cout << str_phoneNumber;


                std::cout << "Replace \"" << str_phoneNumber << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();


                break;
            }
            case 7: {
                std::string str_search = "CNIC:";
                std::string str_replace;
                std::string str_cnic;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_cnic = str.substr(position1, position2);
                //std::cout << str_cnic;


                std::cout << "Replace \"" << str_cnic << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();


                break;
            }
            case 8: {
                std::string str_search = "AccountType:";
                std::string str_replace;
                std::string str_accountType;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_accountType = str.substr(position1, position2);
                //std::cout << str_middleName;


                std::cout << "Replace \"" << str_accountType << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();


                break;
            }
            case 9: {
                std::string str_search = "CardType:";
                std::string str_replace;
                std::string str_cardType;
                int position1 = str.find(str_search);
                position1 += str_search.length();
                int position2 = str.substr(position1).find('\n');

                str_cardType = str.substr(position1, position2);
                //std::cout << str_cardType;


                std::cout << "Replace \"" << str_cardType << "\" with: ";
                std::cin >> str_replace;

                str.replace(position1, position2, str_replace);
                in_file.close();

                std::ofstream out_file(userName + ".txt");
                out_file << str;
                out_file.close();


                break;
            }
        }
    }


}

void Employee::findAccountHolder() {

    std::string accountNumber;
    std::string temp;
    std::string userName;
    std::string cnic;
    int choice;

    std::cout << "Get Account Holder with \n[1 for Account Number]\n[2 for CNIC]: ";
    std::cin >> choice;

    if(choice == 1){

        std::cout << "Enter Account number For account that You want to display: ";
        std::cin >> accountNumber;
    }
    else if(choice == 2){
        std::cout << "Enter CNIC For account that You want to display: ";
        std::cin >> cnic;
    }
    else{
        std::cout << "Incorrect choice";
        return;
    }


    std::ostringstream text;
    std::ifstream in_file("customer_info.txt");

    if(in_file.is_open()){
        //int lineNum = 0;
        text << in_file.rdbuf();

        int userNamePos;
        std::string str = text.str();
        //std::cout << str;
        int position1;

        if(choice == 1){
            position1 = str.find("AccountNumber:" + accountNumber);

        }
        else{
            position1 = str.find("CNIC:" + cnic);
        }

        if(position1 != 0){

            position1--;
        }
        //std::cout << position1;
        //std::cout << str.substr(position1,str.size());
        userNamePos = str.find("username:",position1);
        int userNamePos1 = str.find('\n',userNamePos);

        userName = str.substr(userNamePos,userNamePos1-userNamePos);

        userName = userName.substr(9);
        //std::cout << userName;
        getAccountHoldersInfo(userName);
        in_file.close();


    }


}

void Employee::displayAccountHolders() {
    int choice;
    int accountType;
    int cardType;
    std::cout << "Display account Holders of specific "
                 "\n[1 Account Type]"
                 "\n[2 Card Type]: ";
    std::cin >> choice;

    if(choice == 1){

        std::cout << "Enter Account Type"
                     "\n[1 Saving Account]"
                     "\n[2 Checking Account]: ";
        std::cin >> accountType;
    }
    else if(choice == 2){
        std::cout << "Enter Card Type"
                     "\n[1 Mastercard]"
                     "\n[2 Visa Card]"
                     "\n[3 Local Card]: ";
        std::cin >> cardType;
    }
    else{
        std::cout << "Incorrect choice";
        return;
    }

    std::cout << "Users With " ;
    if (choice == 1) {
        if (accountType == 1) {
            std::cout << "Saving Account:\n";
        } else if (accountType == 2) {
            std::cout << "Checking Account:\n";
        }
    }
    else if (choice == 2){
        if(cardType == 1){
            std::cout << "Mastercard:\n";
        }
        else if(cardType == 2){
            std::cout << "Visa Card:\n";
        }
        else if(cardType == 3){
            std::cout << "Local Card:\n";
        }
    }

    std::ostringstream text;
    std::ifstream in_file("customer_info.txt");

    if(in_file.is_open()){
        //int lineNum = 0;
        text << in_file.rdbuf();

        int userNamePos;
        std::string str = text.str();
        //std::cout << str;
        int position1 = 0;

        do{
            if(choice == 1){
                position1 = str.find("AccountType:" + std::to_string(accountType),position1+1);

            }
            else{
                position1 = str.find("CardType:" + std::to_string(cardType),position1+1);
            }

            //std::cout <<std::endl << position1 <<std::endl;
            if(position1 == -1){
                //std::cout << "Section break";
                break;
            }

            /*if(position1 != 0){

                position1--;
            }*/
            //std::cout << position1;
            //std::cout << str.substr(position1,str.size());

                userNamePos = str.find("username:",position1);
            int userNamePos1 = str.find('\n',userNamePos);

            std::string userName = str.substr(userNamePos,userNamePos1-userNamePos);

            userName = userName.substr(9);
            std::cout << "\n**********" << userName <<"**********"<< std::endl;
            getAccountHoldersInfo(userName);

        }while(position1 != -1);
        in_file.close();


    }
}

void Employee::depositAmount() {
    std::string user;
    long double deposit;
    std::cout << "Enter Customer Username to deposit to: ";
    std::cin >> user;

    getAccountHoldersInfo(user);

    std::cout << "\nDeposit Amount: ";
    std::cin >> deposit;

    if(holder.getAccountType() == 1){
        holder.accountType->setGovtTax(deposit*0.005);
    }
    updateBalance(holder.getCurrentbalance()+deposit-holder.accountType->getGovtTax(),user);

    logTransaction(deposit,holder.getCurrentbalance()+deposit-holder.accountType->getGovtTax(),user, 1);

}




