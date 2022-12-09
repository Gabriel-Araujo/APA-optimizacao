#ifndef APA_VND_H
#define APA_VND_H

#pragma once

#include <Solution.h>

class Vnd {

public:
    Vnd();

    std::vector<Present> performVnd(Solution solution);
    std::vector<Present> swap();
    std::vector<Present> two_opt();
    std::vector<Present> re_insertion();

private:

};

#endif