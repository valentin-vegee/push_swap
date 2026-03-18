#include "push_swap.h"

char    *strategy_name(t_strategy strategy)
{
    if (strategy == STRAT_SIMPLE)
        return ("Simple");
    if (strategy == STRAT_MEDIUM)
        return ("Medium");
    if (strategy == STRAT_COMPLEX)
        return ("Complex");
    if (strategy == STRAT_ADAPTIVE)
        return ("Adaptive");
    return ("unknown");
}
char    *strategy_complexity(t_strategy strategy)
{
    if (strategy == STRAT_SIMPLE)
        return ("O(n\xC2\xB2)");
    if (strategy == STRAT_MEDIUM)
        return ("O(n\xE2\x88\x9A n)");
    if (strategy == STRAT_COMPLEX)
        return ("O(n log n)");
    return("unknown");
}
void    putnbr_fd(int n, int fd)
{
    char    c;

    if (n >= 10)
        putnbr_fd(n / 10, fd);
    c = (n % 10) + '0';
    write(fd, &c ,1);
}

void    putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    if (!str)
        return;
    while(str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}
void    print_bench(t_push_swap *ps)
{
    if (!ps || !ps->bench.bool_bench)
        return;
    print_disorder(ps);
    print_strategy_info(ps);
    print_ops(&ps->bench);

}