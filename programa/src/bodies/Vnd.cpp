#include "../headers/Vnd.h"
#include "../headers/Solution.h"

Vnd::Vnd()
{

}

Vnd::Vnd(InputHandler input)
{
    this->input = input;
}

Solution Vnd::swap(Solution solv){
    Solution new_solution;
    guloso guloso = guloso(this->input);
    int aux;
    for(int i = 0; i < solv.get_num_present()-1; i++){
        for(int j = i + 1; j < solv.get_num_present(); j++){
            aux = solv.presents[i].getWeight();
            solv.presents[i].setWeight(solv.presents[j].getWeight());
            solv.presents[j].setWeight(aux);

        }

    }

    new_solution.presents = solv.presents;
    new_solution = guloso.organaziSled(new_solution);


    return new_solution;
}

Solution Vnd::two_opt(Solution solut){
    Solution new_solution;
    int aux;
    for(int i = 0; i < solut.get_num_present(solut.get_presents()); i++){
        for(int j = i + 3; j < solut.get_num_present(solut.get_presents()); j++){
            aux = solut.presents[i].getWeight();
            solut.presents[i].setWeight(solut.presents[j].getWeight());
            solut.presents[j].setWeight(aux);
        }

    }

    new_solution.presents = solv.presents;
    new_solution = guloso.organaziSled(new_solution);

    return new_solution;
}

Solution Vnd::re_insertion(Solution solut){
    Solution new_solution;
    int aux;
    for(int i = 0; i < solut.get_num_present(solut.get_presents()); i++){
        for(int j = i + 1; j < solut.get_num_present(solut.get_presents()); j++){
            aux = solut.presents[i].getWeight();
            solut.presents[i].setWeight(solut.presents[j].getWeight());
            solut.presents[j].setWeight(aux);
        }

    }

    
    new_solution.presents = solv.presents;
    new_solution = guloso.organaziSled(new_solution);

    return new_solution;
}

std::vector<Present> Vnd::performVnd(Solution solv)
{
    int k = 1;
    Solution new_solution;
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
        if(solv.get_num_trenos > new_solution.get_num_trenos){
            solv = new_solution;
            k++;
        }
    }
    
}