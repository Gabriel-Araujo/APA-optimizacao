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


Present Treno::removerPresente(unsigned present_id) {
    Present retorno = Present();

    for (auto presente = this->presents_list.begin(); presente != this->presents_list.end(); presente++) {
        if (presente->getID() == present_id) {
            retorno.setWeight(presente->getWeight());
            retorno.setID(presente->getID());
            this->max_weight += presente->getWeight();
            this->presents_list.erase(presente);
            return retorno;
        }
    }

    return retorno;
}