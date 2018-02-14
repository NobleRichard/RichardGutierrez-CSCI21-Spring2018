#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int initial_value = 87; //in cents not dollars
    int pennies, dimes, nickles, quarters = 0;
    
    
    quarters = initial_value / 25;
    cout << "Quarters: " << quarters << endl;
    initial_value = initial_value % 25; 
    
    dimes = initial_value / 10;
    cout << "Dimes: " << dimes << endl;
    initial_value = initial_value % 10;
        
    nickles = initial_value / 5;
    cout << "Nickles: " << nickles << endl;
    initial_value = initial_value % 5;
        
    pennies = initial_value;
    cout << "Pennies: " << pennies << endl;
    
    return 0;
}