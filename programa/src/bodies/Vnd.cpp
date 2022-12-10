#include "../headers/Vnd.h"
#include "../headers/Solution.h"

Vnd::Vnd()
{

}

int Vnd::swap(Solution solut){
    int new_solution;
    unsigned aux;
    for(int i = 0; i < solut.get_num_present(solut.get_presents()); i++){
        for(int j = i + 1; j < solut.get_num_present(solut.get_presents()); j++){
            aux = solut.presents[i].getWeight();
            solut.presents[i].setWeight(solut.presents[j].getWeight());
            solut.presents[j].setWeight(aux);


        }

    }


    return new_solution;
}

int Vnd::two_opt(Solution solut){
    int new_solution;
    int aux;
    for(int i = 0; i < solut.get_num_present(solut.get_presents()); i++){
        for(int j = i + 3; j < solut.get_num_present(solut.get_presents()); j++){
            aux = solut.presents[i].getWeight();
            solut.presents[i].setWeight(solut.presents[j].getWeight());
            solut.presents[j].setWeight(aux);
        }

    }


    return new_solution;
}

int Vnd::re_insertion(Solution solut){
    int new_solution;
    int aux;
    for(int i = 0; i < solut.get_num_present(solut.get_presents()); i++){
        for(int j = i + 1; j < solut.get_num_present(solut.get_presents()); j++){
            aux = solut.presents[i].getWeight();
            solut.presents[i].setWeight(solut.presents[j].getWeight());
            solut.presents[j].setWeight(aux);
        }

    }


    return new_solution;
}

std::vector<Present> Vnd::performVnd(Solution solv)
{
    int k = 1;
    int new_solution = 0;
    while (k <= 3)
    {
        switch (k)
        {
        case 1:
            new_solution = swap(solv);
            break;
        case 2:
            new_solution = two_opt(solv);
            break;
        case 3:
            new_solution = re_insertion(solv);
            break;
        }
        if(solv.solution > new_solution){
            solv.solution = new_solution;
            k++;
        }
    }
    
}