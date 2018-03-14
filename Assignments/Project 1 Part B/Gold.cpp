#include "Gold.h"

Gold::Gold(){
    credit_ = 3000.0;
    overdraft_ = 0.0;
    rebate_ = .01;
    CreditCheck_ = true;
    CardTypeBalanceCheck_ = true;
    LuhnValid_ = true;
}



////////////////////////////////////////////////////////////////////////////
//sets and gets
    void Gold::SetCredit(double cred){
        credit_ = cred;
    }
    void Gold::SetOverDraft(double over){
        overdraft_ = over;
    } 
    void Gold::SetRebate(double reb){
        rebate_ = reb;
    }
    void Gold::SetCardHolder(long holder){
        cardholder_ = holder;
    }
    void Gold::SetDate(string day){
        date_ = day;
    }
    void Gold::SetStore(string company){
        store_ = company;
    }
    void Gold::SetPrice(double prices){
        price_ = prices;
    }
    void Gold::SetCreditCheck(bool check1){
        CreditCheck_ = check1;
    }
    void Gold::SetCardType(bool check2){
        CardTypeBalanceCheck_ = check2;
    }
    void Gold::SetLuhns(bool check3){
        LuhnValid_ = check3;
    }
    
    double Gold::GetCredit(){
        return credit_;
    }
    double Gold::GetOverDraft(){
        return overdraft_;
    }
    double Gold::GetRebate(){
        return rebate_;
    }
    long Gold::GetCardHolder(){
        return cardholder_;
    }
    string Gold::GetDate(){
        return date_;
    }
    string Gold::GetStore(){
        return store_;
    }
    double Gold::GetPrice(){
        return price_;
    }
    bool Gold::GetCardTypeBalCheck(){
        return CreditCheck_;
    }
    bool Gold::GetCardType(){
        return CardTypeBalanceCheck_;
    }
    bool Gold::GetLuhns(){
        return LuhnValid_;
    }

///////////////////////////////////////////////////////////////////////////////////
    //Card Checks
    
bool Gold::Luhns_Algorithm(long num) {
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

bool Gold::CheckCardBalance(double bal){ //will check the balance and regarding which type it is 
    if ( bal < 3000.0){
        return true;
    }
    else{
        return false;
    }
}

bool Gold::CheckLimit(double bal, double price){  //checks if transaction is too much
    if ( price > bal ){
        return false;
    }
    else{
        return true;
    }
}

double Gold::Transaction(double bal, double price, string stor, string date, int h){ //Computes the transaction and assigns it to the  new balance
    cout << "Transaction processed: " << date << " " << "BY " << stor << endl;
    cout << "$" << bal << " - $" << price << " = $" << bal - price << endl;
    rebate_ = rebate_ + (price * .01);
    bal = bal - price;
    cout << "                        You have $" << bal << " remaining." <<  endl;
    
    return bal;
}

void Gold::Output1(){
    cout << GetFirstName() << " " << GetLastName() << " " << GetCardNumber() << " " << GetCardType() << endl;
}

void Gold::Output2(){
    if(LuhnValid_ != true){
        cout << "Your Credit Card number is not a valid number. So no transactions went through." << endl;
    }
    if(CreditCheck_ != true){
        cout << "Your account balance was not sufficient for a transaction." << endl;
    }
    if(CardTypeBalanceCheck_ != true){
        cout << "Your account had a problem with the balance and so no transactions were processed. Call your local bank for help."<< endl;
    }
    else{
        cout << "Congratulations on using your credit card wisely." << endl;
    }
}

void Gold::Output3(){
    cout << "Your total rebate for this month is: $" << GetRebate();
}
