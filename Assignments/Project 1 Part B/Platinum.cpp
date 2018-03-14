#include "Platinum.h"

Platinum::Platinum(){
    credit_ = 5000.0;
    overdraft_ = 1000.0;
    rebate_ = .02;
    CreditCheck_ = true;
    CardTypeBalanceCheck_ = true;
    LuhnValid_ = true;
}



////////////////////////////////////////////////////////////////////////////
//sets and gets
    void Platinum::SetCredit(double cred){
        credit_ = cred;
    }
    void Platinum::SetOverDraft(double over){
        overdraft_ = over;
    } 
    void Platinum::SetRebate(double reb){
        rebate_ = reb;
    }
    void Platinum::SetCardHolder(long holder){
        cardholder_ = holder;
    }
    void Platinum::SetDate(string day){
        date_ = day;
    }
    void Platinum::SetStore(string company){
        store_ = company;
    }
    void Platinum::SetPrice(double prices){
        price_ = prices;
    }
    void Platinum::SetCreditCheck(bool check1){
        CreditCheck_ = check1;
    }
    void Platinum::SetCardType(bool check2){
        CardTypeBalanceCheck_ = check2;
    }
    void Platinum::SetLuhns(bool check3){
        LuhnValid_ = check3;
    }
    
    double Platinum::GetCredit(){
        return credit_;
    }
    double Platinum::GetOverDraft(){
        return overdraft_;
    }
    double Platinum::GetRebate(){
        return rebate_;
    }
    long Platinum::GetCardHolder(){
        return cardholder_;
    }
    string Platinum::GetDate(){
        return date_;
    }
    string Platinum::GetStore(){
        return store_;
    }
    double Platinum::GetPrice(){
        return price_;
    }
    bool Platinum::GetCardTypeBalCheck(){
        return CreditCheck_;
    }
    bool Platinum::GetCardType(){
        return CardTypeBalanceCheck_;
    }
    bool Platinum::GetLuhns(){
        return LuhnValid_;
    }

///////////////////////////////////////////////////////////////////////////////////
    //Card Checks
    
bool Platinum::Luhns_Algorithm(long num) {
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
        
        return true;
    }
    else{
        
        return false;
    }
}

bool Platinum::CheckCardBalance(double bal){
    if( bal < 5000.0){
        return true;
    }
    else{
        return false;
    }
}

bool Platinum::CheckLimit(double bal, double cred){  //checks if transaction is too much
        if ( cred > bal ){
        return false;
    }
    else{
        return true;
    }
}