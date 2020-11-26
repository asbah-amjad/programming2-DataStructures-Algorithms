#include "mammal.hh"

Mammal::Mammal()
{

}

Mammal::Mammal(const std::string &moving_noise): Animal(moving_noise)
{
    Animal("Kip kop kip kop");
}

void Mammal::suckle(std::ostream &output)
{
    output << "Mus mus" << std::endl;
}
