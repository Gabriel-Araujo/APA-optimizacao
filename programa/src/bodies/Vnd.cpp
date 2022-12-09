#include "Vnd.h"

Vnd::Vnd()
{

}

std::vector<Present> Vnd::performVnd(Solution solution)
{
    int k = 1;
    while (k <= 3)
    {
        switch (k)
        {
        case 1:
            swap();
            break;
        case 2:
            two_opt();
            break;
        case 3:
            re_insertion();
            break;
        }
    }
    
}