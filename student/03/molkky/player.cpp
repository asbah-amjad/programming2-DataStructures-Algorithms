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
