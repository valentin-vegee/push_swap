#include "push_swap.h"

void    swap_stack(t_stack *stack)
{
    t_node  *first;
    t_node  *second;
    t_node  *third;

    if(!stack || !stack->top || !stack->top->next)
        return;
    first = stack->top;
    second = stack->top->next;
    third = second->next;
    stack->top = second;
    stack->top->next = first;
    first->next = third;
}
void    sa(t_push_swap *ps)
{
    if(!ps || !ps->a.top || !ps->a.top->next)
        return;
    swap_stack(&ps->a);
    ft_printf("sa\n");
    ps->bench.sa++;
    ps->bench.total_ops++;
}
void    sb(t_push_swap *ps)
{
    if(!ps || !ps->b.top || !ps->b.top->next)
        return;
    swap_stack(&ps->b);
    ft_printf("sb\n");
    ps->bench.sb++;
    ps->bench.total_ops++;
}
void    ss(t_push_swap *ps)
{
    int swapped;

    swapped = 0;
    if(!ps)
        return;
    if(ps->a.top && ps->a.top->next)
            {
                swap_stack(&ps->a);
                swapped++;
            }
    if(ps->b.top && ps->b.top->next)
        {
            swap_stack(&ps->b);
            swapped++;
        }
    if(swapped > 0)
        {
            ft_printf("ss\n");
            ps->bench.ss++;
            ps->bench.total_ops++;
        }
}