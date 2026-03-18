#include "push_swap.h"

void    init_bench(t_bench *bench)
{
    if (!bench)
        return;
    bench->executed_strategy = STRAT_ADAPTIVE;
    bench->bool_bench = 0;
    bench->total_ops = 0;
    bench->sa = 0;
    bench->sb = 0;
    bench->ss = 0;
    bench->pa = 0;
    bench->pb = 0;
    bench->ra = 0;
    bench->rb = 0;
    bench->rr = 0;
    bench->rra = 0;
    bench->rrb = 0;
    bench->rrr = 0;
}
void    init_push_swap(t_push_swap *ps)
{
    if (!ps)
        return;
    ps->a.top = NULL;
    ps->a.size = 0;
    ps->b.top = NULL;
    ps->b.size = 0;
    ps->strategy = STRAT_ADAPTIVE;
    ps->disorder = 0.0;
    init_bench(&ps->bench);
}