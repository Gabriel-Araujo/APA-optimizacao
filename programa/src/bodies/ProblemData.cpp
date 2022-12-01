/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 01/12/2022

#include <utility>

#include "../headers/ProblemData.h++"

ProblemData::ProblemData() {
    presents_quantity = 0;
    sleds_quantity = 0;
    max_weight = 0;
    array_L_length = 0;
}

ProblemData::~ProblemData() {

};


void ProblemData::setPresentsQuantity(unsigned int quantity) {
    this->presents_quantity = quantity;
}


void ProblemData::setSleds_quantity(unsigned int quantity) {
    this->sleds_quantity = quantity;
}


void ProblemData::setMaxWeight(unsigned int weight) {
    this->max_weight = weight;
}


void ProblemData::setArrayLLength(unsigned int length) {
    this->array_L_length = length;
}


void ProblemData::setWeights(std::vector<unsigned int> weights_list) {
    this->weights = std::move(weights_list);
}


void ProblemData::setPresentsPairs(const std::vector<std::array<unsigned int, 2>>& presents_pairs_list) {
    this->presents_pairs = presents_pairs_list;
}


unsigned ProblemData::getPresentsQuantity() {
    return this->presents_quantity;
}


unsigned int ProblemData::getSleds_quantity() {
    return this->sleds_quantity;
}


unsigned int ProblemData::getMaxWeight() {
    return this->max_weight;
}


unsigned int ProblemData::getArrayLLength() {
    return this->array_L_length;
}


std::vector<unsigned int> &ProblemData::getWeights() {
    return this->weights;
}


std::vector<std::array<unsigned int, 2>> &ProblemData::getPresentsPairs() {
    return this->presents_pairs;
}
