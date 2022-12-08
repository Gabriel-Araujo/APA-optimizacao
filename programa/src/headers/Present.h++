/// Compilado para C++ 17
/// Autores:
///         - Gabriel Souza Cruz Araujo
///
/// Data de Criação: 01/12/2022

#ifndef APA_PRESENT_H
#define APA_PRESENT_H


#include <vector>

class Present {
private:
    unsigned weight;
    unsigned id; // posição do presente no array inicial
    std::vector<unsigned> incompatible_gifts;

public:
    Present();

    void setWeight(unsigned weight);
    void addIncompatibleGift(unsigned position);

    unsigned getWeight();
    std::vector<unsigned> getIncompatibleGifts(); // lista de Adjacência
    unsigned int getID();

    void setID(unsigned int pos);
};


#endif //APA_PRESENT_H