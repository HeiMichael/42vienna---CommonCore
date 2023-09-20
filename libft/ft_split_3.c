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

char	*word(char *s, char c, char **list, int number)
{
	char	*out;

	if (ft_strchr(s, c))
		out = (char *)malloc((ft_strchr(s, c) - s + 1) * sizeof(char));
	else
		out = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!out)
		return (free_all(list, number));
	ft_strlcpy(out, s, ft_strchr(s, c) - s + 1);
	return (out);
}

static int	wordcount(char *str, char c)
{
	int	count++;

	while (ft_strchr(s, c) == ft_strchr(ft_strchr(s, c) + 1, c) - 1)
			s = ft_strchr(ft_strchr(s, c) + 1, c);
		else
			count++;
	if (count == 0)
	{
		str = calloc(1, sizeof(char));
		if (!str)
			return (0);
	return (count + 1);
 }





char    **ft_split(char const *s, char c)
{
	char	**table;
	char	*str;
	int		i;
	int		j;

	if (!s || !*s)
		return (NULL);
	str = ft_strtrim(str, c);
	i = wordcount(str, c);
	if (i = 1)
		return (str);






	free(str);
	return (table);

}


/*
#include <stdio.h>
int	main(void)
{
	char	b[] = "--1-2--3---4----5-----42";
	char	c = '-';
	char	**result = (char **)ft_split(b, c);
	int		a;
	int		count;

	a = 0;
		while (result[2][a] != '\0')
		{
			printf("%c", result[0][a]);
			a++;
		}

	count = 0;
	while (result[count] != NULL) 
	{
		count++;
	}    
	freeall (result, (count - 1));
	return (0);
}*/