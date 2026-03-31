#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	chunk += chunk / 2;
	if (chunk > size)
		chunk = size;
	return (chunk);
}

static int	find_pos_in_range(t_stack *stack, int max_index)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->index <= max_index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	move_range_to_top(t_push_swap *ps, int max_index)
{
	int	pos;
	int	moves;

	pos = find_pos_in_range(&ps->a, max_index);
	if (pos < 0)
		return ;
	if (pos <= ps->a.size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			ra(ps);
	}
	else
	{
		moves = ps->a.size - pos;
		while (moves-- > 0)
			rra(ps);
	}
}

static int	find_max_pos(t_stack *stack)
{
	int		pos;
	int		max_pos;
	int		max_index;
	t_node	*current;

	pos = 0;
	max_pos = 0;
	max_index = -1;
	current = stack->top;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	move_max_to_top(t_push_swap *ps)
{
	int	pos;
	int	moves;

	pos = find_max_pos(&ps->b);
	if (pos <= ps->b.size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			rb(ps);
	}
	else
	{
		moves = ps->b.size - pos;
		while (moves-- > 0)
			rrb(ps);
	}
}