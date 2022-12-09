//
// Created by Gabriel on 07/12/2022.
//

#ifndef APA_GULOSO_H
#define APA_GULOSO_H

#include "FactoryPresent.h++"
#include "Present.h++"
#include <list>

struct Treno {
    unsigned max_weight;
    std::vector<Present> presents_list;
};

class guloso {
private:
    std::list<Present> generatePresentList(std::vector<unsigned> weight_list);

public:

    static std::vector<Treno> createSleds(unsigned weight, unsigned quantity);

    std::vector<Treno> organaziSled(std::vector<unsigned int> weight_list, unsigned int sleds_number, unsigned int max_weight,
                      std::vector<std::vector<bool>> presents_pair_matrix);

    bool verifyCompatibility(Present &present, Treno &treno, std::vector<std::vector<bool>> &presents_pair_matrix);

    std::vector<Treno> remove_unused_sled(std::vector<Treno> &trenos, unsigned int max_weight);

    std::vector<Treno>
    organaziSledUsingWeight(std::vector<unsigned int> weight_list, unsigned int sleds_number, unsigned int max_weight,
                            std::vector<std::vector<bool>> presents_incomp_pairs_matrix);
};


#endif //APA_GULOSO_H
