#include <iostream>
#include <cmath>

using namespace std;




int factorial(int y){
    //base condition of recursion
    if(y == 0){
        return 1;
    }
    //call function recursively
    if(y > 0){
        return y * factorial((y - 1));
    }
}

int main(){
    int x;
    cout << "Input a number you want to factiorial." << endl;
    cin >> x;
    cout << factorial(x) << endl;
    return 0;
}
