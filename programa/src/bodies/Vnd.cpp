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
}

unsigned Vnd::re_insertion(Solution &solut){
    Solution new_solution;
    guloso guloso_algoritmo = guloso(this->input);
    int objective = solut.get_num_trenos();

    for (auto a = solut.presents.begin(); a < solut.presents.end()-2; a++) {
        for (auto b = a+2; b < solut.presents.end(); b++) {
            solut.presents.insert(b, *a);

            new_solution = guloso_algoritmo.organaziSled(solut);
            if (objective < new_solution.get_num_trenos()) {
                solut = new_solution;
                return -2;
            }
        }
    }

//    for(int i = 0; i < solut.presents.size()-2; i++){
//        for(int j = i + 2; j < solut.presents.size(); j++){
//
//            aux = solut.presents[i];
//            solut.presents.insert(j, solut);
//
//            new_solution = guloso_algoritmo.organaziSled(solut);
//            if(objective < new_solution.get_num_trenos()){
//                solut = new_solution;
//                return -2;
//            }
//        }
//
//    }

    return 1;
}

unsigned Vnd::re_insertion2(Solution &solut) {
    int pos = 0;
    auto new_solution = Solution();
    std::list<Treno> lista_trenos (solut.get_num_trenos());

    for (auto item : solut.get_trenos()) {
        item.id = pos;
        lista_trenos.push_back(item);
        pos++;
    }

    for (auto element = lista_trenos.begin(); element != lista_trenos.end(); element++) {
        Treno temp = *element;
        lista_trenos.remove(*element);

        for (auto &element2 : lista_trenos) {
            for (presentes : lista_trenos)
        }
    }

}
Solution Vnd::performVnd(Solution solv)
{
    unsigned k = 1;
    Solution actual_solution;
    while (k <= 3)
    {
        switch(k)
        {
        case 1:
            k += swap(solv);
            break;
        case 2:
            k += two_opt(solv);
            break;
        case 3:
            k += re_insertion(solv);
            break;
        }
    }

    return solv;
}