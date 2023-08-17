/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:40:39 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/17 17:40:41 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_list(char **s, int *a_len)
{
	char	**tmp;
	int		*a;
	int		i;
	int		j;

	j = 0;
	while (s[j + 1])
	{
		i = 0;
		tmp = moded_split(s[j + 1]);
		while (tmp[i])
		{
			*a_len = *a_len + 1;
			i++;
		}
		ft_free(tmp);
		j++;
	}
	a = copy_list(s, a_len);
	return (a);
}

static void	sort_small(int *a, int *b, int *a_len, int *b_len)
{
	if (*a_len == 2)
		ft_printf("sa\n");
	else if (*a_len == 3)
		if_three(a, a_len, 0);
	else if (*a_len == 4)
	{
		while ((!check_list(a, a_len) && *a_len == 4) || *b_len > 0)
			if_four(a, b, a_len, b_len);
	}
	else if (*a_len == 5)
	{
		while ((!check_list(a, a_len) && *a_len == 5) || *b_len > 0)
			if_five(a, b, a_len, b_len);
	}
}

static void	radix_sort(int *a, int *b, int *a_len, int *b_len)
{
	int	i;

	i = 0;
	while (i < *a_len)
	{
		if ((a[0] & 1) == 0)
		{
			if (p(a, b, a_len, b_len))
				ft_printf("pb\n");
		}
		else if ((a[0] & 1) == 1)
		{
			if (r(a, a_len))
				ft_printf("ra\n");
			i++;
		}
	}
	while (*b_len > 0)
	{
		if (p(b, a, b_len, a_len))
			ft_printf("pa\n");
	}
}

static void	sort_list(int *a, int *b, int *a_len, int *b_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_list(a, a_len))
		return ;
	sort_arr(a, a_len);
	if (*a_len < 6)
	{
		sort_small(a, b, a_len, b_len);
		return ;
	}
	while (i++ < 31)
	{
		j = 0;
		radix_sort(a, b, a_len, b_len);
		while (j < *a_len)
		{
			a[j] = a[j] >> 1;
			j++;
		}
		if (check_list(a, a_len))
			return ;
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;

	a_len = 0;
	b_len = 0;
	while (a_len < argc)
	{
		if (!argv[a_len++][0])
			return (ft_printf("Error\n"), 0);
	}
	a_len = 0;
	if (argc > 1 && valid_char(argv) && valid_int(argv))
	{
		a = create_list(argv, &a_len);
		if (!int_is_dup(a, &a_len))
			return (free(a), ft_printf("Error\n"), 0);
		b = ft_calloc(sizeof(int), a_len);
		sort_list(a, b, &a_len, &b_len);
		free(a);
		free(b);
	}
	return (0);
}
