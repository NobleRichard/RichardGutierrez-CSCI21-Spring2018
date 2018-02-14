//Richard Gutierrez         2/1/18
//Project 1 Part A: Luhn Algorithm for Digital Validation

/*
Accept input from a text file.  Each line of 
the text file is a sequence of digits with no
spaces between digits, representing a credit card number.

Your program will read in each line of text from the 
file and determine the credit card type by checking 
the BIN.  It is possible that the data file contains 
card numbers from a bank/issuer other than the 4 major 
credit card companies.  Any other card types other than 
the 4 card companies described above are not acceptable 
in your application.  A message of “Unknown card type” 
should be displayed and the card number will be rejected.
*/



#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::stringstream;
using std::setprecision;
using std::fstream;


class Check{
    private:
    string CardCompany_;        //to hold the card 
    long CardNumber_;             //actually holds card number
    int Sum_;                  //Holds the number when summed up
    int Double_;               //Holds the number when you double then add 
    
    public:
    void CheckCards();
    bool Luhns_Algorithm();
    string CheckType();
    
}


//American Express          1
//Discover                  2
//Mastercard                3
//Visa                      4

bool CheckCard(string numbers){ //grab the numbers from string and run Luhns algorithm
    
    stringstream streamnumber(numbers);
  
  while (!isdigit(streamnumber.peek())) {
    streamnumber.ignore(1);                  //grabs the number 
  }

    streamnumber >> CardNum;                   //now inputs the number into a double
    CheckType(CardNum);
}
string CheckType(long PutCardHere){
    PutCardHere.size();
        
    if(PutCardHere == 16){
        if ( )
    }
    else if(PutCardHere == 15){
        if(PutCardHere)
    }
    else if (PutCardHere == 13 || PutCardHere == 14){
         return "Visa";
    }
    else {
       return "Unknown card type";
    }
}
