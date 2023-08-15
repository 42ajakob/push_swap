/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:11:27 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/15 23:52:06 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(unsigned int *a, int *a_len)
{
	unsigned int	tmp;

	if (*a_len < 2)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

int	p(unsigned int *a, unsigned int *b, int *a_len, int *b_len)
{
	unsigned int	swap;
	int				i;

	i = 0;
	if (*a_len == 0)
		return (0);
	swap = a[0];
	while (i < *a_len)
	{
		a[i] = a[i + 1];
		i++;
	}
	i = *b_len;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = swap;
	*a_len -= 1;
	*b_len += 1;
	return (1);
}

int	r(unsigned int *a, int *a_len)
{
	unsigned int	swap;
	int				i;

	i = 0;
	if (*a_len < 2)
		return (0);
	swap = a[0];
	while (i < *a_len)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*a_len - 1] = swap;
	return (1);
}

void	rr(unsigned int *a, int *a_len)
{
	unsigned int	swap;
	int				i;

	i = *a_len - 1;
	if (*a_len < 2)
		return ;
	swap = a[*a_len - 1];
	while (a[i])
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = swap;
	a[*a_len] = 0;
}

void	sort_arr(unsigned int *a, int *a_len)
{
	unsigned int	*copy;
	int				i;
	int				j;

	copy = ft_calloc(sizeof(int), *a_len);
	sort_copy(copy, a, a_len);
	i = 0;
	j = 0;
	while (i < *a_len)
	{
		j = 0;
		while (j < *a_len)
		{
			if (a[i] == copy[j])
				a[i] = j;
			j++;
		}
		i++;
	}
	free(copy);
}
