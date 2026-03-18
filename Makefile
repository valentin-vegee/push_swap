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
	src/stack/utils_2.c \
	src/stack/utils.c \
	bench/bench.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(INCLUDES) -o $(NAME)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all