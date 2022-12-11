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
    auto int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start);


    std::cout << "resultados do algoritmo guloso:" << std::endl;
    std::cout << "tempo de execucao: " << int_s.count() << " microsegundos" << std::endl;
    std::cout << "quantidade de trenos: " << a.trenos.size() << std::endl;
    //OutputHandler::showInTerminal(a.get_trenos());


    auto start2 = std::chrono::high_resolution_clock::now();
    busca_local.performVnd(&a);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto int_s2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);


    std::cout << "resultados do algoritmo VND:" << std::endl;
    std::cout << "tempo de execucao: " << int_s2.count() << " microsegundos" << std::endl;
    std::cout << "quantidade de trenos: " << a.trenos.size() << std::endl;
    //OutputHandler::showInTerminal(a.trenos);
    return 0;
}
