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

int Solution::get_num_trenos(std::vector<Treno> trenos){
    return trenos.size();
}

int Solution::get_num_present(std::vector<Present> present){
    return present.size();
}
