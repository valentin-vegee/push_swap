#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc < 2)
		return(0);
	init_push_swap(&ps);
	parse_input(argc, argv, &ps);
	if (!parse_input(argc, argv, &ps))
	{
		write(2, "Error\n", 6);
		clear_stack(&ps.a);
		clear_stack(&ps.b);
		return(1);
	}
	if(is_sorted(&ps.a))
	{
		clear_stack(&ps.a);
		clear_stack(&ps.b);
		return(0);
	}
	ps.disorder = compute_disorder(&ps.a);

	run_strategy(&ps);
	print_bench(&ps);
	clear_stack(&ps.a);
	clear_stack(&ps.b);
	
	return (0);
}

#include "push_swap.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
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

	ps.a.top = NULL;
	ps.a.size = 0;
	ps.b.top = NULL;
	ps.b.size = 0;
	ps.strategy = STRAT_ADAPTIVE;
	ps.disorder = 0.0;
	if (!parse_input(argc, argv, &ps))
	{
		print_error();
		clear_stack(&ps.a);
		return (1);
	}
	ps.disorder = compute_disorder(&ps.a);
	printf("disorder = %.4f\n\n", ps.disorder);
	print_stack(&ps.a, 'A');
	print_stack(&ps.b, 'B');
	clear_stack(&ps.a);
	clear_stack(&ps.b);
	return (0);
}