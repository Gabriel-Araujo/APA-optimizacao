#ifndef TRENO_H
#define TRENO_H

#pragma once

#include <Present.h++>

class Treno
{
public:
    Treno();
    Treno(unsigned weight, std::vector<Present> presents);
    unsigned max_weight = 0;
    std::vector<Present> presents_list;

    void setMaxWeight(unsigned weight);
    unsigned getMaxWeight();

private:

};

#endif