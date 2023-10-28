/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:28:24 by miheider          #+#    #+#             */
/*   Updated: 2023/10/22 15:18:56 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		current = current->next;
	}
	free(current->line);
	current->line = ft_strdup(buf);
	ft_clean_up(list, current, NULL);
	free(buf);
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
		while (list->line && list->line[i] != '\0')
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

int	ft_store_line(char *buffer, t_text **list, t_text *current)
{
	t_text	*new;

	current = NULL;
	new = (t_text *)ft_calloc(sizeof(t_text), 1);
	if (NULL == new)
		return (1);
	if (buffer)
	{
		new->line = ft_strdup(buffer);
		if (!new->line)
			return (free(new), free(buffer), 1);
	}
	else
		new->line = NULL;
	new->next = NULL;
	if (NULL == *list)
		*list = new;
	else
	{
		current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (0);
}

void	ft_read_the_file(int fd, t_text **list)
{
	int		length;
	char	*buffer;

	if (*list && ft_strchr((*list)->line, '\n'))
		return ;
	length = 1;
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1) * sizeof(char), 1);
	if (!buffer)
		return ;
	while (length > 0 && !ft_strchr((const char *)buffer, '\n'))
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if (length < 0)
			return (ft_clean_up(list, NULL, NULL), (void)free(buffer));
		buffer[length] = '\0';
		if (length == 0)
			return ((void)free(buffer));
		if (ft_store_line(buffer, list, NULL))
			return ((void)free(buffer));
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_text	*list[1024];
	char			*buf;
	int				length;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (0);
	ft_read_the_file(fd, &list[fd]);
	if (list[fd] == NULL || !list[fd]->line)
		return (NULL);
	length = ft_str_len(&list[fd]);
	line = ft_get_line(list[fd], length);
	if (!line)
		return (ft_clean_up(&list[fd], NULL, NULL), NULL);
	if (line[0] == 0)
	{
		free(line);
		return (ft_clean_up(&list[fd], NULL, NULL), NULL);
	}
	buf = (char *)ft_calloc((BUFFER_SIZE + 1) * sizeof(char), 1);
	if (!buf)
		return (ft_clean_up(&list[fd], NULL, NULL), NULL);
	ft_set_up(&list[fd], buf);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *a;
	int fd = open("read_error.txt", O_RDONLY);

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
		free(a);
	}
	return 0;
}

#include <stdio.h>

 int	main(void)
 {
 	int		fd0;
 	char	*line;
 	int		zeile;
 	int		i;

 	zeile = 29;
 	fd0 = open("example0.txt", O_RDONLY);
 	i = 0;
 	while (i < zeile)
 	{
 		line = get_next_line(fd0);
 		printf("%s", line);
 		free(line);
 		line = NULL;
 		i++;
 	}
 			close(fd0);
 }*/
