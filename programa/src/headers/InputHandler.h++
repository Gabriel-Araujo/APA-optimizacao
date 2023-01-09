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


class InputHandler {
private:
    std::string file_name;
    unsigned long presents_number;
    unsigned long sleds_number;
    unsigned long max_weight;
    unsigned long array_L_length;
    std::vector<unsigned> weights;
    std::vector<std::vector<bool>> presents_pair_matrix;


public:
    InputHandler();
    explicit InputHandler(const std::string& filename);
    ~InputHandler();


    void readFile(const std::string& filename);

    void loadFileHeader(std::ifstream &file);
    void loadWeightsArray(std::ifstream &file);
    void loadPresentsPairsMatrix(std::ifstream &file);

    unsigned getPresentsQuantity() const;
    unsigned getSledsQuantity() const;
    unsigned getMaxWeightPerSled() const;
    unsigned getArrayLLength() const;

    [[nodiscard]] const std::vector<unsigned>& getWeights() const;

    [[nodiscard]] const std::vector<std::vector<bool>>& getPresentsPairsMatrix() const;
};


#endif //APA_INPUTHANDLER_H
