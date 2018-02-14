#ifndef item_h
#define item_h
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

class Item {
    private:
    string name_;                //holds the name of the item
    unsigned int value_;         //holds the value of the item
    
    public:
    Item(){
        name_ = "item";
        value_ = 0;
    }
    Item(string label, int cost){
        name_ = label;
        value_ = cost;
    }
    
    void set_name(string label){
        name_ = label;
    }
    string name(){
        return name_;
    }
    
    void set_value(int cost){
        value_ = cost;
    }
    int value(){
        return value_;
    }

    string ToString(){
        stringstream holder;
        holder << name_ << ", &" << value_ << endl;
        string tempHolder;
        holder >> tempHolder;
        return tempHolder;
    }
    virtual ~Item();
};
#endif