#include "Base.cpp"
#include "Corporate.cpp"
#include "Platinum.cpp"
#include "Gold.cpp"

int main(){
    int  i = 0;
    int SIZE = 0; //holds length of card vector
    int g = 0;
    int ga = 1;
    int c = 0;
    int ca = 1;
    int p = 0;
    int pa = 1;
    int ReceiptLength = 0; //will hold length transaction vector
    bool holding1;
    bool holding2;
    bool holding3;
    string file1, file2;
    stringstream ss, sa;
    ifstream fin, fin2; //input file stream
    ofstream fout; //ouptut file stream
    fin.open("PartB1.txt");
    fin2.open("PartB2.txt");
    
    vector <long> CardNumbers;     //the vecotrs are where I hold all of the card information
    vector <string> FirstNames;   
    vector <string> SecondNames;   
    vector <string> Type;              
    vector <double> Balances;

    
    vector <Corporate> Corp;    //object vectors
    vector <Platinum> Plat;
    vector <Gold> Au;
    
    long cardnum;                   //the types that hold the info before going into second set of vectors
    string firstna;
    string lastna;
    string accounttype;
    double balan;
    
    
    long cardpurch;           //hold info being put into vectors
    string date;
    string stor;
    double deduction;
    
    vector <long> CardPerson;       //real memory holder
    vector <string> Date;
    vector <string> Store;
    vector <double> Price;    
   
    while(!fin2.eof()){
        getline(fin2, file2);
        std::size_t found = file2.find_first_of( ":");   // erases the colons in the grabbed line
          while (found!=std::string::npos){
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
        }
    
    /////////Now the second file
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
        
        //////Start putting info into object if statements to determin what object is made
        if (accounttype == "Gold" || accounttype == "gold"){
            Au.push_back(Gold());
            Au.at(g).SetCardNumber(cardnum);
            Au.at(g).SetFirstName(firstna);
            Au.at(g).SetLastName(lastna);
            Au.at(g).SetMembership(accounttype);
            Au.at(g).SetLuhns(Au.at(g).Luhns_Algorithm(cardnum));   //check 3
            Au.at(g).SetCardType(Au.at(g).CheckCardBalance(balan));  //check 2
            Au.at(g).SetRebate(0.0);
            Au.at(g).Output1();
            for (int i = 0; i < ReceiptLength; i++){
                if (CardPerson.at(i) == cardnum){
                    holding1 = Au.at(g).CheckLimit(balan, Price.at(i));  //check 1
                    holding2 = Au.at(g).GetLuhns();
                    holding3 = Au.at(g).GetCardTypeBalCheck();
                    
                    if (holding1 == true && holding2 == true && holding3 == true){ 
                        balan = Au.at(g).Transaction(balan, Price.at(i), Store.at(i), Date.at(i), ga);
                        Au.at(g).SetBalance(balan);
                        Au.at(g).SetCreditCheck(holding1);
                        ++ga;
                    }
                    else{
                        Au.at(g).SetCreditCheck(false);
                    }
                }
                
            }
            Au.at(g).Output2();
            
                 
            ++g;
            
        }
        else if (accounttype == "Corporate" || accounttype == "corporate"){
           
            ++c;
        }
        else if (accounttype == "Platinum" || accounttype == "platinum"){
            Plat.at(p).Luhns_Algorithm(cardnum);
            
            Plat.push_back(Platinum());
            
            ++p;
        }
        else{
            cout << "What?" << endl;
        }        
    }
        

    fin.close();
    fin2.close();
     
  
    

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
    
    


    

    
    
    
    
    
    
    
    
    
    
    
    return 0;
}


