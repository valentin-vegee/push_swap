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
void    adaptive_sort(t_push_swap *ps)
{
    if (!ps)
        return;
    if (ps->disorder < 0.2)
    {
        ps->bench.executed_strategy = STRAT_SIMPLE;
        simple_sort(ps);
    }
    else if (ps->disorder >= 0.2 && ps->disorder < 0.5)
    {
        ps->bench.executed_strategy = STRAT_MEDIUM;
        medium_sort(ps);
    }
    else if (ps->disorder >= 0.5)
    {
        ps->bench.executed_strategy = STRAT_COMPLEX;
        complex_sort(ps);
    }
}
void    run_strategy(t_push_swap *ps)
{
    if (!ps)
        return;
    if (ps->strategy == STRAT_ADAPTIVE)
        adaptive_sort(ps);
    else if (ps->strategy == STRAT_SIMPLE)
        {
            ps->bench.executed_strategy = STRAT_SIMPLE;
            simple_sort(ps);
        }
    else if (ps->strategy == STRAT_MEDIUM)
        {
            ps->bench.executed_strategy = STRAT_MEDIUM;
            medium_sort(ps);
        }
    else if (ps->strategy == STRAT_COMPLEX)
        {
            ps->bench.executed_strategy = STRAT_COMPLEX;
            complex_sort(ps);
        }
}