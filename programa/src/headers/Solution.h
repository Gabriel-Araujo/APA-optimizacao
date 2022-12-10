#ifndef APA_SOLUTION_H
#define APA_SOLUTION_H

#pragma once

#include "../headers/Present.h++"
#include "../headers/Treno.h"
#include <vector>

class Solution
{
public:
    Solution();

    int solution;
    std::vector<Present> presents;
    std::vector<Treno> trenos;  // trenos.size() eh o numero objetivo

    int get_num_trenos(std::vector<Treno> );
    int get_num_present(std::vector<Present> );
    std::vector<Treno> get_trenos();
    std::vector<Present> get_presents();


private:
   
};

#endif