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
    unsigned int id; // posição do presente no array inicial
    unsigned int weight;


public:
    Present();
    Present(unsigned id, unsigned weight): id{id}, weight{weight} {};

    bool operator == (const Present& p) const;
    bool operator < (const Present& p) const;

    void setWeight(unsigned weight);
    void setID(unsigned int pos);

    unsigned int getWeight() const;
    unsigned int getID() const;

};


#endif //APA_PRESENT_H
