/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moded_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:57 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/17 15:07:26 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countsubstrings(char const *s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if ((s[i - 1] == ' ' || (s[i - 1] >= 9 && s[i - 1] <= 13))
			&& (s[i] != ' ' && !(s[i] >= 9 && s[i] <= 13)))
			j++;
		i++;
	}
	if (s[0] != ' ' && !(s[0] >= 9 && s[0] <= 13))
		j++;
	return (j);
}

static int	substrlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ' && !(s[i] >= 9 && s[i] <= 13))
		i++;
	return (i);
}

static char	*copysubstr(char const *src, int i)
{
	char	*string;

	string = ft_calloc((i + 1), sizeof(char));
	string[i] = '\0';
	if (!string)
		return (NULL);
	ft_strlcpy(string, src, i + 1);
	return (string);
}

static void	*freeptr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	return (NULL);
}

char	**moded_split(char const *s)
{
	char	**strings;
	int		count;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	count = countsubstrings(s);
	strings = ft_calloc((count + 1), sizeof(char *));
	if (strings == NULL)
		return (NULL);
	while (++i < count && s[j])
	{
		while (s[j] == ' ' || (s[j] >= 9 && s[j] <= 13))
			j++;
		len = substrlen(&s[j]);
		strings[i] = copysubstr(&s[j], len);
		if (!strings[i])
			return (freeptr(strings));
		j += len;
	}
	strings[count] = NULL;
	return (strings);
}
