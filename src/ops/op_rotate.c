#include "push_swap.h"

void    rotate_stack(t_stack *stack)
{
    t_node *element;

    if(!stack || !stack->top || !stack->top->next)
        return;
    element = stack->top;
    stack->top = stack->top->next;
    last(stack)->next = element;
    element->next = NULL;
}
void    ra(t_push_swap *ps)
{
    if (!ps || !ps->a.top || !ps->a.top->next)
        return;
    rotate_stack(&ps->a);
    ft_printf("ra\n");
    ps->bench.ra++;
    ps->bench.total_ops++;
}
void    rb(t_push_swap *ps)
{
    if (!ps || !ps->b.top || !ps->b.top->next)
        return;
    rotate_stack(&ps->b);
    ft_printf("rb\n");
    ps->bench.rb++;
    ps->bench.total_ops++;
}
void    rr(t_push_swap *ps)
{
    int rotated;

    rotated = 0;
    if(!ps)
        return;
    if (ps->a.top && ps->a.top->next)
    {
            rotate_stack(&ps->a);
            rotated++;
    }
    if (ps->b.top && ps->b.top->next)
    {
        rotate_stack(&ps->b);
        rotated++;
    }
    if (rotated > 0)
        {
            ft_printf("rr\n");
            ps->bench.rr++;
            ps->bench.total_ops++;
        }
}