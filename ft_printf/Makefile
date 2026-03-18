NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c  utils/ft_print_else.c utils/ft_print_print.c 
OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)

all: $(NAME)

$(NAME) : $(OBJ) Makefile
	$(AR) $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)