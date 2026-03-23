#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc < 2)
		return(0);
	init_push_swap(&ps);
	if (!parse_input(argc, argv, &ps))
	{
		write(2, "Error\n", 6);
		clear_stack(&ps.a);
		clear_stack(&ps.b);
		return(1);
	}
	assign_index(&ps.a);
	if(is_sorted(&ps.a))
	{
		clear_stack(&ps.a);
		clear_stack(&ps.b);
		return(0);
	}
	ps.disorder = compute_disorder(&ps.a);
	ps.strategy = STRAT_SIMPLE;
	ps.bench.executed_strategy = STRAT_SIMPLE;
	ps.bench.bool_bench = 1;
	simple_sort(&ps);
	print_bench(&ps);
	clear_stack(&ps.a);
	clear_stack(&ps.b);
	
	return (0);
}
