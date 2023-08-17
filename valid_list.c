/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:21:51 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/17 15:28:20 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	long_check_atoi(const char *s)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	res = res * sign;
	if (res >= -2147483648 && res <= 2147483647)
		return ((int) res);
	return (0);
}

int	valid_char(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '-' && s[i][j] != '+' && s[i][j] != ' '
				&& !(s[i][j] >= 9 && s[i][j] <= 13)
				&& !(s[i][j] >= '0' && s[i][j] <= '9'))
				return (ft_printf("Error\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	valid_int_part_2(char *tmp)
{
	int	len;
	int	k;

	len = 0;
	k = 0;
	while (tmp[k])
	{
		if (tmp[k] != '-' && tmp[k] != '+')
			len++;
		k++;
	}
	if (len == 11 || !long_check_atoi(tmp))
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	valid_int(char **s)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (s[i + 1])
	{
		j = 0;
		tmp = moded_split(s[i + 1]);
		while (tmp[j])
		{
			if (!valid_int_part_2(tmp[j]))
			{
				ft_free(tmp);
				return (0);
			}
			j++;
		}
		if (tmp && tmp[0])
			ft_free(tmp);
		i++;
	}
	return (1);
}

int	int_is_dup(int *a, int *a_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < *a_len)
	{
		j = i + 1;
		while (j < *a_len)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
