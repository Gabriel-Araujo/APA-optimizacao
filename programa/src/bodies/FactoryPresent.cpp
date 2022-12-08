//
// Created by Gabriel on 08/12/2022.
//

#include "../headers/FactoryPresent.h++"

Present FactoryPresent::createPresent(unsigned int pos, unsigned int weight) {
    Present return_value = Present();
    return_value.setWeight(weight);
    return_value.setID(pos);

    return return_value;
}

