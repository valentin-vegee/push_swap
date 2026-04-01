

#include "push_swap.h" 

static int set_strategy(t_push_swap *ps, t_strategy strategy, int *strategy_set)
{
	if (*strategy_set)
		return (0);
	ps->strategy = strategy;
	*strategy_set = 1;
	return (1);
}
static int parse_flag(char *arg, t_push_swap *ps, int *strategy_set, int *bench_set)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{ 
		if (*bench_set)
			return (0);
	ps->bench.bool_bench = 1; 
	*bench_set = 1; 
	} 
	else if (ft_strcmp(arg, "--simple") == 0) 
		return (set_strategy(ps, STRAT_SIMPLE, strategy_set)); 
	else if (ft_strcmp(arg, "--medium") == 0) 
		return (set_strategy(ps, STRAT_MEDIUM, strategy_set)); 
	else if (ft_strcmp(arg, "--complex") == 0) 
		return (set_strategy(ps, STRAT_COMPLEX, strategy_set)); 
	else if (ft_strcmp(arg, "--adaptive") == 0)
		return (set_strategy(ps, STRAT_ADAPTIVE, strategy_set));
	else 
		return (0);
	return (1); 
} 
static int parse_token(char *token, t_stack *a)
{
	long nb;
	if (!token || token[0] == '\0')
		return (0);
	if (!is_valid_number(token))
		return (0);
	nb = ft_atol(token);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	if (has_duplicate(a, (int)nb))
		return (0); 
	if (!stack_add_back(a, (int)nb))
		return (0);
	return (1); 
} 
static int parse_arg(char *arg, t_stack *a)
{ 
	char **split;
	int i; 
	if (!arg || arg[0] == '\0') 
		return (0); 
	split = ft_split(arg, ' '); 
	if (!split) 
		return (0); 
	if (!split[0]) 
	{ 
		free_split(split); 
		return (0); 
	} 
	i = 0; 
	while (split[i]) 
	{ 
		if (!parse_token(split[i], a)) 
		{ 
			free_split(split); 
			return (0); 
		} 
		i++; 
	} 
	free_split(split); 
	return (1); 
} 
int parse_input(int argc, char **argv, t_push_swap *ps) 
{ 
	int i; 
	int strategy_set; 
	int bench_set; 
	if (argc < 2) 
		return (1); 
	ps->strategy = STRAT_ADAPTIVE; 
	ps->bench.bool_bench = 0; i = 1; 
	strategy_set = 0; 
	bench_set = 0; 
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-') 
	{ 
		if (!parse_flag(argv[i], ps, &strategy_set, &bench_set)) 
			return (0); 
		i++; 
	} 
	if (i >= argc) 
		return (0); 
	while (i < argc) 
	{ 
		if (!parse_arg(argv[i], &ps->a)) 
			return (0); 
		i++; 
	} 
	if (ps->a.size == 0) 
		return (0); 
	return (1); 
}

