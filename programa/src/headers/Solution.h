#ifndef APA_SOLUTION_H
#define APA_SOLUTION_H

#pragma once

#include <Present.h++>
#include <Treno.h>
#include <vector>

class Solution
{
public:
    Solution();
    
    std::vector<Present> orderly_presents;
    std::vector<Treno> trenos;  // trenos.size() eh o numero objetivo
    

private:
   
};

#endif