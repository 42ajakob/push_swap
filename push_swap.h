/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:40:48 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/15 23:53:12 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

int				valid_list(int argc, char **s);
unsigned int	long_check_ft_atoui(const char *s, unsigned int *a);
int				check_list(unsigned int *a, int a_len);
void			sort_copy(unsigned int *copy, unsigned int *a, int *a_len);
void			sort_arr(unsigned int *a, int *a_len);
void			s(unsigned int *a, int *a_len);
int				p(unsigned int *a, unsigned int *b, int *a_len, int *b_len);
int				r(unsigned int *a, int *a_len);
void			rr(unsigned int *a, int *a_len);

#endif