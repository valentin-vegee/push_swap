#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

int	stack_add_back(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = node_new(value);
	if (!new_node)
		return (0);
	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
	return (1);
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clear_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
}