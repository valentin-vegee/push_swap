#include "push_swap.h"

void    push_stack(t_stack *dest,t_stack *src)
{
    t_node  *element;

    if(!dest || !src || !src->top)
        return;
    element = src->top;
    src->top = src->top->next;
    element->next = dest->top;
    dest->top = element;
    src->size--;
    dest->size++;
}
void    pa(t_push_swap *ps)
{
    if (!ps || !ps->b.top)
        return;
    push_stack(&ps->a , &ps->b);
    ft_printf("pa\n");
    ps->bench.pa++;
    ps->bench.total_ops++;
}
void    pb(t_push_swap *ps)
{
    if(!ps || !ps->a.top)
        return;
    push_stack(&ps->b, &ps->a);
    ft_printf("pb\n");
    ps->bench.pb++;
    ps->bench.total_ops++;
}