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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>


static char	freeall(char **table, int counter)
{
	while (counter >= 0)
	{
		free (table[counter]);
		counter--;
	}
	free (table);
	return (0);
}

static char	*nextround(char *str, char c, int *i, int *j)
{
	while (*str == c)
		str++;
	*i = 0;
	*j += 1;
	return (str);
}

static char	**setarray(char *str, char **table, char c, int i)
{
	int		k;
	int		j;

	j = 0;
	i = 0;
	while (*str != '\0')
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		table[j] = malloc(sizeof(char) * (i + 1));
		if (table[j] == NULL)
		{
			freeall(table, j);
			return (0);
		}
		k = 0;
		while (k < i)
		{
			table[j][k] = str[k];
			k++;
		}
		table[j][k] = '\0';
		str = nextround(&str[i], c, &i, &j);
	}
	table[j] = (char *) NULL;
	return (table);
}

static int	word_count(char *str, char c)
{
	int		i;
	int count;

	i = (strlen(str) - 1);
	while (str[i] == c)
		str[i--] = '\0';
	i = 0;
	    {
        count = 0;
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] != c)
            {
                count++;
                while (str[i] != '\0' && str[i] != c)
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        return (count);
    }
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	char	*str;
	int		i;
	int		j;

	if (c == '\0')
	{
		table = (char **)malloc(sizeof(char *));
		if(!table)
			return(NULL);
		table[0] = NULL;
		return(table);
	}
    str = ft_strdup(s);  
	if ((!s || !*s) && c == '\0')
		return (NULL);
	str = ft_strdup(s);
	i = 0;
	while (str[i] == c)
		i++;
	str = &str[i];
	j = word_count(str, c);
	table = (char **)malloc(sizeof(char *) * (j + 1));
	if (!table)
	{
		free(table);
		return (NULL);
	}
	j = 0;
	table = (char **)setarray(str, table, c, i);
	return (table);
}

/*
int	main(void)
{
	char	b[] = "\0aa\0bbb";
	char	c = '\0';
	char	**result = (char **)ft_split(b, c);
	int		a;
	int		count;

	a = 0;
		while (result[0][a] != '\0')
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
