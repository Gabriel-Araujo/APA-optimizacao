#include "../headers/Vnd.h"
#include "../headers/Solution.h"

Vnd::Vnd()
{

}

Vnd::Vnd(InputHandler input)
{
    this->input = input;
}

unsigned Vnd::swap(Solution &solut){
    Solution new_solution;
    guloso guloso_algoritmo = guloso(this->input);
    int objective = solut.get_num_trenos();
    Present aux;
    for(int i = 0; i < solut.get_num_present()-1; i++){
        for(int j = i + 1; j < solut.get_num_present(); j++){
            aux = solut.presents[i];
            solut.presents[i] = solut.presents[j];
            solut.presents[j] = aux;

            new_solution = guloso_algoritmo.organaziSled(solut);
            if(objective < new_solution.get_num_trenos()){
                solut = new_solution;
                return 0;
            }

        }

    }

    return 2;
}


unsigned Vnd::two_opt(Solution &solut){
//    Solution new_solution;
//    guloso guloso_algoritmo = guloso(this->input);
//    int objective = solut.get_num_trenos();
//    unsigned contador = 3;
//
//    for (auto i = solut.presents.begin(); i < solut.presents.end()-contador; i++) {
//        for (auto j = solut.presents.begin()+contador; j < solut.presents.end(); j++) {
//            std::vector<Present> aux(i, j);
//            std::reverse(aux.begin(), aux.end());
///*
//            *i = aux.at(0);
//            *(i+1) = aux.at(1);
//            *(i+2) = aux.at(2);*/
//            for (int teste = 0; teste < contador; teste++) {
//                *(i+teste) = aux.at(teste);
//            }
//
//            new_solution = guloso_algoritmo.organaziSled(solut);
//            if (objective < new_solution.get_num_trenos()) {
//                solut = new_solution;
//                return -1;
//            }
//        }
//    }
//    /*
//     for(int i = 0; i < solut.get_num_present() - 3; i++){
//        for(int j = i + 3; j < solut.get_num_present(); j++){
//            aux = solut.presents[i].getWeight();
//            solut.presents[i].setWeight(solut.presents[j].getWeight());
//            solut.presents[j].setWeight(aux);
//
//            new_solution = guloso_algoritmo.organaziSled(solut);
//            if(objective < new_solution.get_num_trenos()){
//                solut = new_solution;
//                return -1;
//            }
//        }
//    }*/
//
//    return 1;
return 1;
}


unsigned Vnd::re_insertion(Solution *solut) {
    std::vector<Treno> old_solutuon = solut->get_trenos();

    for (int treno_removido_index = 0; treno_removido_index < solut->get_num_trenos(); treno_removido_index++) {
        for (int treno_index = 0; treno_index < solut->get_num_trenos(); treno_index++) {
            if (treno_index == treno_removido_index) continue;
            unsigned peso_dos_itens = solut->max_weight - solut->trenos.at(treno_removido_index).max_weight;
            unsigned peso_disponivel = solut->trenos.at(treno_index).max_weight;

            if (peso_dos_itens <= peso_disponivel) {
                if (verificar_compatibilidade_presentes(solut->trenos.at(treno_removido_index), solut->trenos.at(treno_index), solut->get_pair_matrix())) {
                    for (auto presente : solut->trenos.at(treno_removido_index).presents_list) {
                        solut->trenos.at(treno_index).presents_list.push_back(presente);
                    }
                    solut->trenos.at(treno_removido_index).max_weight = solut->max_weight;
                    solut->trenos = guloso::remove_unused_sled(solut->trenos, solut->max_weight);
                    return -1;
                }
            }
        }
    }
    return 1;
}


bool Vnd::verificar_compatibilidade_presentes(Treno &treno, Treno &treno2, std::vector<std::vector<bool>> matrix) {
    for (auto presente : treno.presents_list) {
        if (!guloso::verifyCompatibility(presente, treno, matrix)) {
            return false;
        }
    }
    return true;
}

unsigned Vnd::_2_opt(Solution *solut) {
    std::vector<Treno> old_solution = solut->get_trenos();

    for (int t = 0; t < solut->trenos.size(); t++) {
        distribuir_itens(&solut->trenos.at(t), &solut->trenos, solut->get_pair_matrix());
        solut->trenos = guloso::remove_unused_sled(solut->trenos, solut->max_weight);
        if (solut->trenos.size() < old_solution.size()) {
            return 0;
        }
        solut->trenos.swap(old_solution);
    }
    return 1;
}


void Vnd::distribuir_itens(Treno *treno, std::vector<Treno> *trenos, std::vector<std::vector<bool>> matrix) {
    for (int pos = 0; pos < trenos->size(); pos++) {
        if (treno->id == trenos->at(pos).id) continue;

        for (int pos_presente = 0; pos_presente < treno->presents_list.size(); pos_presente++) {
            if (guloso::verifyCompatibility(treno->presents_list.at(pos_presente), trenos->at(pos), matrix)) {
                if (treno->presents_list.at(pos_presente).getWeight() <= trenos->at(pos).max_weight) {
                    trenos->at(pos).presents_list.push_back(treno->presents_list.at(pos_presente));
                    trenos->at(pos).max_weight -= treno->presents_list.at(pos_presente).getWeight();
                    treno->removerPresente(treno->presents_list.at(pos_presente).getID());
                }
            }
        }
    }
}


Solution Vnd::performVnd(Solution *solv)
{
    unsigned k = 2;
    Solution actual_solution;
    while (k <= 3)
    {
        switch(k)
        {
        case 2:
            k += _2_opt(solv);
            break;
        case 3:
            k += re_insertion(solv);
            break;
        }
    }

    return *solv;
}