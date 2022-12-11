#ifndef APA_VND_H
#define APA_VND_H

#pragma once

#include "../headers/Solution.h"
#include "../headers/guloso.h++"


class Vnd {

public:
    Vnd();
    Vnd(InputHandler input);

    Solution performVnd(Solution *solv);
    unsigned swap(Solution &solution_atual);
    unsigned two_opt(Solution &solution_atual);
    static unsigned int _2_opt(Solution *solut);
    static unsigned int re_insertion(Solution *solut);

private:
    InputHandler input;

    static void distribuir_itens(Treno *treno, std::vector<Treno> *trenos, std::vector<std::vector<bool>> matrix);
    static bool verificar_compatibilidade_presentes(Treno &treno, Treno &treno2, std::vector<std::vector<bool>> matrix);

};

#endif