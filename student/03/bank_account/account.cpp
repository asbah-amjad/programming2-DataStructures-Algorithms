#include "account.hh"
#include <iostream>
#include <string>

Account::Account(const std::string& owner, bool has_credit):
    owner_(owner), has_credit_(has_credit)   //initialization
{
    generate_iban();
}

void Account::print() const{
    cout << owner_ << " : " << iban_ << " : " << balance_ << " euros" << endl;
}

void Account::set_credit_limit(int amount){
    if(has_credit_ == true){
          credit_limit_ = amount;
    }
    else{
      cout << "Cannot set credit limit: the account has no credit card" << endl;
    }
}
void Account::save_money(int amount){

        balance_ += amount;

}

void Account::take_money(int amount){
    if(amount <= balance_){
    balance_ -= amount;
    cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ <<" euros" << endl;
    }
    else{
        cout << "Cannot take money: balance underflow" << endl;
    }
}

void Account::transfer_to(Account a, int amount){
    if(!has_credit_){
      if(amount <= balance_){
    balance_ -= amount;
    a.balance_ += amount;
    cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ <<" euros" << endl;
    }
      else{
        cout << "Cannot take money: balance underflow" << endl;
        cout << "Transfer from " << iban_ << " failed" << endl;
    }
    }
    else{
        int credit = balance_ + credit_limit_;
        int remaining = credit - amount;
        if(amount <= credit){
            cout << amount << " euros taken: new balance of " << iban_ << " is -" << remaining <<" euros" << endl;
        }
        else{
            cout << "Cannot take money: credit limit overflow" << endl;
            cout << "Transfer from " << iban_ << " failed" << endl;
        }
    }
}
// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
