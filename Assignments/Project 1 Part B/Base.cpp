#include "Base.h"

    CreditCard::CreditCard(){
        cardnumber_ = 0;
        firstname_ = "John";
        lastname_ = "Doe";
        membership_ = "Gold";
        balance_ = 0;
        LuhnValid_ = true;
        CreditCheck_ = true;
        CardTypeBalanceCheck_ = true;
    }
    CreditCard::CreditCard(long num, string first, string last, string mem, bool x, bool y, bool z){ 
        cardnumber_ = num;
        firstname_ = first;
        lastname_ = last;
        membership_ = mem;
        LuhnValid_ = x;
        CreditCheck_ = y;
        CardTypeBalanceCheck_ = z;
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
    void CreditCard::SetMembership(int mem){
        membership_ = mem;
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
    
    

    

void CreditCard::PrintDeclineStatus(){
    
    
}



