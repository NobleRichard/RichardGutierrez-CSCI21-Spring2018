//Richard Gutierrez

//Credit Card
#include "Base.h"

    CreditCard::CreditCard(){
        cardnumber_ = 0;
        firstname_ = "John";
        lastname_ = "Doe";
        membership_ = "Gold";
        balance_ = 0;
    }
    CreditCard::CreditCard(long num, string first, string last, string mem, double bal){ 
        cardnumber_ = num;
        firstname_ = first;
        lastname_ = last;
        membership_ = mem;
        balance_ = bal;
    }
    void CreditCard::SetCardNumber(long num){
        cardnumber_ = num;
    }
    void CreditCard::SetFirstName(string first){
        firstname_ = first;
    }
    void CreditCard::SetLastName(string last){
        lastname_ = last;
    }
    void CreditCard::SetMembership(string mem){
        membership_ = mem;
    }
    void CreditCard::SetBalance(double bal){
        balance_ = bal;
    }
    long CreditCard::GetCardNumber(){
        return cardnumber_;
    }
    string CreditCard::GetFirstName(){
        return firstname_;
    }
    string CreditCard::GetLastName(){
        return lastname_;
    }
    string CreditCard::GetMembership(){
        return membership_;
    }
    double CreditCard::GetBalance(){
        return balance_;
    }