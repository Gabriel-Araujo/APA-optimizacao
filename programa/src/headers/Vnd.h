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
    Solution swap(Solution solution_atual);
    Solution two_opt(Solution solution_atual);
    Solution re_insertion(Solution solution_atual);

private:
    InputHandler input;
};

#endif