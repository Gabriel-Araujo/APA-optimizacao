/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///         - David Wilson Melo Santos
///         - Luiz Gusttavo Oliveira De Souza
///
/// Data de Criação: 29/11/2022

#include <iostream>
#include <string>
#include <chrono>

#include "headers/InputHandler.h++"
#include "headers/OutputHandler.h++"
#include "headers/GreedyAlgorithm.h++"
#include "headers/Sled.h"

const std::string FILENAME = "../instances/n30_k150_A.txt";

int main() {
    InputHandler input = InputHandler(FILENAME);
    Solution solution = Solution(input.getSledsQuantity(), input.getMaxWeightPerSled());

    solution.makePresentsList(input.getWeights());
    solution.setIncompatibilityMatrix(input.getPresentsPairsMatrix());

    GreedyAlgorithm ordenacao = GreedyAlgorithm(solution);

    auto start = std::chrono::high_resolution_clock::now();
    ordenacao.run();
    auto end = std::chrono::high_resolution_clock::now();

    auto int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    //OutputHandler::showInTerminal(a.trenos);
    std::cout << "tempo de execução: " << int_s.count() << "µs";
    return 0;
}
