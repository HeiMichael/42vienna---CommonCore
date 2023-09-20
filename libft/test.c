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

int	main(void)
{
	char	**result = ft_split("tripouille", 0);
	int i = 0;
    while (i < 3)
		printf("{%s} ", result[i++]);
	// while (result[i])
		// printf("{%s} ", result[i++]);
	printf("\n");
	i = 0;
	while (result[i])
		free(result[i++]);
    free(result);
	return (0);
}