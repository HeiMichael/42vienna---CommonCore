/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:34:50 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 17:32:47 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*begin(char *t1, char *set)
{
	int		i;
	int		j;
	int		set_len;

	set_len = ft_strlen(set);
	i = 0;
	while (t1[i])
	{
		j = 0;
		while (set[j] && t1[i] != set[j])
		{
			if (t1[i] == set[j])
				i++;
			j++;
		}
		if (j == set_len && t1[i] != set[set_len -1])
			return (t1 + i);
		i++;
	}
	return (0);
}

static int	end(char *t1, char *set, int t1_len)
{
	int		i;
	int		j;
	int		set_len;

	set_len = ft_strlen(set);
	i = t1_len - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] && t1[i] != set[j])
		{
			if (t1[i] == set[j])
				i--;
			j++;
		}
		if (j == set_len && t1[i] != set[set_len - 1])
			return (t1_len - i - 1);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t1;
	char	*trim;
	int		i;
	int		t1_len;
	char	*res;

	t1 = (char *)s1;
	trim = (char *)set;
	t1 = begin(t1, trim);
	t1_len = ft_strlen(t1);
	i = end(t1, trim, t1_len);
	res = malloc(sizeof(char *) * (i + 1));
	ft_strlcpy(res, t1, i);
	res[i + 1] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main(void)
{
    char s1[] = "caabc.www.sdeaaaacbba";
    char set[] = "abc";

    printf("%s", ft_strtrim(s1, set));
    return 0;
}*/