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
    
bool Corporate::Luhns_Algorithm(long num) {
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

bool Corporate::CheckCardBalance(double bal){ //will check the balance and regarding which type it is 
    if ( bal < 10000.0){
        return true;
    }
    else{
        return false;
    }
}

bool Corporate::CheckLimit(double bal, double price){  //checks if transaction is too much
    if ( price > (bal + 5000) ){
        return false;
    }
    else{
        return true;
    }
}

double Corporate::Transaction(double bal, double price, string stor, string date, int h){ //Computes the transaction and assigns it to the  new balance
    if (bal >= price && bal >= 0){
        cout << "Transaction processed: " << date << " " << "BY " << stor << " Transaction #" << h << endl;
        cout << "$" << bal << " - $" << price << " = $" << bal - price << endl;
        rebate_ = rebate_ + (price * .05);
        bal = bal - price;
        cout << "                        You have $" << bal << " remaining." <<  endl;
    }
    else if (price > bal || bal < 0){
    
        cout << "Transaction processed but overdrafted: " << date << " " << "BY " << stor << " Transaction #" << h << endl;
        cout << "$" << bal << " - $" << price << " = $" << bal - price << endl;
        rebate_ = rebate_ + (price * .05);
        bal = bal - price;
        cout << "                        You have $" << (5000 + bal) << " remaining." <<  endl;
        cout << "                        You currently owe $" << - (bal)  << endl;
        
    }
    return bal;
}

void Corporate::Output1(){
    cout << GetFirstName() << " " << GetLastName() << " " << GetCardNumber() << " " << GetMembership() << endl;
    SetOverDraft(5000.0);
    
}

void Corporate::Output2(){
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

void Corporate::Output3(){
    cout << "Your total rebate for this month is: $" << GetRebate() << endl;
}
