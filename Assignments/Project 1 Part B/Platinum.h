#ifndef PLATINUM_H
#define PLATINUM_H

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
    Platinum();
    Platinum(double cred, double overd, double reb, long holder, string day, string company, double prices, bool check1, bool check2, bool check3, long num, string first, string last, string mem, double bal) : CreditCard(num, first, last, mem, bal){
    credit_ = cred;
    overdraft_ = overd;
    rebate_ = reb;
    cardholder_ = holder;
    date_ = day;
    store_ = company;
    price_ = prices;
    CreditCheck_ = check1;
    CardTypeBalanceCheck_ = check2;
    LuhnValid_ = check3;
    
    
        SetCardNumber(num);
        SetFirstName(first);
        SetLastName(last);
        SetMembership(mem);
        SetBalance(bal);
    };
    
    
    void SetCredit(double cred);
    void SetOverDraft(double over); 
    void SetRebate(double reb);
    void SetCardHolder(long holder);
    void SetDate(string day);
    void SetStore(string company);
    void SetPrice(double prices);
    void SetCreditCheck(bool check1);
    void SetCardType(bool check2);
    void SetLuhns(bool check3);
    
    double GetCredit();
    double GetOverDraft();
    double GetRebate();
    long GetCardHolder();
    string GetDate();
    string GetStore();
    double GetPrice();
    bool GetCardTypeBalCheck();
    bool GetCardType();
    bool GetLuhns();
    
    double Transaction(double bal, double price, string stor, string date, int h); //Computes the transaction and assigns it to the  new balance
    
    
    bool Luhns_Algorithm(long num);  //checks validity of credit card
    
    bool CheckCardBalance(double bal); //will check the balance and regarding which type it is 
    
    bool CheckLimit(double bal, double price);  //checks if transaction is too much
    
    void Output1(); //outputs the name, card number of person, and card type
    
    void Output2(); //outputs if a card didnt go through and for what reason
    
    void Output3(); //outputs rebate
    
};
#endif