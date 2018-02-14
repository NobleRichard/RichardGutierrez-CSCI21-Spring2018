#include "item.h"
#ifndef food_item.h
#define food_item.h

class FoodItem : public Item{
    private:
    unsigned int calories_;         //holds a calorie count
    string unit_of_measure_;         //holds the unit of measure (such as "ounces")
    double units_;                  //holds a count of how many units we have
    
    public:
    FoodItem(){
           set_name("fooditem");
           set_value(0);
           calories_ = 0;
           unit_of_measure_ = "nounits";
           units_ = 0;
    }
    FoodItem(string label, int cost, int cal, string unitmeasure, double unit){
           set_name(label);
           set_value(cost);
           calories_ = cal;
           unit_of_measure_ = unitmeasure;
           units_ = unit;
    }    
    
    
    int calories(){
        return calories_;
    }
    void set_calories(int cal){
        calories_ = cal;
    }
    
    void set_unit_of_measure(string unitmeasure){
        unit_of_measure_ = unitmeasure;
    }
    string unit_of_measure(){
        return unit_of_measure_;
    }
    
    double set_units(double unit){
        units_ = unit;
    }
    double units(){
        return units_;
    }
    
    string ToString(){
        stringstream holder;
        holder << Item::ToString() << ", " << setprecision(2) << units_ << " " << unit_of_measure_ << ", " << calories_ << " calories";
        string tempHolder;
        holder >> tempHolder;
        return tempHolder;
    
    }
    virtual ~FoodItem();
};
#endif