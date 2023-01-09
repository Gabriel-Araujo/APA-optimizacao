#ifndef APA_VND_H
#define APA_VND_H

#pragma once

#include "../headers/Solution.h"
//TODO implementar e refatorar VND

class Vnd {

public:
    Vnd();

    int performVnd(Solution solv);
    int swap();
    int two_opt();
    int re_insertion();

private:

};

#endif