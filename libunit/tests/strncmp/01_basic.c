/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_01_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:56:33 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 15:01:08 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strncmp_tests.h"

int	basic(void)
{
	int	result;

	result = ft_strncmp("Hallo!", "Hallo!", 6);
	if (result == 0)
		return (0);
	else
		return (-1);
}
