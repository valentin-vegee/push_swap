#include "push_swap.h"

int     find_index_pos(t_stack *a, int target_index)
{
    t_node  *current;
    int     pos;

    if(!a || !a->top)
        return(-1);
    current = a->top;
    pos = 0;
    while (current)
    {
        if (current->index == target_index)
            return (pos);
        current = current->next;
        pos++;
    }
    return(-1);
}
void    bring_to_top(t_push_swap *ps, int pos)
{
    int moves;

    if (!ps || !ps->a.top || !ps->a.top->next || pos < 0)
        return;
    moves = ps->a.size - pos;
    if (pos <= (ps->a.size/2))
        {
            while(pos != 0)
            {
                ra(ps);
                pos--;
            }
        }
    else
    {
        while (moves != 0)
        {
            rra(ps);
            moves--;
        }
    }
}
void    simple_sort(t_push_swap *ps)
{
    int pos;
    int target;

    target = 0;
    if (!ps || !ps->a.top)
        return;
    if (ps->a.size == 2)
        sa(ps);
    else if (ps->a.size == 3)
        sort_three(ps);
    else
    {
        while (ps->a.size > 0)
        {
            pos = find_index_pos(&ps->a, target);
            if (pos == -1)
                return;
            bring_to_top(ps , pos);
            pb(ps);
            target++;
        }
        while(ps->b.size > 0)
            pa(ps);
    }
}
void    sort_three(t_push_swap *ps)
{
    int first;
    int second;
    int third;

    if (!ps || !ps->a.top || !ps->a.top->next || !ps->a.top->next->next)
        return;
    first = ps->a.top->index;
    second = ps->a.top->next->index;
    third = ps->a.top->next->next->index;
    if (first > second && second < third && first < third)
                sa(ps);
    else if (first > second && second > third)
        {
            sa(ps);
            rra(ps);
        }
    else if (first > second && second < third && first > third)
        ra(ps);
    else if (first < second && second > third && first < third)
    {
        sa(ps);
        ra(ps);
    }
    else if (first < second && second > third && first > third)
                rra(ps);
}
