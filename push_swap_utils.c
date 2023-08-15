/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:13:06 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/15 23:52:15 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	long_check_ft_atoui(const char *s, unsigned int *a)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' && (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	res = res * sign;
	if (res >= -2147483648 && res <= 2147483647)
	{
		*a = res + 2147483648;
		return (1);
	}
	return (0);
}

static int	is_str_dup(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = i + 1;
		while (s[j] && ft_strcmp(s[i], s[j]))
			j++;
		if (s[j] && !ft_strcmp(s[i], s[j]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_list(int argc, char **s)
{
	int				i;
	unsigned int	j;
	int				len;

	i = 1;
	if (argc < 2)
		return (0);
	while (s[i])
	{
		j = 0;
		len = 0;
		while (s[i][j])
		{
			if (s[i][j] != '-' && s[i][j] != '+'
				&& !(s[i][j] >= '0' && s[i][j] <= '9'))
				return (ft_printf("Error\n"), 0);
			if (len <= 10 && (s[i][j] >= '0' && s[i][j] <= '9'))
				len++;
			j++;
		}
		if (len == 11 || !long_check_ft_atoui(s[i], &j) || !is_str_dup(s))
			return (ft_printf("Error\n"), 0);
		i++;
	}
	return (1);
}

int	check_list(unsigned int *a, int a_len)
{
	int	i;

	i = 0;
	while (i < a_len - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_copy(unsigned int *copy, unsigned int *a, int *a_len)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < *a_len)
	{
		copy[i] = a[i];
		i++;
	}
	i = 0;
	while (i++ < *a_len)
	{
		j = 0;
		while (j++ < *a_len - 1)
		{
			if (copy[j] > copy[j + 1])
			{
				tmp = copy[j + 1];
				copy[j + 1] = copy[j];
				copy[j] = tmp;
			}
		}
	}
}
