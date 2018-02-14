/*
 * Name        : lab_6.cpp
 * Author      : Richard Gutierez
 * Description : Working with Arrays
 */

#include "lab_6.h"


string PrepareForDisplay(int values[], int size, char separator){
    stringstream ss;
    string display;
    
    for(int i = 0; i < size; i++){
        ss << values[i] ;
        while((i + 1) < size){
            ss << separator;
        }
    }
    ss >> display;
    
    return display;
}

bool HasValue(int values[], int size, int value){
    for (int i = 0; i < size; i++){
        if(values[i] == value){
            return true;
            }
        }
        return false;
}
    

int ValueAt(int values[], int size, int index, bool &error){
    
    for (int i = 0; i < size; i++){
        if(index == i){
            error = false;
            return values[i];
        }
        else {
            error = true;
            return 0;
        }
    }
}


int Sum(int values[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum = +values[i];
    } 
    return sum;
}

bool SwapValues(int values[], int size, int index1, int index2){
    
    for(int i = 0; i < size; i++){
        if(index1 < size && index1 >=0 && index2 < size && index2 >=0){
            int holder;
            holder = values[index1];
            values[index1] = values[index2];
            values[index2] = holder;
            return true;
        }
    }
}