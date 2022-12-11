#include "../headers/Vnd.h"
#include "../headers/Solution.h"

Vnd::Vnd()
{

}

Vnd::Vnd(InputHandler input)
{
    this->input = input;
}

/// Remove um treno da solução e percorre todos os outros trenos tentando colocar todos os presentes do treno removido
/// dentro de algum outro treno.
///
/// Como ele recebe a solução como ponteiro, as mudanças dentro do algoritmo são feitas direto na solução.
/// \param Solution
/// \return -1 se encontrar uma solução melhor ou
///          1 se não encontrar.
unsigned Vnd::re_insertion(Solution *solut) {
    std::vector<Treno> old_solutuon = solut->get_trenos();

    for (int treno_removido_index = 0; treno_removido_index < solut->get_num_trenos(); treno_removido_index++) { // separa 1 treno pra ser removido
        for (int treno_index = 0; treno_index < solut->get_num_trenos(); treno_index++) { // percorre todos os trenos
            if (treno_index == treno_removido_index) continue; // evita o treno removido
            unsigned peso_dos_itens = solut->max_weight - solut->trenos.at(treno_removido_index).max_weight;
            unsigned peso_disponivel = solut->trenos.at(treno_index).max_weight;

            if (peso_dos_itens <= peso_disponivel) { // se o peso dos presentes do treno removido for menor que o peso restante do treno destiono mova os presentes para o treno destino e remova da solução o treno fonte.
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


/// Remove um treno da solução e quebra a conexão entre os presentes - as arestas - depois percorre os trenos da solução
/// tentando colocar cada presente (vertice) dentro de algum treno (arvore).
/// \param Solution
/// \return Retorna 0 se conseguir achar uma solução melhor ou 1 se não conseguir.
unsigned Vnd::_2_opt(Solution *solut) {
    std::vector<Treno> old_solution = solut->get_trenos();

    for (int t = 0; t < solut->trenos.size(); t++) { // percorre os trenos
        distribuir_itens(&solut->trenos.at(t), &solut->trenos, solut->get_pair_matrix()); // tenta distribuir os presentes de um treno em outro, se não consegui poem o treno com os presentes restantes
        //                                                                                                          de volta na solução.
        solut->trenos = guloso::remove_unused_sled(solut->trenos, solut->max_weight);
        if (solut->trenos.size() < old_solution.size()) {
            return 0;
        }
        solut->trenos.swap(old_solution); // se não achar uma solução melhor retorna a solução devolta pro seu estado anterior.
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