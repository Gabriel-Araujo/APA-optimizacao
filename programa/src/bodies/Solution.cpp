#include "../headers/Solution.h"

Solution::Solution()
{

}

std::vector<Present> Solution::get_presents() {
    return presents;
}

std::vector<Treno> Solution::get_trenos(){
    return trenos;
}

int Solution::get_num_trenos(){
    return this->trenos.size();
}

int Solution::get_num_present(){
    return this->presents.size();
}
