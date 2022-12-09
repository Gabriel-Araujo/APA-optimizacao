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
#include "headers/guloso.h++"

const std::string FILENAME = "../instances/n30_k150_A.txt";

int main() {
    InputHandler input = InputHandler();
    guloso ordenacao = guloso();
    input.readFile(FILENAME);

    auto start = std::chrono::high_resolution_clock::now();
    auto a = ordenacao.organaziSledUsingWeight(input.getWeights(), input.getSledsNumber(), input.getMaxWeight(), input.getPresentsPairsMatrix());
    auto end = std::chrono::high_resolution_clock::now();

    auto int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    OutputHandler::showInTerminal(a);
    std::cout << "tempo de execução: " << int_s.count() << "µs";
    return 0;
}
