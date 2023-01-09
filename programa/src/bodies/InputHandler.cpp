/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 29/11/2022

#include "../headers/InputHandler.h++"


InputHandler::InputHandler() {
    presents_number = 0;
    sleds_number = 0;
    max_weight = 0;
    array_L_length = 0;
}


InputHandler::InputHandler(const std::string& filename) {
    presents_number = 0;
    sleds_number = 0;
    max_weight = 0;
    array_L_length = 0;
    readFile(filename);
}

InputHandler::~InputHandler() = default;


void InputHandler::readFile(const std::string& filename) {
    std::ifstream file_handler(filename, std::ifstream::in);
    loadFileHeader(file_handler);
    loadWeightsArray(file_handler);
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

    file_name = _name;
    presents_number = stoi(_presents_number);
    sleds_number = stoi(_sleds_number);
    max_weight = stoi(_max_weight);
    array_L_length = stoi(_array_L_length);
    getline(file, _name);
}


void InputHandler::loadWeightsArray(std::ifstream &file) {
    std::string array_line;
    std::string number_string;

    for (int _ = 0; _ < presents_number; _++) {
        getline(file, array_line, ' ');
        this->weights.push_back(std::stoul(array_line));
    }
    getline(file, array_line);
}


void InputHandler::loadPresentsPairsMatrix(std::ifstream &file) {
    std::vector<std::vector<bool>> return_matrix (presents_number+1, std::vector<bool> (presents_number+1, false));
    std::string number_1_str, number_2_str;
    unsigned number_1, number_2 = 0;

    while (!file.eof()) {
        getline(file, number_1_str, ' ');
        getline(file, number_2_str, '\n');
        if (number_1_str.empty() || number_2_str.empty()) continue;
        number_1 = std::stoul(number_1_str);
        number_2 = std::stoul(number_2_str);

        return_matrix.at(number_1).at(number_2) = true;
        return_matrix.at(number_2).at(number_1) = true;
    }
    this->presents_pair_matrix = return_matrix;
}


unsigned InputHandler::getPresentsQuantity() const{
    return presents_number;
}


unsigned InputHandler::getSledsQuantity() const {
    return sleds_number;
}


unsigned int InputHandler::getMaxWeightPerSled() const {
    return max_weight;
}


unsigned int InputHandler::getArrayLLength() const {
    return array_L_length;
}


const std::vector<unsigned>& InputHandler::getWeights() const {
    return weights;
}


std::vector<std::vector<bool>>& InputHandler::getPresentsPairsMatrix() const{
    return presents_pair_matrix;
}