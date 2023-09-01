/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:40:48 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/01 15:22:44 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

int		valid_char(char **s);
int		valid_int(char **s);
int		int_is_dup(int *a, int *a_len);
int		*copy_list(char **s, int *a_len);
int		check_list(int *a, int *a_len);
void	sort_copy(int *copy, int *a, int *a_len);
void	sort_arr(int *a, int *a_len);
void	if_three(int *a, int *a_len, int plus);
void	if_four(int *a, int *b, int *a_len, int *b_len);
void	if_five(int *a, int *b, int *a_len, int *b_len);
void	ft_free(char **s);
int		s(int *a, int *a_len);
int		p(int *a, int *b, int *a_len, int *b_len);
int		r(int *a, int *a_len);
int		rr(int *a, int *a_len);

#endif