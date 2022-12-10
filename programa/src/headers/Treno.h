#ifndef TRENO_H
#define TRENO_H

#pragma once

#include "../headers/Present.h++"

class Treno
{
public:
    Treno();
    Treno(unsigned weight, std::vector<Present> presents);
    bool operator == (const Treno& t) const;
    unsigned max_weight = 0;
    unsigned id;
    std::vector<Present> presents_list;

    void setMaxWeight(unsigned weight);
    unsigned getMaxWeight();

private:


};

#endif