#include"push_swap.h"

void    reverse_rotate_stack(t_stack *stack)
{
    t_node  *last_node;
    t_node  *before_last_node;

    if (!stack || !stack->top || !stack->top->next)
        return;
    last_node = last(stack);
    before_last_node = before_last(stack);
    before_last_node->next = NULL;
    last_node->next = stack->top;
    stack->top = last_node;
}
void    rra(t_push_swap *ps)
{
    if (!ps || !ps->a.top || !ps->a.top->next)
        return;
    reverse_rotate_stack(&ps->a);
    ft_printf("rra\n");
    ps->bench.rra++;
    ps->bench.total_ops++;
}
void    rrb(t_push_swap *ps)
{
    if (!ps || !ps->b.top || !ps->b.top->next)
        return;
    reverse_rotate_stack(&ps->b);
    ft_printf("rrb\n");
    ps->bench.rrb++;
    ps->bench.total_ops++;
}
void    rrr(t_push_swap *ps)
{
    int did;

    did = 0;
    if(!ps)
        return;
    if (ps->a.top && ps->a.top->next)
        {
            reverse_rotate_stack(&ps->a);
            did++;
        }
    if (ps->b.top && ps->b.top->next)
    {
        reverse_rotate_stack(&ps->b);
        did++;
    }
    if (did > 0)
        {
            ft_printf("rrr\n");
            ps->bench.rrr++;
            ps->bench.total_ops++;
        }
}