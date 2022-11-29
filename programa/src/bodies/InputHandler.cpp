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


void InputHandler::readFile(const std::string& filepath) {
    std::ifstream file_handler(filepath, std::ifstream::in);
    loadFileHeader(file_handler);
    loadWeightsArray(file_handler);
    loadPresentsPairs(file_handler);
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
    while (!file.eof()) {
        getline(file, number1, ' ');
        getline(file, number2, ' ');
        std::array<unsigned long, 2> _temp{std::stoul(number1), std::stoul(number2)};
        this->presents_pairs.push_back(_temp);
    }
}


