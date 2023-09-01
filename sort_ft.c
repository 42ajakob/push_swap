/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:11:27 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/01 16:56:22 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s(int *a, int *a_len)
{
	int	tmp;

	if (*a_len < 2)
		return (0);
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	return (1);
}

int	p(int *a, int *b, int *a_len, int *b_len)
{
	int	swap;
	int	i;

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

int	r(int *a, int *a_len)
{
	int	swap;
	int	i;

	swap = a[0];
	i = 0;
	if (*a_len < 2)
		return (0);
	while (i < *a_len)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*a_len - 1] = swap;
	return (1);
}

int	rr(int *a, int *a_len)
{
	int	swap;
	int	i;

	swap = a[*a_len - 1];
	i = *a_len;
	if (*a_len < 2)
		return (0);
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = swap;
	return (1);
}

void	sort_arr(int *a, int *a_len)
{
	int	*copy;
	int	i;
	int	j;

	copy = ft_calloc(sizeof(int), *a_len);
	i = 0;
	sort_copy(copy, a, a_len);
	while (i < *a_len)
	{
		j = 0;
		while (j < *a_len)
		{
			if (a[i] == copy[j])
			{
				a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}
