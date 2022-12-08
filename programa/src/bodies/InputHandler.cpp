/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 29/11/2022

#include "../headers/InputHandler.h++"


InputHandler::InputHandler() {
    fileHeader = {
            "",
            0,
            0,
            0,
    };
}

InputHandler::~InputHandler() {
}


void InputHandler::readFile(const std::string& filename) {
    std::ifstream file_handler(filename, std::ifstream::in);
    loadFileHeader(file_handler);
    loadWeightsArray(file_handler);
    //loadPresentsPairs(file_handler);
    loadPresentsPairsMatrix(file_handler);
    file_handler.close();
}



/// O Header do arquivo está consistindo de 5 linhas
/// Na 1ª está o nome do arquivo
/// Na 2ª está a quantidade de presentes
/// Na 3ª está o K
/// Na 4ª está o max_weight
/// Na 5ª está o número de elementos na lista L
void InputHandler::loadFileHeader(std::ifstream &file) {
    std::string _name;
    std::string _presents_number;
    std::string _sleds_number;
    std::string _max_weight;
    std::string _array_L_length;

    if(!file.is_open()) {
        throw fileNotFoundError("file not found", std::error_code());
    }

    getline(file, _name);
    getline(file, _presents_number);
    getline(file, _sleds_number);
    getline(file, _max_weight);
    getline(file, _array_L_length);

    this->fileHeader.name = _name;
    this->fileHeader.presents_number = stoi(_presents_number);
    this->fileHeader.sleds_number = stoi(_sleds_number);
    this->fileHeader.max_weight = stoi(_max_weight);
    this->fileHeader.array_L_length = stoi(_array_L_length);
    getline(file, _name);
}


void InputHandler::loadWeightsArray(std::ifstream &file) {
    std::string array_line;
    std::string number_string;

    for (int i = 0; i < this->fileHeader.presents_number; i++) {
        getline(file, array_line, ' ');
        this->weights.push_back(std::stoul(array_line));
    }
    getline(file, array_line);
}


void InputHandler::loadPresentsPairs(std::ifstream &file) {
    std::string number1, number2;
    unsigned number11, number22;
    while (!file.eof()) {
        getline(file, number1, ' ');
        getline(file, number2, '\n');
        if (number1 == "" || number2 == "") continue;
        number11 = std::stoul(number1);
        number22 = std::stoul(number2);
        std::array<unsigned, 2> _temp = {number11, number22};
        this->presents_pairs.push_back(_temp);
    }
}


void InputHandler::loadPresentsPairsMatrix(std::ifstream &file) {
    std::vector<std::vector<bool>> return_matrix (this->fileHeader.presents_number+1, std::vector<bool> (this->fileHeader.presents_number+1, false));
    std::string number_1, number_2;
    unsigned number_11, number_22;

    while (!file.eof()) {
        getline(file, number_1, ' ');
        getline(file, number_2, '\n');
        if (number_1 == "" || number_2 == "") continue;
        number_11 = std::stoul(number_1);
        number_22 = std::stoul(number_2);

        return_matrix.at(number_11).at(number_22) = true;
    }
    this->presents_pair_matrix = return_matrix;
}


unsigned InputHandler::getPresentsNumber() {
    return this->fileHeader.presents_number;
}


unsigned InputHandler::getSledsNumber() {
    return this->fileHeader.sleds_number;
}


unsigned int InputHandler::getMaxWeight() {
    return this->fileHeader.max_weight;
}


unsigned int InputHandler::getArrayLLength() {
    return this->fileHeader.array_L_length;
}


std::vector<unsigned> InputHandler::getWeights() {
    return this->weights;
}

std::vector<std::array<unsigned, 2>> InputHandler::getPresentsPairs() {
    return this->presents_pairs;
}


std::vector<std::vector<bool>> InputHandler::getPresentsPairsMatrix() {
    return this->presents_pair_matrix;
}