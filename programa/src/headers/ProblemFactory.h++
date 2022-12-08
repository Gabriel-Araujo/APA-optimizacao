/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 01/12/2022

#ifndef APA_PROBLEMFACTORY_H
#define APA_PROBLEMFACTORY_H

#include <string>

#include "ProblemData.h++"


class ProblemFactory {
public:
    static ProblemData createProblemObject(unsigned presents_number, unsigned sleds_number, unsigned max_weight,
                                           unsigned array_L_length, std::vector<unsigned> weights,
                                           std::vector<std::array<unsigned, 2>> presents_pairs);

    static ProblemData
    createProblemObjectWithMatrix(unsigned int presents_number, unsigned int sleds_number, unsigned int max_weight,
                                  unsigned int array_L_length, std::vector<unsigned int> weights,
                                  std::vector<std::vector<bool>> presents_pairs_matrix);
};


#endif //APA_PROBLEMFACTORY_H
