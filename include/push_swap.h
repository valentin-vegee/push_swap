#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"

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

typedef	struct s_bench
{
	t_strategy	executed_strategy;
	int			total_ops;
	int			bool_bench;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_bench;

typedef struct s_push_swap
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	double		disorder;
	t_bench		bench;
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

int	is_sorted(t_stack *stack);
double compute_disorder(t_stack *stack);

void    reverse_rotate_stack(t_stack *stack);
void    rra(t_push_swap *ps);
void    rrb(t_push_swap *ps);
void    rrr(t_push_swap *ps);
void    rotate_stack(t_stack *stack);
void    ra(t_push_swap *ps);
void    rb(t_push_swap *ps);
void    rr(t_push_swap *ps);
void    push_stack(t_stack *dest,t_stack *src);
void    pa(t_push_swap *ps);
void    pb(t_push_swap *ps);
void    swap_stack(t_stack *stack);
void    sa(t_push_swap *ps);
void    sb(t_push_swap *ps);
void    ss(t_push_swap *ps);

t_node	*last(t_stack *stack);
t_node	*before_last(t_stack *stack);
t_node	*get_by_pos(t_stack *stack, int position);

#endif