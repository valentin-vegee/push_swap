#include "push_swap.h"

void    complex_sort(t_push_swap *ps)
{
    int max_bits;
    int bit;
    int size;
    
    bit = 0;
    max_bits = get_max_bits(&ps->a);
    while (bit < max_bits)
    {
        size = ps->a.size;
        while (size > 0)
        {
            if (((ps->a.top->index >> bit) & 1) == 0)
                pb(ps);
            else
                ra(ps);
            size--;
        }
        while (ps->b.size > 0)
            pa(ps);
        bit++;
    }
}
int     get_max_bits(t_stack *stack)
{
    int max_index;
    int bits;

    if(!stack || stack->size <= 1)
        return(0);
    max_index = stack->size - 1;
    bits = 0;
    while (max_index > 0)
    {
        max_index >>= 1;
        bits++;
    }
    return (bits);
}