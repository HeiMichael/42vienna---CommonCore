/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:29:34 by miheider          #+#    #+#             */
/*   Updated: 2023/10/22 13:43:49 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_str_len(t_text **list)
{
	int		i;
	int		length;
	t_text	*current;

	current = *list;
	length = 0;
	while (current)
	{
		i = 0;
		while (current->line && current->line[i])
		{
			if (current->line[i] == '\n')
			{
				i++;
				return (length);
			}
			i++;
			length++;
		}
		current = (current)->next;
	}
	return (length);
}

void	ft_clean_up(t_text **list, t_text *current, t_text *save)
{
	if (NULL == *list)
		return ;
	while ((*list)->next)
	{
		save = (*list)->next;
		if ((*list)->line)
			free((*list)->line);
		free(*list);
		*list = save;
	}
	if ((*list)->line && (*list)->line[0] != '\0')
	{
		if (current == NULL)
			(free((*list)->line), free(*list));
		*list = current;
	}
	else
	{
		if ((*list)->line)
			free((*list)->line);
		if (*list)
			free ((*list));
		*list = (NULL);
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		a;

	if (!s)
		return (NULL);
	a = 0;
	while (s[a])
	{
		if (s[a] == (char)c)
		{
			return ((char *)&s[a]);
		}
		a++;
	}
	if ((char)c == '\0')
		return ((char *)&s[a]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		a;
	char	*dupl;

	a = 0;
	while (s[a])
		a++;
	dupl = malloc(sizeof(char) * a + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < a)
	{
		dupl[i] = s[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*a;
	size_t			x;

	a = malloc(nmemb * size);
	if (a == 0)
		return (NULL);
	else
	{
		x = 0;
		while (x < (nmemb * size))
		{
			a[x] = 0;
			x++;
		}
		return (a);
	}
}
