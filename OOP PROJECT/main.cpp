using namespace std;
#include "Date.cpp"
#include "BankUser.cpp"
#include "Customer.h"
#include "Employee.h"
#include<iostream>
int main()
{
    srand(time(0));

//Date date;

//AccountHolder accountHolder("Muhammad", "Ahsan", "Farooq", "home",date , 034321 , 234, 1, 1);

//Variables
    int loginType;
    std::string username;
    std::string password;
    int choice;
    string cardNum;
    string cnic;
    int accNum;
    double withdrawAmount;

    cout << "-----WELCOME TO AIR BANKING SYSTEM-----" << endl;
    cout << "-----BY: YAHYA BIN NAVEED      || 210999-----" << endl;
    cout << "-----BY: MUHAMMAD AHSAN FAROOQ || 211023-----" << endl;
    cout << "-----BY: MUHAMMAD HASHAAM AWAN || 210981-----" << endl;
    cout << "-----TESTED BY: MUJTABA SHAHID || IRON 1-----" << endl;

    cout << "LOGIN: " << endl;
    cout << ">EMPLOYEE (1) \n>CUSTOMER (2)" << endl;
    cin >> loginType;

    switch(loginType)
    {
        case 1://Employee
        {
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            Employee employee(username, password);

            if(employee.isLoggedIn()){
                cout << "\n\nWELCOME TO MANAGER ACCOUNT\n"
                        "\n[1 to create new customer account]"
                        "\n[2 to delete existing customer account]"
                        "\n[3 to update any customer's details]"
                        "\n[4 find a account holder]"
                        "\n[5 to display account holders of a specific Account Type/Card Type]"
                        "\n[6 to deposit amount into a customer's account]";
                cin >> choice;
                switch(choice){
                    case 1:
                    {
                        employee.createAccountHolder();
                        break;
                    }
                    case 2:
                    {
                        employee.deleteAccountHolder();
                        break;
                    }
                    case 3:
                    {
                        employee.updateAccountHolderInfo();

                        break;
                    }
                    case 4:
                    {
                        employee.findAccountHolder();

                        break;
                    }
                    case 5:
                    {
                        employee.displayAccountHolders();

                        break;
                    }
                    case 6:
                    {
                        employee.depositAmount();

                        break;
                    }
                }
            }

        }
        break;

        case 2: //Customer
        {
              cout << "Username: ";
              cin >> username;
              cout << "Password: ";
              cin >> password;
              Customer customer(username, password);
              if(customer.isLoggedIn()){
                  cout << "\n\nWELCOME TO CUSTOMER ACCOUNT\n"
                          "\n[1 to get mini statement]"
                          "\n[2 to withdraw using credit card number]"
                          "\n[3 to withdraw using account number AND CNIC]"
                          "\n[4 for balance inquiry]"
                          "\n[5 to display transaction history]"
                          "\n[6 to deposit amount into a customer's account]";
                  cin >> choice;

                  switch(choice){
                      case 1:
                      {
                          cout <<"Account Number: ";
                          cin >> accNum;
                          cout <<"CNIC: ";
                          cin >> cnic;

                          customer.getMiniStatement(accNum, cnic);

                          break;
                      }
                      case 2:
                      {
                          cout <<"Credit Card Number: ";
                          cin >> cardNum;
                          cout <<"WithdrawAmount: ";
                          cin >> withdrawAmount;

                          cout << customer.withdraw(cardNum,withdrawAmount);


                      }
                          break;
                      case 3:
                      {
                          cout <<"Account Number: ";
                          cin >> accNum;
                          cout <<"CNIC: ";
                          cin >> cnic;
                          cout <<"WithdrawAmount: ";
                          cin >> withdrawAmount;

                          cout << customer.withdraw(accNum,cnic,withdrawAmount);
                          break;
                      }
                      case 4:
                      {
                          cout <<"Account Number: ";
                          cin >> accNum;
                          cout <<"CNIC: ";
                          cin >> cnic;
                          customer.balanceInquiry(accNum,cnic);

                          break;
                      }
                      case 5:
                      {
                          cout <<"Account Number: ";
                          cin >> accNum;
                          cout <<"CNIC: ";
                          cin >> cnic;

                          customer.getTransactionHistory(accNum, cnic);

                          break;
                      }
                  }

              }
        }

        break;
    }


}


