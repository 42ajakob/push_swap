/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:40:39 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/16 00:09:56 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void	print_list(unsigned int *a, unsigned int *b, int *a_len, int *b_len)
//{
//	int	i;

//	i = 0;
//	while (i < *a_len && i < *b_len)
//	{
//		printf("%u : ", a[i]);
//		printf("%u\n", b[i]);
//		i++;
//	}
//	while (i < *a_len)
//	{
//		printf("%u : -\n", a[i]);
//		i++;
//	}
//	while (i < *b_len)
//	{
//		printf("- : %u\n", b[i]);
//		i++;
//	}
//	ft_printf("\n");
//}

static unsigned int	*create_list(char **s, int *a_len)
{
	unsigned int	*list;
	int				i;

	i = 0;
	while (s[*a_len + 1])
		*a_len = *a_len + 1;
	list = ft_calloc(sizeof(unsigned int), *a_len);
	if (!list)
	{
		ft_printf("Error\n");
		exit(0);
	}
	while (s[i + 1] && i < *a_len)
	{
		long_check_ft_atoui(s[i + 1], &list[i]);
		i++;
	}
	return (list);
}

//static void	sort_small(unsigned int *a, int *a_len)
//{
	
//}

static void	radix_sort(unsigned int *a, unsigned int *b, int *a_len, int *b_len)
{
	int	i;

	i = 0;
	while (i < *a_len)
	{
		if ((a[0] & 1) == 1)
		{
			if (p(a, b, a_len, b_len))
				ft_printf("pb\n");
		}
		else if ((a[0] & 1) == 0)
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

static void	sort_list(unsigned int *a, unsigned int *b, int *a_len, int *b_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_list(a, *a_len))
		return ;
	sort_arr(a, a_len);
	if (*a_len < 6)
	{
		// sort_small(a, a_len);
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
		if (check_list(a, *a_len))
			return ;
	}
}

int	main(int argc, char **argv)
{
	unsigned int	*a;
	unsigned int	*b;
	int				a_len;
	int				b_len;

	a_len = 0;
	b_len = 0;
	if (valid_list(argc, argv))
	{
		a = create_list(argv, &a_len);
		b = ft_calloc(sizeof(unsigned int), a_len);
		sort_list(a, b, &a_len, &b_len);
		free(a);
		free(b);
	}
	return (0);
}
