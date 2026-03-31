#include "push_swap.h"

static void	push_chunks(t_push_swap *ps, int chunk_size)
{
	int	pushed;
	int	limit;

	pushed = 0;
	limit = chunk_size - 1;
	while (ps->a.size > 0)
	{
		if (ps->a.top->index <= pushed)
		{
			pb(ps);
			rb(ps);
			pushed++;
			limit = pushed + chunk_size - 1;
		}
		else if (ps->a.top->index <= limit)
		{
			pb(ps);
			pushed++;
			limit = pushed + chunk_size - 1;
		}
		else
			move_range_to_top(ps, limit);
	}
}

static void	push_back_to_a(t_push_swap *ps)
{
	while (ps->b.size > 0)
	{
		move_max_to_top(ps);
		pa(ps);
	}
}

void	sort_medium(t_push_swap *ps)
{
	int	chunk_size;

	if (!ps || ps->a.size <= 1 || is_sorted(&ps->a))
		return ;
	if (ps->a.size == 2)
	{
		if (ps->a.top->index > ps->a.top->next->index)
			sa(ps);
		return ;
	}
	chunk_size = get_chunk_size(ps->a.size);
	push_chunks(ps, chunk_size);
	push_back_to_a(ps);
}