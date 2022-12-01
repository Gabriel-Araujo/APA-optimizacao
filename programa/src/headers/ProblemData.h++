/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 01/12/2022

#ifndef APA_PROBLEMDATA_H
#define APA_PROBLEMDATA_H


#include <vector>
#include <array>

class ProblemData {
private:
    unsigned presents_quantity;
    unsigned sleds_quantity;
    unsigned max_weight;
    unsigned array_L_length;
    std::vector<unsigned> weights;
    std::vector<std::array<unsigned, 2>> presents_pairs;

public:
    ProblemData();
    ~ProblemData();
    void setPresentsQuantity(unsigned quantity);
    void setSleds_quantity(unsigned quantity);
    void setMaxWeight(unsigned weight);
    void setArrayLLength(unsigned length);
    void setWeights(std::vector<unsigned> weights_list);
    void setPresentsPairs(const std::vector<std::array<unsigned, 2>>& presents_pairs_list);

    unsigned getPresentsQuantity();
    unsigned getSleds_quantity();
    unsigned getMaxWeight();
    unsigned getArrayLLength();
    std::vector<unsigned>& getWeights();
    std::vector<std::array<unsigned, 2>>& getPresentsPairs();
};


#endif //APA_PROBLEMDATA_H
