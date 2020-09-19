#include "book.hh"
#include "date.hh"
#include <iostream>
#include <string>

using namespace std;

Book::Book(string author, string title):
    author_(author),title_(title)
{
}

void Book::print() const{
    cout << author_ << " : " << title_ << endl;
    if(has_loaned == false){
        cout << "- available" << endl;
    }
    else{

        cout << "- loaned: ";
        loan_date.print();
        cout << "- to be returned: ";
        due_date.print();
    }
}

void Book::loan(Date& a){
    if(has_loaned == false){
        loan_date = a;
        a.advance(28);
        due_date = a;
    }
}

void Book::renew(){
    if(has_loaned == false){
        cout << "Not loaned: cannot be renewed" << endl;
    }
    else{
        due_date.advance(28);
    }
}
void Book::give_back(){

}

