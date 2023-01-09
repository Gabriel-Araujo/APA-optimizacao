//
// Created by Gabriel on 07/12/2022.
//

#ifndef APA_GREEDYALGORITHM_H
#define APA_GREEDYALGORITHM_H

#include "Solution.h"
#include "Present.h++"
#include <list>

class GreedyAlgorithm {
private:
    Solution& solution;
    void organizeSleds();
    bool verifyCompatibility(Present &present, Sled &treno) const;

public:
    explicit GreedyAlgorithm(Solution &solution): solution{solution} {};
    void run();

};


#endif //APA_GREEDYALGORITHM_H
