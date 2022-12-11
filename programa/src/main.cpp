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
#include "headers/Vnd.h"

const std::string FILENAME = "../instances/n30_k150_C.txt";

int main() {
    InputHandler input = InputHandler();
    input.readFile(FILENAME);
    guloso ordenacao = guloso(input);
    Vnd busca_local = Vnd();
    
    auto start = std::chrono::high_resolution_clock::now();
    auto a = ordenacao.organaziSledUsingWeight(input.getWeights(), input.getSledsNumber(), input.getMaxWeight(), input.getPresentsPairsMatrix());
    auto end = std::chrono::high_resolution_clock::now();
    OutputHandler::showInTerminal(a.get_trenos());
    auto int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto b = busca_local.performVnd(&a);

    OutputHandler::showInTerminal(b);
    std::cout << "tempo de execucao: " << int_s.count() << "ms";
    return 0;
}
