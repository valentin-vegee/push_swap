/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenavid <tbenavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:06:57 by tbenavid          #+#    #+#             */
/*   Updated: 2026/03/09 15:17:10 by tbenavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if(!stack || !stack->top)
		return(1);
	current = stack->top;	
	while(current->next)
	{
		if(current->value > current->next->value)
			return(0);
		current = current->next;
	}
	return(1);
}
double compute_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	t_node	*outer;
	t_node	*inner;

	mistakes = 0;
	total_pairs = 0;
	if(!stack || !stack->top || !stack->top->next)
		return(0.0);
	outer = stack->top;
	while(outer->next)
	{
		inner = outer->next;
		while(inner)
		{
			total_pairs++;
			if(outer->value > inner->value)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return(mistakes / total_pairs);
}