#ifndef APA_VND_H
#define APA_VND_H

#pragma once

#include "../headers/Solution.h"
#include "../headers/guloso.h++"


class Vnd {

public:
    Vnd();
    Vnd(InputHandler input);

    std::vector<Present> performVnd(Solution solv);
    unsigned swap(Solution &solution_atual);
    unsigned two_opt(Solution &solution_atual);
    unsigned re_insertion(Solution &solution_atual);

private:
    InputHandler input;
};

#endif