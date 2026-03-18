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
	if(is_sorted(&ps.a))
	{
		clear_stack(&ps.a);
		clear_stack(&ps.b);
		return(0);
	}
	ps.disorder = compute_disorder(&ps.a);
	// run_strategy(&ps);
	print_bench(&ps);
	clear_stack(&ps.a);
	clear_stack(&ps.b);
	
	return (0);
}