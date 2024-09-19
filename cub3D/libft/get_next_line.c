/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:37:04 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 17:01:59 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd, unsigned char *bool, char **pot)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pot[fd] = vs_buff_to_pot(fd, pot[fd], bool);
	if (!pot[fd])
		return (NULL);
	line = vs_check_line(pot[fd], bool);
	pot[fd] = vs_fresh_pot(pot[fd], bool);
	return (line);
}

char	*vs_buff_to_pot(int fd, char *pot_str, unsigned char *bool)
{
	char	*buff;
	int		bytes;

	buff = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buff)
	{
		*bool = 1;
		return (NULL);
	}
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read_bytes(fd, bytes, buff, pot_str);
		buff[bytes] = '\0';
		pot_str = vs_strjoint(pot_str, buff, bool);
		if (!pot_str)
		{
			free_stuff(buff, pot_str);
			return (NULL);
		}
		if (vs_strchr(pot_str, '\n'))
			break ;
	}
	free(buff);
	return (pot_str);
}

char	*vs_check_line(char *pot_str, unsigned char *bool)
{
	int		i;
	char	*final_line;

	i = 0;
	if (!pot_str[i])
		return (NULL);
	final_line = (char *)malloc(sizeof(char) * (vs_strlen(pot_str) + 2));
	if (!final_line)
	{
		final_line_error(bool, pot_str);
		return (NULL);
	}
	while (pot_str[i] && pot_str[i] != '\n')
	{
		final_line[i] = pot_str[i];
		i++;
	}
	if (pot_str[i] == '\n')
	{
		final_line[i] = pot_str[i];
		i++;
	}
	final_line[i] = '\0';
	return (final_line);
}

char	*vs_fresh_pot(char *old_pot, unsigned char *bool)
{
	int		i;
	int		j;
	char	*new_pot;

	i = 0;
	while (old_pot[i] && old_pot[i] != '\n')
		i++;
	if (!old_pot[i])
	{
		free(old_pot);
		return (NULL);
	}
	new_pot = ft_calloc(1, vs_strlen(old_pot) - i + 1);
	if (!new_pot)
	{
		new_pot_error(bool, new_pot, old_pot);
		return (NULL);
	}
	i++;
	j = 0;
	while (old_pot[i])
		new_pot[j++] = old_pot[i++];
	new_pot[j] = '\0';
	free(old_pot);
	return (new_pot);
}
