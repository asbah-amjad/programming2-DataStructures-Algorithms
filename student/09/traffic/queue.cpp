#include "queue.hh"
#include <iostream>
#include <string>

using namespace std;

// Implement the member functions of Queue here

Queue::Queue(unsigned int cycle)
{
    cycle_ = cycle;
}

Queue::~Queue()
{
    while ( first_ != nullptr ) {
          Vehicle* item_to_be_released = first_;
          first_ = first_->next;

          delete item_to_be_released;
       }
    last_ = nullptr;
}

void Queue::enqueue(string reg)
{
    if(!is_green_){
        Vehicle* new_item = new Vehicle{reg, nullptr};
        if(first_ == nullptr){
            first_ = new_item;
            last_ = new_item;
        }
        else{
            last_->next = new_item;
            last_ = new_item;
        }
    }
    else{
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
    }
}

void Queue::switch_light()
{
    if(!is_green_){

        is_green_ = true;  //new color is now green
        unsigned int vehicle_no = sizeQueue();
        if(vehicle_no == 0){
            print();
        }
        else{
            if(vehicle_no < cycle_){
                cout << "GREEN: Vehicle(s) ";
                while(vehicle_no != 0){
                    dequeue();
                    vehicle_no--;
                }
                cout << "can go on" << endl;
            }
            else{
                unsigned int i = 1;
                cout << "GREEN: Vehicle(s) ";
                while(i <= cycle_){
                    dequeue();
                    i++;
                }
                cout << "can go on" << endl;

            }
            is_green_ = false;
        }

        //is_green_ = false; //reset again to red
    }
    else{
        is_green_ = false;
        print();
    }

}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print()
{
    Vehicle* item = first_;

    if(first_ == nullptr){
        if(is_green_)
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;
        else
           cout << "RED: No vehicles waiting in traffic lights" << endl;
    }
    else{
        cout << "RED: Vehicle(s) ";
        while (item != nullptr) {
            cout << item->reg_num << " ";
            item = item->next;
        }
        cout << "waiting in traffic lights" << endl;
    }
}

void Queue::dequeue()
{
    if(first_ == nullptr)
        return;

    Vehicle* temp = first_;
    first_ = first_->next;
    if(first_ == nullptr){
        last_ = nullptr;
    }
    cout << temp->reg_num << " ";
    delete temp;
}

unsigned int Queue::sizeQueue()
{
    Vehicle* s = first_;
    unsigned int count = 0;
    while(s != nullptr){
        ++count;
        s = s->next;
    }
    return count;
}
