/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///         - David Wilson Melo Santos
///         - Luiz Gusttavo Oliveira De Souza
///
/// Data de Criação: 29/11/2022

#include <iostream>
#include <string>

#include "headers/InputHandler.h++"
#include "headers/OutputHandler.h++"
#include "headers/guloso.h++"

const std::string FILENAME = "../instances/n30_k150_A.txt";

int main() {
    InputHandler input = InputHandler();
    guloso ordenacao = guloso();
    input.readFile(FILENAME);

    auto a = ordenacao.organaziSled(input.getWeights(), input.getSledsNumber(), input.getMaxWeight(), input.getPresentsPairsMatrix());

    OutputHandler::showInTerminal(a);
    return 0;
}
