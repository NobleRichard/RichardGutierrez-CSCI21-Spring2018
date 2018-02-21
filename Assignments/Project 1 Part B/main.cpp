#include "Base.h"
#include "Corporate.h"
#include "Platinum.h"
#include "Gold.h"



int main(){
    int  i = 0;
    int SIZE = 0;
    string line;
    stringstream ss;
    ifstream fin; //input file stream
    ofstream fout; //ouptut file stream
    fin.open("PartB1.txt");
    
    while (getline(fin, line)){
        ++SIZE;                         //checks how many lines of input you will have and then assigns it to the size of the vectors
    }
    cout << SIZE;
    
    
    vector <CreditCard> Cards(SIZE);
    vector <long> CardNumbers(SIZE);    
    vector <string> FirstNames(SIZE);   
    vector <string> SecondNames(SIZE);   
    vector <string> Type(SIZE);              
    vector <double> Balances(SIZE);
    
    Cards.push_back(CreditCard());
    
    while (!fin.eof()){
        
        fin >> CardNumbers.at(i);
        fin >> FirstNames.at(i);
        fin >> SecondNames.at(i);
        fin >> Type.at(i);
        fin >> Balances.at(i);
        
        i++;
    }
    //assigns the card number, names, card type and balances into vectors
    
    //for (i = 0; i < SIZE; i++){
        
    //}
    fin.close();  
    


    

    
    
    
    
    
    
    
    
    
    
    
    return 0;
}