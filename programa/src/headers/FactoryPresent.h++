//
// Created by Gabriel on 08/12/2022.
//

#ifndef APA_FACTORYPRESENT_H
#define APA_FACTORYPRESENT_H

#include "Present.h++"


class FactoryPresent {
public:
    static Present createPresent(unsigned int pos, unsigned int weight);
};


#endif //APA_FACTORYPRESENT_H
