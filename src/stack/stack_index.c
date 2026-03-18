#include "push_swap.h"

static int	get_rank(t_stack *stack, int value)
{
	t_node	*current;
	int		rank;

	current = stack->top;
	rank = 0;
	while (current)
	{
		if (current->value < value)
			rank++;
		current = current->next;
	}
	return (rank);
}

void	assign_index(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		current->index = get_rank(stack, current->value);
		current = current->next;
	}
}