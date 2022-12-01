/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 29/11/2022

#ifndef APA_INPUTHANDLER_H
#define APA_INPUTHANDLER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

#include "fileNotFoundError.h++"

struct FileHeader {
    std::string name;
    unsigned long presents_number;
    unsigned long sleds_number;
    unsigned long max_weight;
    unsigned long array_L_length;
};


class InputHandler {
private:
    FileHeader fileHeader;
    std::vector<unsigned> weights;
    std::vector<std::array<unsigned, 2>> presents_pairs;



public:
    InputHandler();
    ~InputHandler();


    void readFile(const std::string& filename);

    void loadFileHeader(std::ifstream &file);
    void loadWeightsArray(std::ifstream &file);
    void loadPresentsPairs(std::ifstream &file);

    unsigned getPresentsNumber();
    unsigned getSledsNumber();
    unsigned getMaxWeight();
    unsigned getArrayLLength();
    std::vector<unsigned> getWeights();
    std::vector<std::array<unsigned, 2>> getPresentsPairs();
};


#endif //APA_INPUTHANDLER_H
