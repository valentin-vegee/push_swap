#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

int		parse_input(int argc, char **argv, t_push_swap *ps);

int		is_valid_number(char *str);
long	ft_atol(const char *str);
int		has_duplicate(t_stack *stack, int value);

t_node	*node_new(int value);
int		stack_add_back(t_stack *stack, int value);
void	free_split(char **tab);
void	clear_stack(t_stack *stack);

char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);

#endif