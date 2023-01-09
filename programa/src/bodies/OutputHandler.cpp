//
// Created by Gabriel on 08/12/2022.
//


#include "../headers/OutputHandler.h++"

void OutputHandler::showInTerminal(const std::vector<Sled>& trenos) {
    std::cout << "Quantidade de trenos: " << trenos.size() << std::endl;
    for (int treno = 0; treno < trenos.size(); treno++) {
        Sled __treno = trenos.at(treno);
        std::cout << "Sled " << treno+1 << std::endl;
        std::cout << "Peso atual: " << __treno.getMaxWeight() << std::endl;

        for (auto present : __treno.getPresentsList()) {
            std::cout << "Presente " << present.getID() << ", peso " << present.getWeight() << std::endl;
        }
        std::cout << std::endl;
    }
}
