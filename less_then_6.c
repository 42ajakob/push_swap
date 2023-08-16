/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_then_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:38:54 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/16 16:33:08 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_three(int *a, int *a_len, int plus)
{
	if (a[0] == 2 + plus && a[1] == 1 + plus
		&& a[2] == 0 + plus
		&& s(a, a_len) && rr(a, a_len))
		ft_printf("sa\nrra\n");
	else if (a[0] == 2 + plus && a[1] == 0 + plus
		&& a[2] == 1 + plus
		&& r(a, a_len))
		ft_printf("ra\n");
	else if (a[0] == 1 + plus && a[1] == 0 + plus
		&& a[2] == 2 + plus && s(a, a_len))
		ft_printf("sa\n");
	else if (a[0] == 1 + plus && a[1] == 2 + plus
		&& a[2] == 0 + plus && rr(a, a_len))
		ft_printf("rra\n");
	else if (a[0] == 0 + plus && a[1] == 2 + plus
		&& a[2] == 1 + plus
		&& r(a, a_len) && s(a, a_len) && rr(a, a_len))
		ft_printf("ra\nsa\nrra\n");
}

void	if_four(int *a, int *b, int *a_len, int *b_len)
{
	if (a[0] == 0 && p(a, b, a_len, b_len))
	{
		ft_printf("pb\n");
		if_three(a, a_len, 1);
		p(b, a, b_len, a_len);
		ft_printf("pa\n");
	}
	else if (r(a, a_len))
		ft_printf("ra\n");
}

void	if_five(int *a, int *b, int *a_len, int *b_len)
{
	if (*b_len == 2 && a[0] == 2 && a[1] == 3
		&& a[2] == 4 && b[0] == 1 && b[1] == 0)
	{
		p(b, a, b_len, a_len);
		p(b, a, b_len, a_len);
		ft_printf("pa\npa\n");
	}
	else if ((a[0] == 0 || a[0] == 1) && p(a, b, a_len, b_len))
		ft_printf("pb\n");
	else if (*a_len == 3)
	{
		if_three(a, a_len, 2);
		if (b[0] == 0 && s(b, b_len))
			ft_printf("sb\n");
	}
	else if (r(a, a_len))
		ft_printf("ra\n");
}
