/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 01/12/2022

#include "../headers/ProblemFactory.h++"

ProblemData
ProblemFactory::createProblemObject(unsigned int presents_number, unsigned int sleds_number,
                                    unsigned int max_weight, unsigned int array_L_length,
                                    std::vector<unsigned int> weights,
                                    std::vector<std::array<unsigned int, 2>> presents_pairs) {

    auto return_object = ProblemData();

    return_object.setPresentsQuantity(presents_number);
    return_object.setSleds_quantity(sleds_number);
    return_object.setMaxWeight(max_weight);
    return_object.setArrayLLength(array_L_length);
    // TODO talvez substituir os campos weights e presents_pairs por presents.
    return_object.setWeights(weights);
    return_object.setPresentsPairs(presents_pairs);

    for (int i = 0; i < weights.size(); i++) {
        auto present = Present();
        present.setWeight(weights[i]);

        for (auto pos : presents_pairs) {
            if (pos.at(0) == i+1) {
                present.addIncompatibleGift(pos.at(1));
            }
        }

        return_object.addPresent(present);
    }

    return return_object;
}

ProblemData
ProblemFactory::createProblemObjectWithMatrix(unsigned int presents_number, unsigned int sleds_number, unsigned int max_weight,
                                    unsigned int array_L_length, std::vector<unsigned int> weights,
                                    std::vector<std::vector<bool>> presents_pairs_matrix) {
    auto return_object = ProblemData();

    return_object.setPresentsQuantity(presents_number);
    return_object.setSleds_quantity(sleds_number);
    return_object.setMaxWeight(max_weight);
    return_object.setArrayLLength(array_L_length);
    // TODO talvez substituir os campos weights e presents_pairs por presents.
    return_object.setWeights(weights);
    return_object.setPresentsPairsMatrix(presents_pairs_matrix);

    for (int i = 0; i < weights.size(); i++) {
        auto present = Present();
        present.setWeight(weights[i]);

        return_object.addPresent(present);
    }

    return return_object;
}
