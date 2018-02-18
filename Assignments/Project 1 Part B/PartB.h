#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
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

There are 3 types of credit cards:

Gold Card

Credit line $3,000
Once limit is reached, the card will be blocked
Each month, a rebate of 1% of the total monthly purchase is awarded to the account
Platinum Card

Credit line is $5,000
An overdraft of $1,000 is allowed. A warning message is issued through the account summary
Each month, a rebate of 2% of the total monthly purchase is awarded to the account
Corporate Card

Credit line of $10,000
An overdraft of $5, 000 is allowed. A warning message is issued through the account summary
Each month, a rebate of 5% of the total monthly purchase is awarded to the account. */

using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::stringstream;
using std::setprecision;
using std::fstream;




class CreditCard{
  private:
    long long cardnumber_;
    string firstname_;
    string lastname_;
    string membership_;   
    public:
    CreditCard(){
        cardnumber_ = 0;
        firstname_ = "John";
        lastname_ = "Doe";
        membership_ = "Gold";
    }
    CreditCard(long long num, string first, string last, string mem){ 
        cardnumber_ = num;
        firstname_ = first;
        lastname_ = last;
        membership_ = mem;
    }
    void SetCardNumber(long long num){
        cardnumber_ = num;
    }
    void SetFirstName(string first){
        firstname_ = first;
    }
    void SetLastName(string last){
        lastname_ = last;
    }
    void SetMembership(int mem){
        membership_ = mem;
    }
    long long GetCardNumber(){
        return cardnumber_;
    }
    string GetFirstName(){
        return firstname_;
    }
    string GetLastName(){
        return lastname_;
    }
    string GetMembership(){
        return membership_;
    }
};
/*
Gold Card

Credit line $3,000
Once limit is reached, the card will be blocked
Each month, a rebate of 1% of the total monthly purchase is awarded to the account
*/
class Gold : public CreditCard{
  private:
    
    
  public:
    
    

};
/*
Platinum Card

Credit line is $5,000
An overdraft of $1,000 is allowed. A warning message is issued through the account summary
Each month, a rebate of 2% of the total monthly purchase is awarded to the account
*/
class Platinum : public CreditCard{
  private:
    
    
  public:
    
    

};
/*
Corporate Card

Credit line of $10,000
An overdraft of $5, 000 is allowed. A warning message is issued through the account summary
Each month, a rebate of 5% of the total monthly purchase is awarded to the account. */
class Corporate : public CreditCard{
  private:
    
    
  public:
    
    

};

