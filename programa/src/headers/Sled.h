#ifndef SLED_H
#define SLED_H

#pragma once

#include "../headers/Present.h++"

class Sled {
private:
    unsigned int id;
    unsigned int max_weight;
    unsigned int current_weight;
    std::vector<Present> presents_list;

public:
    Sled(unsigned id, unsigned weight);


    void addWeight(unsigned weight);
    void subWeight(unsigned weight);
    void addPresent(Present present);

    unsigned getCurrentWeight() const;
    unsigned getMaxWeight() const;
    const std::vector<Present>& getPresentsList() const;
    std::vector<Present>& getMutPresentsList();
};

#endif