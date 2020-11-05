#include "cards.hh"
#include <iostream>

using namespace std;

// TODO: Implement the methods here
Cards::Cards(): top_(nullptr){
}

Cards::~Cards(){
    while(top_ != nullptr){
        Card_data* item = top_;
        top_ = top_->next;

        delete item;
    }
}

void Cards::add(int id)
{
    Card_data* new_item = new Card_data{id, nullptr};
    if(top_ == nullptr){
        top_ = new_item;
    }
    else{
        new_item->next = top_;
        top_ = new_item;
    }
}


bool Cards::remove(int &id)
{
    if(top_ == nullptr){
        return false;
    }
    else{
        Card_data* item = top_;
        id = item->data;
        top_ = top_->next;
        delete  item;
        return true;
    }

}

bool Cards::bottom_to_top()
{
    if(top_ == nullptr){
        return false;
    }

        if(top_->next == nullptr){
            return true;
        }
        else{
        Card_data* last = top_;
        Card_data* secLast = NULL;
        while(last->next != nullptr){
            secLast = last;
            last = last->next;
        }
        secLast->next = nullptr;
        last->next = top_;
        top_ = last;
        return  true;
        }

}

bool Cards::top_to_bottom()
{
    if(top_ == nullptr){
        return false;
    }

        if(top_->next == nullptr){
            return true;
        }
        else{
        Card_data* last = top_;
        Card_data* first = top_;
        while(last->next != nullptr){
            last = last->next;
        }
        top_ = first->next;
        first->next = nullptr;
        last->next = first;
        return  true;
        }

}


void Cards::print_from_top_to_bottom(ostream &s)
{
    Card_data* item = top_;
    int num = 1;
    while(item != nullptr){
        s << num << ": " << item->data << endl;
        ++num;
        item = item->next;
    }
}

void Cards::recursive_print(Cards::Card_data *top, ostream &s)
{
    int num =1;
    if(top != nullptr){

        recursive_print(top->next, s);

        s << num << ": " << top->data << endl;
        ++num;
    }
}

void Cards::print_from_bottom_to_top(ostream &s)
{
    recursive_print(top_, s);
}

