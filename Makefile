NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include -I ft_printf

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = src/main.c \
	src/parse/parse.c \
	src/parse/parse_utils.c \
	src/parse/stack_parse_utils.c \
	src/parse/ft_split.c \
	src/parse/ft_strcmp.c \
	src/ops/op_push.c \
	src/ops/op_revrotate.c \
	src/ops/op_rotate.c \
	src/ops/op_swap.c \
	src/stack/stack_access.c \
	src/stack/stack_analysis.c \
	src/bench/bench_print.c \
	src/bench/bench_utils.c \
	src/init/init.c \
	src/algo/simple.c

OBJ_DIR = .build
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(INCLUDES) -o $(NAME)

$(OBJ_DIR)/%.o: %.c include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
