#include "push_swap.h"

char    *strategy_name(t_strategy strategy)
{
    if (strategy == STRAT_SIMPLE)
        return ("simple");
    if (strategy == STRAT_MEDIUM)
        return ("medium");
    if (strategy == STRAT_COMPLEX)
        return ("complex");
    if (strategy == STRAT_ADAPTIVE)
        return ("adaptive");
    return("unknow");
}
char    *strategy_complexity(t_strategy strategy)
{
    // return O(n^2) ou O(sqrt(n)) ou "O(n log n)"
}