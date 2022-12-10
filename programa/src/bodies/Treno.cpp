#include "../headers/Treno.h"

Treno::Treno()
{
    this->max_weight = 0;
    this->id = 0;
}

Treno::Treno(unsigned weight, std::vector<Present> presents)
{
    this->max_weight = weight;
    this->presents_list = presents;
}

void Treno::setMaxWeight(unsigned weight)
{
    this->max_weight;
}

unsigned Treno::getMaxWeight()
{
    return this->max_weight;
}


bool Treno::operator==(const Treno &p) const {
    return this->id == p.id;
}
