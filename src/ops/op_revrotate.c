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
void    rra(t_stack *a)
{
    if (!a || !a->top || !a->top->next)
        return;
    reverse_rotate_stack(a);
    printf("rra\n");
}
void    rrb(t_stack *b)
{
    if (!b || !b->top || !b->top->next)
        return;
    reverse_rotate_stack(b);
    printf("rrb\n");
}
void    rrr(t_stack *a, t_stack *b)
{
    int did;

    did = 0;
    if (a && a->top && a->top->next)
        {
            reverse_rotate_stack(a);
            did++;
        }
    if (b && b->top && b->top->next)
    {
        reverse_rotate_stack(b);
        did++;
    }
    if (did > 0)
        printf("rrr\n");
}