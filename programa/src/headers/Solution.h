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

    std::vector<Present> presents;
    std::vector<Treno> trenos;  

    int get_num_trenos();    // Numero objetivo
    int get_num_present();
    std::vector<Treno> get_trenos();
    std::vector<Present> get_presents();


private:
   
};

#endif