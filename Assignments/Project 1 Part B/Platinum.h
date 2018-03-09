#include "Base.h"

/*
Platinum Card

Credit line is $5,000
An overdraft of $1,000 is allowed. A warning message is issued through the account summary
Each month, a rebate of 2% of the total monthly purchase is awarded to the account
*/
class Platinum : public CreditCard{
  private:
    double credit_;
    double overdraft_;
    double rebate_;
    long cardholder_;
    string date_;
    string store_;
    double price_;
    bool CreditCheck_;            //check1
    bool CardTypeBalanceCheck_;   //check2
    bool LuhnValid_;              //check3
    
  public:
    Platinum(double cred = 5000.0, double overd  = 1000.0, double reb  = .02);
    void SetCredit(double cred);
    double GetCredit();
    void SetOverDraft(double over);  
    double GetOverDraft();
    void SetRebate(double reb);
    double GetRebate();
    
    
    
    void Luhns_Algorithm(string Num);  //checks validity of credit card
    
    void CheckCardBalance(string mem, double bal); //will check the balance and regarding which type it is 
    
    void CheckLimit(double lim, double cred);  //checks if transaction is too much
    

};