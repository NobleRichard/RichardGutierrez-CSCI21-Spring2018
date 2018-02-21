#include "Base.h"
/*
Gold Card

Credit line $3,000
Once limit is reached, the card will be blocked
Each month, a rebate of 1% of the total monthly purchase is awarded to the account
*/
class Gold : public CreditCard{
  private:
    double credit_;
    double overdraft_;
    double rebate_;
    
  public:
    Gold(double cred = 3000.0, double overd  = 0.0, double reb  = .01);
    void SetCredit(double cred);
    double GetCredit();
    void SetOverDraft(double over);  
    double GetOverDraft();
    void SetRebate(double reb);
    double GetRebate();
    
    
    
    bool Luhns_Algorithm(string Num);  //checks validity of credit card
    
    bool CheckCardBalance(string mem, double bal); //will check the balance and regarding which type it is 
    
    bool CheckLimit(double lim, double cred);  //checks if transaction is too much
      

};