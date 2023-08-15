NAME		= push_swap

CFLAGS		= -Wall -Wextra -Werror
LIBFTPRINTF	= ft_printf/libftprintf.a

SRCS		= $(shell find ./ -maxdepth 1 -iname "*.c")
OBJS		= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf/
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFTPRINTF) -o $(NAME)

clean:
	@make -C ft_printf/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re