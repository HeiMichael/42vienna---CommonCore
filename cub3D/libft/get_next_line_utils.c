/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:21:17 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/01 19:16:44 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*vs_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

int	vs_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*vs_strjoint(char *left_str, char *buff, unsigned char *bool)
{
	char	*str;

	if (!left_str)
	{
		left_str = (char *)ft_calloc(1, sizeof(char));
		if (!left_str)
			return (change_bool(bool));
		left_str[0] = '\0';
	}
	if (!buff)
	{
		*bool = 1;
		free(left_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * ((vs_strlen(left_str) + vs_strlen(buff)) + 1));
	if (!str)
		return (change_bool(bool));
	str = copy_to_string(left_str, str, buff);
	return (str);
}

char	*copy_to_string(char *left_str, char *str, char *buff)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[vs_strlen(left_str) + vs_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*change_bool(unsigned char *bool)
{
	*bool = 1;
	return (NULL);
}
