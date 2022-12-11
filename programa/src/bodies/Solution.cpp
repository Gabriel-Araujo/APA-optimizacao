#include "../headers/Solution.h"

Solution::Solution()
{

}

std::vector<Present> Solution::get_presents() {
    return presents;
}

std::vector<Treno> Solution::get_trenos(){
    return this->trenos;
}

int Solution::get_num_trenos(){
    return this->trenos.size();
}

int Solution::get_num_present(){
    return this->presents.size();
}

void Solution::set_pair_matrix(std::vector<std::vector<bool>> matrix) {
    this->pairs_matrix = matrix;
}


std::vector<std::vector<bool>> Solution::get_pair_matrix() {
    return this->pairs_matrix;
}
