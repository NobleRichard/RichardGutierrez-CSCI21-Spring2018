#include "item.h"
#ifndef magic_item.h
#define magic_item.h

class MagicItem : public Item{
    private:
    string description_;                //holds a description of the magic item
    unsigned int mana_required_;        //holds the amount of mana required to use the magic item
    
    public:
    MagicItem(){
        set_name("magicitem");
        set_value(0);
        description_ = "no description";
        mana_required_ = 0;
    }    
    MagicItem(string label, int cost, string things, int fp){
        set_name(label);
        set_value(cost);
        description_ = things;
        mana_required_ = fp;
    }
    void set_description(string things){
        description_ = things;
    }
    string description(){
        return description_;
    }
    void set_mana_required(int fp){
        mana_required_ = fp;
    }
    int mana_required(){
        return mana_required_;
    }
    string ToString(){
        stringstream holder;
        holder << Item::ToString() << ", " << description_ << ", requires " << mana_required_ << " mana";
        string tempHolder;
        holder >> tempHolder;
        return tempHolder;
    }
    
    virtual ~MagicItem();
};
#endif