//
// Created by Gabriel on 07/12/2022.
//

#include <utility>
#include <algorithm>

#include "../headers/guloso.h++"
#include "../headers/Solution.h"


guloso::guloso(InputHandler input){

    this->input = input;

}

std::list<Present> guloso::generatePresentList(std::vector<unsigned int> weight_list) {
    std::list<Present> presents_list;
    for (int pos = 0; pos < weight_list.size(); pos++) {
        presents_list.push_back(FactoryPresent::createPresent(pos+1, weight_list.at(pos))); // pos+1 ocorre porque a posição nos arquivos começa pelo 1, não pelo 0.
    }
    return presents_list;
}


std::vector<Treno> guloso::createSleds(unsigned weight, unsigned quantity) {
    return std::vector<Treno> (quantity, Treno(weight, std::vector<Present> (0)));
}

/// Se for incompativel retorna false.
/// Se for compativel returna true.
bool guloso::verifyCompatibility(Present &present, Treno &treno, const std::vector<std::vector<bool>> presents_pair_matrix) {
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


Solution guloso::organaziSled(Solution solve) {
    std::vector<Treno> trenos = guloso::createSleds(this->input.getMaxWeight(), this->input.getSledsNumber());
    std::vector<Present> presents_list = solve.get_presents();
    std::vector<std::vector<bool>> pairs_matrix = this->input.getPresentsPairsMatrix();
    Solution solution = Solution();
    std::reverse(presents_list.begin(), presents_list.end());
    bool added = false;

    while (!presents_list.empty()) {
        Present present = presents_list.back();
        presents_list.pop_back();

        for (auto &treno : trenos) {
            if (treno.max_weight != 0 && present.getWeight() <= treno.max_weight ) {
                if(verifyCompatibility(present, treno, pairs_matrix)) {
                    treno.presents_list.push_back(present);
                    treno.max_weight -= present.getWeight();
                    added = true;
                    break;
                }
            }
        }
        if (!added) {
                trenos.emplace_back(this->input.getMaxWeight(), std::vector<Present> (0));
                trenos.back().presents_list.push_back(present);
        }
    }
    solution.trenos = remove_unused_sled(trenos, this->input.getMaxWeight());
    return solution;
}

Solution guloso::organaziSledUsingWeight(std::vector<unsigned int> weight_list, unsigned int sleds_number, unsigned int max_weight, std::vector<std::vector<bool>> presents_incomp_pairs_matrix) {
    std::vector<Treno> trenos = guloso::createSleds(max_weight, sleds_number);
    std::list<Present> presents_list = guloso::generatePresentList(weight_list);
    Present heaviest = presents_list.front();
    std::vector<Present> sorted_presents(presents_list.size());
    Solution solution = Solution();
    solution.max_weight = max_weight;
    solution.set_pair_matrix(presents_incomp_pairs_matrix);
    bool added = false;

    for (int i = 0; i < trenos.size(); i++) {
        trenos.at(i).id = i;
    }

    while (!presents_list.empty()) {
        for (auto present : presents_list) {
            if (present.getWeight() > heaviest.getWeight()) {
                heaviest = present;
            }
        }

        for (auto &treno : trenos) {
            if (treno.max_weight != 0 && heaviest.getWeight() < treno.max_weight) {
                if (verifyCompatibility(heaviest, treno, presents_incomp_pairs_matrix)) {
                    treno.presents_list.push_back(heaviest);
                    treno.max_weight -= heaviest.getWeight();
                    sorted_presents.push_back(heaviest);
                    added = true;
                    break;
                }
            }
        }
        if (!added) {
            trenos.emplace_back(max_weight, std::vector<Present> (0));
            trenos.back().presents_list.push_back(heaviest);
        }
        presents_list.remove(heaviest);
        heaviest = presents_list.front();
    }
    
    solution.presents = sorted_presents;
    solution.trenos = remove_unused_sled(trenos, max_weight);
    return solution;
}
