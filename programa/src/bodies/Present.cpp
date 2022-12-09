/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 01/12/2022

#include "../headers/Present.h++"

Present::Present() {
    this->weight = 0;
    this->id = 0;
}


void Present::setWeight(unsigned int _weight) {
    this->weight = _weight;
}


void Present::setID(unsigned int pos) {
    this->id = pos;
}


unsigned int Present::getWeight() {
    return this->weight;
}


unsigned int Present::getID() {
    return this->id;
}


bool Present::operator==(const Present &p) const {
    return this->id == p.id;
}
