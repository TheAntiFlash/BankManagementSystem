cmake_minimum_required(VERSION 3.21)
project(Account_Holder)

set(CMAKE_CXX_STANDARD 14)

add_executable(Account_Holder main.cpp AccountHolder.cpp AccountHolder.h AccountType.cpp AccountType.h CheckingAccount.cpp CheckingAccount.h SavingAccount.cpp SavingAccount.h CreditCard.cpp CreditCard.h MasterCard.cpp MasterCard.h VisaCard.cpp VisaCard.h LocalCard.cpp LocalCard.h Person.cpp Person.h Employee.cpp Employee.h Customer.cpp Customer.h)
