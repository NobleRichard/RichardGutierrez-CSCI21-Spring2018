#include "Base.h"
#include "Corporate.h"
#include "Platinum.h"
#include "Gold.h"



int main(){
    int  i = 0;
    int SIZE = 0; //holds length of card vector
    int ReceiptLength = 0; //will hold length transaction vector
    string file1, file2;
    stringstream ss, sa;
    ifstream fin, fin2; //input file stream
    ofstream fout; //ouptut file stream
    fin.open("PartB1.txt");
    
    vector <long> CardNumbers;     //the vecotrs are where I hold all of the card information
    vector <string> FirstNames;   
    vector <string> SecondNames;   
    vector <string> Type;              
    vector <double> Balances;
    
    long cardnum;                   //the types that hold the info before going into vectors
    string firstna;
    string lastna;
    string accounttype;
    double balan;
    
    while (!fin.eof()){
        getline(fin, file1);
        ss.clear();
        ss << file1;
        ss >> cardnum;
        ss >> firstna;
        ss >> lastna;
        ss >> accounttype;
        ss >> balan;
        
        CardNumbers.push_back(cardnum);
        FirstNames.push_back(firstna);
        SecondNames.push_back(lastna);
        Type.push_back(accounttype);
        Balances.push_back(balan);
        
        ++SIZE;                         //checks how many lines of input you will have and then assigns it to the size of the vectors
    }
    
    fin.close();
    fin2.open("PartB2.txt");
    
    long cardpurch;           //hold info being put into vectors
    string date;
    string stor;
    double deduction;
    
    vector <long> CardPerson;       //real memory holder
    vector <string> Date;
    vector <string> Store;
    vector <double> Price;
     
    
    
    while (!fin2.eof()){
        getline(fin2, file2);
              std::size_t found = file2.find_first_of( ":");   // erases the colons in the grabbed line
              while (found!=std::string::npos)
                 {
                 file2[found] = ' ';
                 found = file2.find_first_of( ":", found+1);
                 }
        
        sa.clear();
        sa << file2;
        sa >> cardpurch;
        sa >> date;
        sa >> stor;
        sa >> deduction;
        
        CardPerson.push_back(cardpurch);
        Date.push_back(date);
        Store.push_back(stor);
        Price.push_back(deduction);
     
     
        ++ReceiptLength;
    };
    
    vector <Corporate> Corprated (Corporate());
    vector <Platinum> Plat (Platinum());
    vector <Gold> Au (Gold());
    
    for (int i = 0; i < SIZE; i++){
        
    }
    
    

    for (int i = 0; i < SIZE; i++){  //to check outputs
        
        cout << CardNumbers.at(i) << " "<< FirstNames.at(i) << " " << SecondNames.at(i) << " " << Type.at(i) << " " << Balances.at(i) << endl;
        cout << CardPerson.at(i) << " " << Date.at(i) << "   " << Store.at(i) << " " << Price.at(i) << endl << endl;
        /*
        for (int j = 0; j < ReceiptLength; j++){
            if (CardPerson.at(j) == CardNumbers.at(i)){
                cout << Month.at(j) << "/" << Day.at(j) << "/" << Year.at(j) << "   " << Store.at(j) << endl;
            }
            else {
                cout << "No purchases this month." << endl;
            }
        } */
    }
    //assigns the card number, names, card type and balances into vectors
    
    //for (i = 0; i < SIZE; i++){
        
    //}
    fin2.close();
    


    

    
    
    
    
    
    
    
    
    
    
    
    return 0;
}