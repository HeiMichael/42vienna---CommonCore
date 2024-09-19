/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:16:26 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:37:09 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_row_length(char **map, int row_index)
{
	return (ft_strlen(map[row_index]));
}

void	*allocate_memory(size_t type, size_t nbr_elements, t_cub cubed)
{
	void	*mem;

	mem = ft_calloc(nbr_elements, type);
	if (NULL == mem)
		free_exit(&cubed, "Error\nFailed to allocate memory\n");
	return (mem);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saved_str;
	char		*token;

	if (str != NULL)
		saved_str = str;
	if (saved_str == NULL || *saved_str == '\0')
		return (NULL);
	while (*saved_str && ft_strchr(delim, *saved_str))
		saved_str++;
	if (*saved_str == '\0')
		return (NULL);
	token = saved_str;
	while (*saved_str && !ft_strchr(delim, *saved_str))
		saved_str++;
	if (*saved_str)
	{
		*saved_str = '\0';
		saved_str++;
	}
	return (token);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
