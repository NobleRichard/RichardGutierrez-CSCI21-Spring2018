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
    string numbers;
    stringstream sup;
    sup << num;
    sup >> numbers;
    
    vector<int> luhn(numbers.length());
    
    int sum = 0;
    int data = 0;
    int check = 0;
    int tempx = numbers.length();
    int tempLS = luhn.size();
    
    for(int i = 0; i < tempx; ++i) {
       luhn.at(i) = numbers.at(i) - 48;
       
    }
    
    for(int i = 0; i < tempLS; i++) {
    }
    
    int parity = luhn.size();
    
    for(int i = luhn.size() - 2; i > -1;i--) {
       
        if(i % 2 == parity % 2) {
            
            data = luhn.at(i) * 2;
            
            if(data > 9) {
                data = data - 9;
            }
        }
        else {
            data = luhn.at(i);
        }
        
        
        sum = sum + data;
    }
    check = (sum * 9) % 10;
    int check2 = luhn.at(luhn.size()-1);
    
    
    sum = sum % 10;
    
    if(check2 == check) {
        return true;
    }   
    else return false;
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
    cout << "Transaction processed: " << date << " " << "BY " << stor << " Transaction #" << h << endl;
    cout << "$" << bal << " - $" << price << " = $" << bal - price << endl;
    rebate_ = rebate_ + (price * .01);
    bal = bal - price;
    cout << "                        You have $" << bal << " remaining." <<  endl;
    
    return bal;
}

void Gold::Output1(){
    cout << GetFirstName() << " " << GetLastName() << " " << GetCardNumber() << " " << GetMembership() << endl;
}

void Gold::Output2(){
    if(LuhnValid_ != true ){
        cout << "Your Credit Card number is not a valid number. Get a real card." << endl << endl;
        if(CreditCheck_ != true){
            cout << "Your account balance was not sufficient for a transaction." << endl << endl;
            if(CardTypeBalanceCheck_ != true){
                cout << "Your account had a problem with the balance and so no transactions were processed. Call your local bank for help."<< endl << endl;
            }
        }
    }
    else if(CreditCheck_ != true){
        cout << "Your account balance was not sufficient for a transaction." << endl << endl;
        if(CardTypeBalanceCheck_ != true){
            cout << "Your account had a problem with the balance and so no transactions were processed. Call your local bank for help."<< endl << endl;
        }
        
    }
    else if(CardTypeBalanceCheck_ != true){
        cout << "Your account had a problem with the balance and so no transactions were processed. Call your local bank for help."<< endl << endl;
    }
    else{
        cout << endl << endl;
    }
}

void Gold::Output3(){
    cout << "Your total rebate for this month is: $" << GetRebate()<< endl;
}
