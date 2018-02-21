#include "Corporate.h"


Corporate::Corporate(double cred, double overd, double reb){
    credit_ = cred;
    overdraft_ = overd;
    rebate_ = reb;
}


    //Card Checks
    
void Corporate::Luhns_Algorithm(string Num) {
    int x = 0;
    int z = 0;
    int digit = 0;
    stringstream strluhn;
    int cardCheck = 0;
    
    strluhn << Num; //moves string into stringstream
    strluhn >> cardCheck;  //then from stringstream into int
    
    int Numarray[Num.size() - 1];
    
    x = (cardCheck % 2);
    
    for(int i = 0;i < Num.size();i++) {
        Numarray[i] = (Num.at(i) - 48); 
    }
    
    
    for(int i = 0;i < (Num.size() - 1);i++) {
        digit = Numarray[i];
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
    for (int i = 0 ; i < Num.size(); i++){
        cout << Numarray[i] << " ";
    }
    cout <<"sum " << x << " then " << Numarray[Num.size() - 1] << endl;
    if((x % 10) == Numarray[Num.size() - 1]) {
        
        LuhnValid_ = true;
    }
    else{
        
        LuhnValid_ = false;
    }
}

