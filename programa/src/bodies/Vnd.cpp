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

    return 1;
}

unsigned Vnd::two_opt(Solution &solut){
    Solution new_solution;
    guloso guloso_algoritmo = guloso(this->input);
    int objective = solut.get_num_trenos();

    for (auto i = solut.presents.begin(); i-3 < solut.presents.end(); i++) {
        for (auto j = solut.presents.begin()+3; j < solut.presents.end(); j++) {
            std::vector<Present> aux(i, j);
            std::reverse(aux.begin(), aux.end());

            *i = aux.at(0);
            *(i+1) = aux.at(1);
            *(i+2) = aux.at(2);

            new_solution = guloso_algoritmo.organaziSled(solut);
            if (objective < new_solution.get_num_trenos()) {
                solut = new_solution;
                return -1;
            }
        }
    }
    /*
     for(int i = 0; i < solut.get_num_present() - 3; i++){
        for(int j = i + 3; j < solut.get_num_present(); j++){
            aux = solut.presents[i].getWeight();
            solut.presents[i].setWeight(solut.presents[j].getWeight());
            solut.presents[j].setWeight(aux);

            new_solution = guloso_algoritmo.organaziSled(solut);
            if(objective < new_solution.get_num_trenos()){
                solut = new_solution;
                return -1;
            }
        }
    }*/

    return 1;
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

std::vector<Present> Vnd::performVnd(Solution solv)
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
    
}