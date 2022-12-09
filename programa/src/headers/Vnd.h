#ifndef APA_VND_H
#define APA_VND_H

#pragma once

#include "../headers/Solution.h"

class Vnd {

public:
    Vnd();

    std::vector<Present> performVnd(Solution solv);
    int swap();
    int two_opt();
    int re_insertion();

private:

};

#endif