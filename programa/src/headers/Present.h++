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


public:
    Present();
    bool operator == (const Present& p) const;

    void setWeight(unsigned weight);

    unsigned getWeight(); // lista de Adjacência
    unsigned int getID();

    void setID(unsigned int pos);
};


#endif //APA_PRESENT_H
