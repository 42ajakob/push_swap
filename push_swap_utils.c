/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:13:06 by ajakob            #+#    #+#             */
/*   Updated: 2023/09/01 15:24:03 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	check_list(int *a, int *a_len)
{
	int	i;

	i = 0;
	while (i < *a_len - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_copy(int *copy, int *a, int *a_len)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < *a_len)
		copy[i] = a[i];
	i = 0;
	while (i++ < *a_len)
	{
		j = 0;
		while (j < *a_len - 1)
		{
			if (copy[j] > copy[j + 1])
			{
				tmp = copy[j + 1];
				copy[j + 1] = copy[j];
				copy[j] = tmp;
			}
			j++;
		}
	}
}

int	*copy_list(char **s, int *a_len)
{
	char	**tmp;
	int		*a;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	a = ft_calloc(sizeof(int), *a_len);
	while (1)
	{
		j = 0;
		if (s[i + 1] == NULL)
			break ;
		tmp = ft_split(s[i++ + 1], ' ');
		while (tmp[j])
		{
			a[k++] = ft_atoi(tmp[j]);
			free(tmp[j++]);
		}
		if (tmp)
			free(tmp);
		a[k] = 0;
	}
	return (a);
}
