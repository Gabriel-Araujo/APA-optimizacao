//
// Created by Gabriel on 08/12/2022.
//


#include "../headers/OutputHandler.h++"

void OutputHandler::showInTerminal(const std::vector<Treno>& trenos) {
    std::cout << "Quantidade de trenos: " << trenos.size() << std::endl;
    for (int treno = 0; treno < trenos.size(); treno++) {
        Treno __treno = trenos.at(treno);
        std::cout << "Treno " << treno+1 << std::endl;
        std::cout << "Peso atual: " << __treno.max_weight << std::endl;

        for (auto present : __treno.presents_list) {
            std::cout << "Presente " << present.getID() << ", peso " << present.getWeight() << std::endl;
        }
        std::cout << std::endl;
    }
}
