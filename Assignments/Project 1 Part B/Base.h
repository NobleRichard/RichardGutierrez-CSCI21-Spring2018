#ifndef PARTB_H
#define PARTB_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>

/*
Your application will read in two sets of input data (2 input files).  The
first set of data includes credit card numbers, the name of the account holder,
the card type (gold, platinum, corporate) and the current balance on each card 
in the format CreditNumber FirstName Last Name Type - CurrentBalance.  
This data will be used to populate an array of credit card objects.

The second set of data include a series of transactions.  
Each transaction’s data include the credit card number, the date, 
a transaction number, the vendor, and a purchase amount in the 
format: CardNumber:00/00/0000:transactNumber:Vendor.  
Depending on the validity of the credit card number, the current 
card credit balance and the credit limit, your application will 
decide if the transaction is to be allowed or denied.  
Your application will also compute the total purchase made on 
the card, and the rebate amount.

The output of your application will be a list of transactions 
that are denied together with the reason for denial and for 
each valid credit card account, create a monthly bill that 
would include the summary of purchases, the total bill on the 
credit card, if there is an overdrawn status on the card, and the rebate value.
*/

using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::stringstream;
using std::setprecision;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::vector;



class CreditCard{
    protected:
    string firstname_;
    string lastname_;
    long cardnumber_;
    string membership_;   
    double balance_;
    bool LuhnValid_;
    bool CreditCheck_;
    bool CardTypeBalanceCheck_;
    
    public:
    CreditCard();
    CreditCard(long num, string first, string last, string mem, double bal);
    
    void SetCardNumber(long num);
    void SetFirstName(string first);
    void SetLastName(string last);
    void SetMembership(int mem);
    
    long GetCardNumber();
    string GetFirstName();
    string GetLastName();
    string GetMembership();
      
    void PrintDeclineStatus();
};
#endif