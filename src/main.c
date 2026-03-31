#include "push_swap.h"
#include <stdio.h>

static int	exit_error(t_push_swap *ps)
{
	write(2, "Error\n", 6);
	clear_stack(&ps->a);
	clear_stack(&ps->b);
	return (1);
}

static void	cleanup_push_swap(t_push_swap *ps)
{
	clear_stack(&ps->a);
	clear_stack(&ps->b);
}

static void	print_stack(t_stack *stack, char name)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	printf("stack %c (size = %d)\n", name, stack->size);
	printf("-----------------\n");
	while (current)
	{
		printf("[%d] value = %d | index = %d\n", i, current->value, current->index);
		current = current->next;
		i++;
	}
	if (stack->size == 0)
		printf("(empty)\n");
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		return (0);
	init_push_swap(&ps);
	if (!parse_input(argc, argv, &ps))
		return (exit_error(&ps));
	assign_index(&ps.a);
	printf("=== BEFORE SORT ===\n");
	print_stack(&ps.a, 'A');
	print_stack(&ps.b, 'B');
	if (is_sorted(&ps.a))
	{
		printf("Pile deja triee.\n\n");
		cleanup_push_swap(&ps);
		return (0);
	}
	ps.disorder = compute_disorder(&ps.a);
	run_strategy(&ps);
	printf("\n=== AFTER SORT ===\n");
	print_stack(&ps.a, 'A');
	print_stack(&ps.b, 'B');
	print_bench(&ps);
	cleanup_push_swap(&ps);
	return (0);
}

// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_push_swap ps;

// 	if (argc < 2)
// 		return(0);
// 	init_push_swap(&ps);
// 	if (!parse_input(argc, argv, &ps))
// 	{
// 		write(2, "Error\n", 6);
// 		clear_stack(&ps.a);
// 		clear_stack(&ps.b);
// 		return(1);
// 	}
// 	assign_index(&ps.a);
// 	if(is_sorted(&ps.a))
// 	{
// 		clear_stack(&ps.a);
// 		clear_stack(&ps.b);
// 		return(0);
// 	}
// 	ps.disorder = compute_disorder(&ps.a);
// 	run_strategy(&ps);
// 	print_bench(&ps);
// 	clear_stack(&ps.a);
// 	clear_stack(&ps.b);
	
// 	return (0);
// }
