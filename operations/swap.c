void    swap_stack(t_stack *stack)
{
    t_node  *first;
    t_node  *second;
    t_node  *third;

    if(!stack || !stack->top || !stack->top->next)
        return;
    first = stack->top;
    second = stack->top->next;
    third = stack->top->next->next;
    stack->top = second;
    stack->top->next = first;
    first->next = third;
}
void    sa(t_stack *stack)
{
    if(!stack || !stack->top || !stack->top->next)
        return;
    swap_stack(stack);
    ft_printf("sa\n");
}
void    sb(t_stack *stack)
{
    if(!stack || !stack->top || !stack->top->next)
        return;
    swap_stack(stack);
    ft_printf("sb\n");
}
void    ss(t_stack *stack_a, t_stack *stack_b)
{
    int swapped;

    swapped = 0;
    if(stack_a && stack_a->top && stack_a->top->next)
            {
                swap_stack(stack_a);
                swapped++;
            }
    if(stack_b && stack_b->top && stack_b->top->next)
        {
            swap_stack(stack_b);
            swapped++;
        }
    if(swapped > 0)
        ft_printf("ss\n");
}