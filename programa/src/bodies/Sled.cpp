#include <utility>

#include "../headers/Sled.h"


Sled::Sled(unsigned int id, unsigned int weight) {
    this->id = id;
    this->current_weight = 0;
    this->max_weight = weight;
}


void Sled::addWeight(unsigned weight) {
    current_weight+= weight;
}


void Sled::subWeight(unsigned int weight) {
    current_weight -= weight;
}


void Sled::addPresent(Present present) {
    presents_list.push_back(present);
}


unsigned Sled::getCurrentWeight() const {
    return current_weight;
}


unsigned Sled::getMaxWeight() const {
    return max_weight;
}


const std::vector<Present>& Sled::getPresentsList() const {
    return presents_list;
}


std::vector<Present> &Sled::getMutPresentsList() {
    return presents_list;
}