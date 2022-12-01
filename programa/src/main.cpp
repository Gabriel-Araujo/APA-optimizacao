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
#include "headers/ProblemData.h++"
#include "headers/ProblemFactory.h++"

const std::string FILENAME = "n30_k150_A.txt";

int main() {
    InputHandler input = InputHandler();
    input.readFile(FILENAME);

    ProblemData info = ProblemFactory::createProblemObject(input.getPresentsNumber(), input.getSledsNumber(), input.getMaxWeight(), input.getArrayLLength(), input.getWeights(), input.getPresentsPairs());

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
