/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///         - David Wilson Melo Santos
///         - Luiz Gusttavo Oliveira De Souza
///
/// Data de Criação: 29/11/2022

#include <iostream>
#include "headers/InputHandler.h++"

int main() {
    InputHandler input = InputHandler();
    input.readFile("n30_k150_A.txt");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
