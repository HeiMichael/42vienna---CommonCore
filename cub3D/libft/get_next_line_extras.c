/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_extras.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:22:57 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/09 11:59:49 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*buff_to_pot_error(char *buff, char *pot_str)
{
	free(buff);
	free(pot_str);
	pot_str = NULL;
	return (NULL);
}

int	read_bytes(int fd, int bytes, char *buff, char *pot_str)
{
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes == -1)
		buff_to_pot_error(buff, pot_str);
	return (bytes);
}

void	free_stuff(char *buff, char *pot_str)
{
	free(buff);
	free(pot_str);
	pot_str = NULL;
}

void	final_line_error(unsigned char *bool, char *pot_str)
{
	*bool = 1;
	free(pot_str);
}

void	new_pot_error(unsigned char *bool, char *new_pot, char *old_pot)
{
	*bool = 1;
	free(old_pot);
	free(new_pot);
}
