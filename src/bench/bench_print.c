#include "push_swap.h"

void    print_strategy_info(t_push_swap *ps)
{
    if (!ps)
        return;
    putstr_fd("[bench] strategy: ", 2);
    putstr_fd(strategy_name(ps->bench.executed_strategy), 2);
    write(2, " (", 2);
    putstr_fd(strategy_complexity(ps->bench.executed_strategy), 2);
    write(2, ")\n", 2);
}
void    print_ops(t_bench *bench)
{
    if (!bench)
        return;
    putstr_fd("[bench] total_ops: ", 2);
    putnbr_fd(bench->total_ops, 2);
    write(2, "\n", 1);
    print_ops_push_swap(bench);
    print_ops_rotate(bench);
}
void    print_ops_push_swap(t_bench *bench)
{
     if (!bench)
        return;
    putstr_fd("[bench] sa: ", 2);
    putnbr_fd(bench->sa, 2);
    putstr_fd(" sb: ", 2);
    putnbr_fd(bench->sb, 2);
    putstr_fd(" ss: ", 2);
    putnbr_fd(bench->ss, 2);
    putstr_fd(" pa: ", 2);
    putnbr_fd(bench->pa, 2);
    putstr_fd(" pb: ", 2);
    putnbr_fd(bench->pb, 2);
    write(2, "\n", 1);
}
void    print_ops_rotate(t_bench *bench)
{
     if (!bench)
        return;
    putstr_fd("[bench] ra: ", 2);
    putnbr_fd(bench->ra, 2);
    putstr_fd(" rb: ", 2);
    putnbr_fd(bench->rb, 2);
    putstr_fd(" rr: ", 2);
    putnbr_fd(bench->rr, 2);
    putstr_fd(" rra: ", 2);
    putnbr_fd(bench->rra, 2);
    putstr_fd(" rrb: ", 2);
    putnbr_fd(bench->rrb, 2);
    putstr_fd(" rrr: ", 2);
    putnbr_fd(bench->rrr, 2);
    write(2, "\n", 1);
}
void    print_disorder(t_push_swap *ps)
{
    int scaled;
    int percent_int;
    int percent_dec;

    if(!ps)
        return;

    scaled = (int)(ps->disorder * 10000 + 0.5);
    percent_int = scaled / 100;
    percent_dec = scaled % 100;
    putstr_fd("[bench] disorder: ", 2);
    putnbr_fd(percent_int, 2);
    write(2, ".", 1);
    if (percent_dec < 10)
        write(2, "0", 1);
    putnbr_fd(percent_dec, 2);
    putstr_fd("%\n", 2);
}