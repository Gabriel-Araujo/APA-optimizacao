#ifndef APA_SOLUTION_H
#define APA_SOLUTION_H

#pragma once

#include "../headers/Present.h++"
#include "../headers/Treno.h"
#include <vector>
#include <list>

class Solution
{
public:
    Solution();
    unsigned max_weight;

    std::vector<Present> presents;
    std::vector<Treno> trenos;  

    int get_num_trenos();    // Numero objetivo
    int get_num_present();
    std::vector<Treno> get_trenos();
    std::vector<Present> get_presents();
    void set_pair_matrix(std::vector<std::vector<bool>> matrix);
    std::vector<std::vector<bool>> get_pair_matrix();


private:
    std::vector<std::vector<bool>> pairs_matrix;
};

#endif