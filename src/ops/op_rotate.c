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
void    ra(t_stack *a)
{
    if (!a || !a->top || !a->top->next)
        return;
    rotate_stack(a);
    printf("ra\n");
}
void    rb(t_stack *b)
{
    if (!b || !b->top || !b->top->next)
        return;
    rotate_stack(b);
    printf("rb\n");
}
void    rr(t_stack *a, t_stack *b)
{
    int rotated;

    rotated = 0;
    if (a && a->top && a->top->next)
    {
            rotate_stack(a);
            rotated++;
    }
    if (b && b->top && b->top->next)
    {
        rotate_stack(b);
        rotated++;
    }
    if (rotated > 0)
        printf("rr\n");
}