#include "Base.h"

/*
Corporate Card

Credit line of $10,000
An overdraft of $5, 000 is allowed. A warning message is issued through the account summary
Each month, a rebate of 5% of the total monthly purchase is awarded to the account. */
class Corporate : public CreditCard{
  private:
    double credit_;
    double overdraft_;
    double rebate_;
    
  public:
    Corporate(double cred = 10000.0, double overd  = 5000.0, double reb  = .05);
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