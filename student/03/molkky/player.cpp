#include "player.hh"

Player::Player(string name):
    name_(name)
{
}

string Player::get_name() const{
    return name_;
}

int Player::get_points(){
    return points_;
}

int Player::add_points(int pts){
    points_ += pts;
    return points_;
}

bool Player::has_won(){
    if(points_ == 50){
        return true;
    }
    else{
        return false;
    }
}
