#include "push_swap.h"

t_node	*last(t_stack *stack)
{
	t_node	*current;
	
	if(!stack || stack->top == NULL)
		return(NULL);
	current = stack->top;
	while(current->next)
		current = current->next;
	return(current);
}

t_node	*before_last(t_stack *stack)
{
	t_node	*current;

	if(!stack || !stack->top || !stack->top->next)
		return(NULL);
	current = stack->top;
	while(current->next->next)
	{
		current = current->next;
	}
	return(current);
}

t_node	*get_by_pos(t_stack *stack, int position)
{
	int	i;
	t_node *current;

	i = 0;
	if(!stack || position < 0)
		return(NULL);
	current = stack->top;
	while(current && i < position)
	{
		i++;
		current = current->next;
	}
	return(current);
}