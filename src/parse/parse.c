#include "push_swap.h"

static int	parse_flag(char *arg, t_push_swap *ps)
{
	if (ft_strcmp(arg, "--simple") == 0)
		ps->strategy = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		ps->strategy = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		ps->strategy = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		ps->strategy = STRAT_ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	parse_token(char *token, t_stack *a)
{
	long	nb;

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

static int	parse_arg(char *arg, t_stack *a)
{
	char	**split;
	int		i;

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

int	parse_input(int argc, char **argv, t_push_swap *ps)
{
	int	i;

	if (argc < 2)
		return (1);
	ps->strategy = STRAT_ADAPTIVE;
	i = 1;
	if (argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!parse_flag(argv[i], ps))
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
