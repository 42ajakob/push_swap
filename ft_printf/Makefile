# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 21:33:02 by ajakob            #+#    #+#              #
#    Updated: 2023/08/17 17:17:55 by ajakob           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CFLAGS = -c -Wall -Wextra -Werror
LIBFT	= libft/libft.a

SRCS	= ft_printf_utils.c \
			ft_printf.c \
			ft_puthexa.c \
			ft_putunbr.c
OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(SRCS)
	@cp -n $(LIBFT) $(NAME)
	@$(AR) -rcs $(NAME) $(OBJS)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re