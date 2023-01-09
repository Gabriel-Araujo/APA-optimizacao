//
// Created by Gabriel on 07/12/2022.
//

#include "../headers/GreedyAlgorithm.h++"



/// Se for incompativel retorna false.
/// Se for compativel returna true.
bool GreedyAlgorithm::verifyCompatibility(Present &present, Sled &treno) const {
    for (Present present_in_sled : treno.getPresentsList()) {
        if (solution.getIncompatibilityMatrix()[present.getID()][present_in_sled.getID()]) return false;
    }
    return true;
}


void GreedyAlgorithm::organizeSleds() {
    bool added = false;


    solution.getMutSledsList().reserve(solution.getMaxSledQuantity());

    for (Present present : solution.getPresentsList()) {
        for (Sled &sled : solution.getMutSledsList()) {
            if (sled.getCurrentWeight() <= sled.getMaxWeight() && present.getWeight() <= sled.getMaxWeight() - sled.getCurrentWeight()) {
                if (verifyCompatibility(present, sled)) {
                    sled.addPresent(present);
                    added = true;
                    break;
                }
            }
        }
        if (!added) {
            solution.getMutSledsList().emplace_back(solution.getSledsQuantity()+1, solution.getMaxWeightPerSled());
            solution.getMutSledsList().back().addPresent(present);
        }
    }
}

void GreedyAlgorithm::run() {
    organizeSleds();
}
