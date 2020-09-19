#ifndef BOOK_HH
#define BOOK_HH
#include <string>
#include "date.hh"
#include <iostream>

using namespace std;

class Book
{
public:

    Book(string author, string title);
    void print() const;
    void renew();
    void give_back();
    void loan(Date & today);

private:
    string author_ = "";
    string title_ = "";
    bool has_loaned=false;
    Date loan_date;
    Date due_date;

};

#endif // BOOK_HH
