#include "Corporate.h"

Corporate::Corporate(){
    credit_ = 10000.0;
    overdraft_ = 5000.0;
    rebate_ = .05;
    CreditCheck_ = true;
    CardTypeBalanceCheck_ = true;
    LuhnValid_ = true;
}



////////////////////////////////////////////////////////////////////////////
//sets and gets
    void Corporate::SetCredit(double cred){
        credit_ = cred;
    }
    void Corporate::SetOverDraft(double over){
        overdraft_ = over;
    } 
    void Corporate::SetRebate(double reb){
        rebate_ = reb;
    }
    void Corporate::SetCardHolder(long holder){
        cardholder_ = holder;
    }
    void Corporate::SetDate(string day){
        date_ = day;
    }
    void Corporate::SetStore(string company){
        store_ = company;
    }
    void Corporate::SetPrice(double prices){
        price_ = prices;
    }
    void Corporate::SetCreditCheck(bool check1){
        CreditCheck_ = check1;
    }
    void Corporate::SetCardType(bool check2){
        CardTypeBalanceCheck_ = check2;
    }
    void Corporate::SetLuhns(bool check3){
        LuhnValid_ = check3;
    }
    
    double Corporate::GetCredit(){
        return credit_;
    }
    double Corporate::GetOverDraft(){
        return overdraft_;
    }
    double Corporate::GetRebate(){
        return rebate_;
    }
    long Corporate::GetCardHolder(){
        return cardholder_;
    }
    string Corporate::GetDate(){
        return date_;
    }
    string Corporate::GetStore(){
        return store_;
    }
    double Corporate::GetPrice(){
        return price_;
    }
    bool Corporate::GetCardTypeBalCheck(){
        return CreditCheck_;
    }
    bool Corporate::GetCardType(){
        return CardTypeBalanceCheck_;
    }
    bool Corporate::GetLuhns(){
        return LuhnValid_;
    }

///////////////////////////////////////////////////////////////////////////////////
    //Card Checks
    
void Corporate::Luhns_Algorithm() {
    int x = 0;
    int z = 0;
    int digit = 0;
    stringstream strluhn; 
    int cardCheck = 0;
    
    
    vector <long> Numarray(sizeof(cardnumber_));
    
    x = (cardnumber_ % 2);
    
    for(int i = 0; i < sizeof(cardnumber_); i++) {
        Numarray.at(i) = (sizeof(cardnumber_) - 48); 
    }
    
    for(int i = 0;i < sizeof(cardnumber_);i++) {
        digit = Numarray.at(i);
        if(i % 2 == 0) {
            digit *= 2;
                if(digit > 9) {
                digit -= 9;
                //x += digit;
                }
                else {
                   // x+= digit;
                    }
                //x += digit;
        }
        x += digit;
        cout << digit << " " << endl;
    }
    x = x * 9;
    for (int i = 0 ; i < sizeof(cardnumber_); i++){
        cout << Numarray.at(i) << " ";
    }

    if((x % 10) == Numarray.at(sizeof(cardnumber_))) {
        
        LuhnValid_ = true;
    }
    else{
        
        LuhnValid_ = false;
    }
}

