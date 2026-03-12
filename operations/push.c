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
void    pa(t_stack *a, t_stack *b)
{
    if (!b || !b->top)
        return;
    push_stack(a , b);
    ft_printf("pa\n");
}
void    pb(t_stack *b, t_stack *a)
{
    if(!a || !a->top)
        return;
    push_stack(b, a);
    ft_printf("pb\n");
}