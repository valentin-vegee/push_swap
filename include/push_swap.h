#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_push_swap
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	double		disorder;
}	t_push_swap;

#endif
