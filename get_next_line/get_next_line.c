/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:28:24 by miheider          #+#    #+#             */
/*   Updated: 2023/10/18 20:29:58 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_set_up(t_text **list, char *buf)
{
	int		i;
	int		j;
	t_text	*current;

	current = *list;
	j = 0;
	while (current)
	{
		if (current->next == NULL)
		{
			i = 0;
			while (current->line[i] && current->line[i] != '\n')
				i++;
			while (current->line[i] && current->line[i++])
				buf[j++] = (current)->line[i];
			buf[j] = '\0';
			break ;
		}
		free (current->line);
		current = current->next;
	}
	current->line = buf;
	*list = current;
//	ft_clean_up(list, current, buf);
}

char	*ft_get_line(t_text *list, int length)
{
	int		i;
	int		k;
	char	*next_line;

	next_line = (char *)ft_calloc((length + 2) * sizeof(char), 1);
	if (!next_line)
		return (NULL);
	k = 0;
	while (list)
	{
		i = 0;
		while (list->line[i] != '\0')
		{
			if (list->line[i] == '\n')
			{
				next_line[k] = '\n';
				next_line[k + 1] = '\0';
				return (next_line);
			}
			next_line[k++] = list->line[i++];
		}
		list = list->next;
	}
	return (next_line);
}

void	ft_store_line(char *buffer, t_text **list)
{
	t_text	*new;
	t_text	*current;

	current = NULL;
	new = (t_text *)ft_calloc(sizeof(t_text), 1);
	if (NULL == new)
		return ;
	if (buffer)
		new->line = ft_strdup(buffer);
	else
		new->line = NULL;
	new->next = NULL;
	if (NULL == *list)
	{
		*list = new;
	}
	else
	{
		current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

void	ft_read_the_file(int fd, t_text **list)
{
	unsigned int	length;
	char			*buffer;

	if (*list && ft_strchr((*list)->line, '\n'))
		return ;
	length = 1;
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1) * sizeof(char), 1);
	if (!buffer)
		return ;
	while (length > 0)
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if (length < 0)
		{
			ft_store_line(NULL, list);
			free (buffer);
			return ;
		}
		buffer[length] = '\0';
		ft_store_line(buffer, list);
		if (ft_strchr((const char *)buffer, '\n'))
			return ((void) free(buffer));
	}
	free (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_text	*list;
	char			*buf;
	int				length;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	ft_read_the_file(fd, &list);
	if (list == NULL)
	{
		return (NULL);
	}
	length = ft_str_len(&list);
	line = ft_get_line(list, length);
	if (line[0] == 0)
		return (NULL);
	buf = (char *)ft_calloc((BUFFER_SIZE + 1) * sizeof(char), 1);
	if (!buf)
		return (NULL);
	ft_set_up(&list, buf);
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int		fd0;
	char	*line;
	int		zeile;
	int		i;

	zeile = 15;
	fd0 = open("example8.txt", O_RDONLY);
	i = 0;
	while (i < zeile)
	{
		line = get_next_line(fd0);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd0);
}
