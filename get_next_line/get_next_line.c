/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:28:24 by miheider          #+#    #+#             */
/*   Updated: 2023/10/13 19:18:41 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_set_up(t_text **list)
{
	char	*buf;
	int		i;
	int		j;
	t_text	*current;

	current = *list;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return ;
	j = 0;
	while (current)
	{
		if (current->next == NULL)
		{
			i = 0;
			while (current->line[i] && current->line[i] != '\n')
				i++;
			while (current->line[i++])
				buf[j++] = (current)->line[i];
			buf[j] = '\0';
			break ;
		}
		free (current->line);
		current = current->next;
	}
	if (!buf)
		return ;
	current->line = buf;
	*list = current;
//	ft_clean_up(list, current, buf);
}

char	*ft_get_line(t_text *list)
{
	int		i;
	int		k;
	char	*next_line;
	int		length;

	length = ft_str_len(&list);
	next_line = (char *)malloc((length + 1) * sizeof(char));
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
	t_text	*here;

	here = NULL;
	new = (t_text *)malloc(sizeof(t_text));
	if (NULL == new)
		return ;
	new->line = ft_strdup(buffer);
	new->next = NULL;
	if (*list == NULL)
	{
		*list = new;
//		free (new);
	}
	else
	{
		here = *list;
		while (here->next != NULL)
			here = here->next;
		here->next = new;
//		free (new);
	}
}

void	ft_read_the_file(int fd, t_text **list)
{
	unsigned int		length;
	char				*buffer;

	if (!(*list));
	else if (ft_strchr((*list)->line, '\n'))
		return ;
	while (1)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		length = read(fd, buffer, BUFFER_SIZE);
		if (length <= 0)
		{
			free (buffer);
			return ;
		}
		buffer[length] = '\0';
		ft_store_line(buffer, list);
		if (ft_strchr((const char *)buffer, '\n'))
			return ((void)free (buffer));
		free (buffer);
	}
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_text	*list;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	ft_read_the_file(fd, &list);
	if (NULL == list)
		return (NULL);
	line = ft_get_line(list);
	if (line[0] == '\0')
		return (NULL);
	ft_set_up(&list);
	return (line);
}

# include<stdio.h>
int	main(void)
{
	int		fd0;
//	int		fd1;
//	int		fd2;
//	int		fd3;
//	int		fd4;
//	int		fd5;
//	int		fd6;
//	int		fd7;
//	int		fd8;
	char	*line;
	int		zeile;
	int		i;
	
	zeile = 29;
	fd0 = open("example2.txt", O_RDONLY);	
	i = 0;
	while (i < zeile)
	{
		line = get_next_line(fd0);
		printf("{%s}", line);
		free(line);
		i++;
	}
	close(fd0);
}
