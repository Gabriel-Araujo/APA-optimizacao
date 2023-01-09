
#include "../headers/Solution.h"

Solution::Solution(unsigned sleds_quantity, unsigned max_weight) {
    max_sleds_quantity = sleds_quantity;
    max_weight_per_sled = max_weight;
}


void Solution::makePresentsList(const std::vector<unsigned int> &weight_list) {
    unsigned weight_id = 0;
    for (unsigned weight : weight_list) {
        presents_list.emplace_back(weight, weight_id);
    }
    std::sort(presents_list.begin(), presents_list.end());
}


void Solution::setIncompatibilityMatrix(std::vector<std::vector<bool>> &matrix) {
    incompatibility_matrix = std::move(matrix);
}


const std::vector<Sled> &Solution::getSledsList() const {
    return sleds_list;
}


std::vector<Sled> &Solution::getMutSledsList() {
    return sleds_list;
}


const std::vector<Present> &Solution::getPresentsList() const {
    return presents_list;
}


unsigned int Solution::getSledsQuantity() const {
    return sleds_list.size();
}


unsigned int Solution::getMaxWeightPerSled() const {
    return max_weight_per_sled;
}


unsigned int Solution::getMaxSledQuantity() const {
    return max_sleds_quantity;
}


const std::vector<std::vector<bool>> &Solution::getIncompatibilityMatrix() const {
    return incompatibility_matrix;
}