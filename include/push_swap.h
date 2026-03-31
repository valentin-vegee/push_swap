
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"
# include <stdio.h>

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

/* PARSE */
int		parse_input(int argc, char **argv, t_push_swap *ps);
int		is_valid_number(char *str);
long	ft_atol(const char *str);
int		has_duplicate(t_stack *stack, int value);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	free_split(char **tab);

/* STACK */
t_node	*node_new(int value);
int		stack_add_back(t_stack *stack, int value);
void	clear_stack(t_stack *stack);
t_node	*last(t_stack *stack);
t_node	*before_last(t_stack *stack);
t_node	*get_by_pos(t_stack *stack, int position);
void	assign_index(t_stack *stack);

/* UTILS */
int		is_sorted(t_stack *stack);
double	compute_disorder(t_stack *stack);
void    putnbr_fd(int n, int fd);
void    putstr_fd(char *str, int fd);

/* OPERATIONS */
void	swap_stack(t_stack *stack);
void	sa(t_push_swap *ps);
void	sb(t_push_swap *ps);
void	ss(t_push_swap *ps);

void	push_stack(t_stack *dest, t_stack *src);
void	pa(t_push_swap *ps);
void	pb(t_push_swap *ps);

void	rotate_stack(t_stack *stack);
void	ra(t_push_swap *ps);
void	rb(t_push_swap *ps);
void	rr(t_push_swap *ps);

void	reverse_rotate_stack(t_stack *stack);
void	rra(t_push_swap *ps);
void	rrb(t_push_swap *ps);
void	rrr(t_push_swap *ps);

/*BENCH*/
void    print_bench(t_push_swap *ps);
void    print_strategy_info(t_push_swap *ps);
void    print_ops(t_bench *bench);
void    print_ops_push_swap(t_bench *bench);
void    print_ops_rotate(t_bench *bench);
void    print_disorder(t_push_swap *ps);
char    *strategy_name(t_strategy strategy);
char    *strategy_complexity(t_strategy strategy);

/*INIT*/
void    init_bench(t_bench *bench);
void    init_push_swap(t_push_swap *ps);
void	assign_index(t_stack *stack);

/*LAUNCHER*/
void    adaptive_sort(t_push_swap *ps);
void    run_strategy(t_push_swap *ps);

/*ALGOS*/
void	simple_sort(t_push_swap *ps);
void	complex_sort(t_push_swap *ps);
int     find_index_pos(t_stack *a, int target_index);
void    bring_to_top(t_push_swap *ps, int pos);
void    sort_three(t_push_swap *ps);
int     get_max_bits(t_stack *stack);
void	sort_medium(t_push_swap *ps);
int		get_chunk_size(int size);
void	move_range_to_top(t_push_swap *ps, int max_index);
void	move_max_to_top(t_push_swap *ps);

#endif

