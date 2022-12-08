//
// Created by Gabriel on 07/12/2022.
//

#include <utility>

#include "../headers/guloso.h++"


std::vector<Present> guloso::generatePresentList(std::vector<unsigned int> weight_list) {
    std::vector<Present> presents_list;
    for (int pos = 0; pos < weight_list.size(); pos++) {
        presents_list.push_back(FactoryPresent::createPresent(pos+1, weight_list.at(pos))); // pos+1 ocorre porque a posição nos arquivos começa pelo 1, não pelo 0.
    }
    return presents_list;
}


std::vector<Treno> guloso::createSleds(unsigned weight, unsigned quantity) {
    return std::vector<Treno> (quantity, Treno {weight, std::vector<Present> (0)});
}

/// Se for incompativel retorna false.
/// Se for compativel returna true.
bool guloso::verifyCompatibility(Present &present, Treno &treno, std::vector<std::vector<bool>> &presents_pair_matrix) {
    for (auto present_in_sled : treno.presents_list) {
        if (presents_pair_matrix.at(present.getID()-1).at(present_in_sled.getID()-1))return false;
    }
    return true;
}


std::vector<Treno> guloso::remove_unused_sled(std::vector<Treno> &trenos, unsigned max_weight) {
    std::vector<Treno> new_list;
    for (auto treno : trenos) {
        if (treno.max_weight != max_weight) {
            new_list.push_back(treno);
        }
    }
    return new_list;
}


std::vector<Treno> guloso::organaziSled(std::vector<unsigned int> weight_list, unsigned sleds_number, unsigned max_weight, std::vector<std::vector<bool>> presents_pair_matrix) {
    std::vector<Treno> trenos = guloso::createSleds(max_weight, sleds_number);
    std::vector<Present> presents_list = guloso::generatePresentList(weight_list);
    bool added = false;

    while (!presents_list.empty()) {
        Present present = presents_list.back();
        presents_list.pop_back();

        for (auto &treno : trenos) {
            if (treno.max_weight != 0 && present.getWeight() <= treno.max_weight) {
                if(verifyCompatibility(present, treno, presents_pair_matrix)) {
                    treno.presents_list.push_back(present);
                    treno.max_weight -= present.getWeight();
                    added = true;
                    break;
                }
            }
            if (!added) {
                trenos.push_back(Treno{max_weight, std::vector<Present> (0)});
                trenos.back().presents_list.push_back(present);
            }
        }
    }
return remove_unused_sled(trenos, max_weight);
}