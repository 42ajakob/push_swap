NAME		= push_swap

CFLAGS		= -Wall -Wextra -Werror
LIBFTPRINTF	= ft_printf/libftprintf.a

SRCS		= push_swap.c \
				moded_split.c \
				push_swap_utils.c \
				sort_ft.c \
				valid_list.c \
				less_then_6.c
OBJS		= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf/
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME)

clean:
	@make -C ft_printf/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re