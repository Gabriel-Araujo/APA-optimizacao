//
// Created by Gabriel on 08/12/2022.
//

#ifndef APA_OUTPUTHANDLER_H
#define APA_OUTPUTHANDLER_H

#include <iostream>
#include <vector>
#include "guloso.h++"
#include "Treno.h"

class OutputHandler {
public:
    static void showInTerminal(const std::vector<Treno>& trenos);
};


#endif //APA_OUTPUTHANDLER_H
