//
// Created by Gabriel on 07/12/2022.
//

#ifndef APA_GULOSO_H
#define APA_GULOSO_H

#include "Solution.h"
#include "FactoryPresent.h++"
#include "Present.h++"

class guloso {
private:
    std::vector<Present> generatePresentList(std::vector<unsigned> weight_list);

public:

    static std::vector<Treno> createSleds(unsigned weight, unsigned quantity);

    Solution organaziSled(std::vector<unsigned int> weight_list, unsigned int sleds_number, unsigned int max_weight,
                      std::vector<std::vector<bool>> presents_pair_matrix);

    bool verifyCompatibility(Present &present, Treno &treno, std::vector<std::vector<bool>> &presents_pair_matrix);

    std::vector<Treno> remove_unused_sled(std::vector<Treno> &trenos, unsigned int max_weight);
};


#endif //APA_GULOSO_H
