#ifndef APA_SOLUTION_H
#define APA_SOLUTION_H

#pragma once

#include "../headers/Present.h++"
#include "../headers/Sled.h"
#include <vector>
#include <algorithm>


class Solution {
private:
    std::vector<Present> presents_list;
    std::vector<Sled> sleds_list;
    std::vector<std::vector<bool>> incompatibility_matrix;
    unsigned max_sleds_quantity;
    unsigned max_weight_per_sled;

public:
    Solution(unsigned sleds_quantity, unsigned max_weight);

    void makePresentsList(const std::vector<unsigned>& weight_list);
    void setIncompatibilityMatrix(std::vector<std::vector<bool>>& matrix);

    const std::vector<Sled>& getSledsList() const;
    std::vector<Sled>& getMutSledsList();
    const std::vector<Present>& getPresentsList()const;
    const std::vector<std::vector<bool>>& getIncompatibilityMatrix() const;

    unsigned getSledsQuantity() const;
    unsigned getMaxWeightPerSled() const;
    unsigned getMaxSledQuantity() const;
};

#endif