/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:22:48 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:42:11 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **table, int counter)
{
	while (counter >= 0)
	{
		free(table[counter]);
		counter--;
	}
	free(table);
}

static char	**setarray(char const *str, char **table, char c)
{
	size_t	i;
	int		j;

	j = 0;
	while (*str != '\0')
	{
		i = 0;
		while (str[i] != c && str[i] != '\0')
			i++;
		table[j] = ft_substr(str, 0, i);
		if (table[j] == NULL)
			return (freeall(table, (j - 1)), NULL);
		str += i;
		while (*str == c && c != '\0')
			str++;
		j++;
	}
	table[j] = NULL;
	return (table);
}

static int	word_count(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		words;

	if (!s)
		return (NULL);
	while (*s == c && c)
		s++;
	words = word_count(s, c);
	table = (char **)malloc(sizeof(char *) * (words + 1));
	if (!table)
		return (NULL);
	if (words == 0)
	{
		table[0] = NULL;
		return (table);
	}
	table = setarray(s, table, c);
	return (table);
}
