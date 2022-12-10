#ifndef APA_VND_H
#define APA_VND_H

#pragma once

#include "../headers/Solution.h"


class Vnd {

public:
    Vnd();

    std::vector<Present> performVnd(Solution solv);
    int swap(Solution );
    int two_opt(Solution );
    int re_insertion(Solution );

private:

};

#endif