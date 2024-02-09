/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_02_greater.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:56:45 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 15:06:09 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strncmp_tests.h"

int	greater(void)
{
	int	result;

	result = ft_strncmp("Nice", "Evaluation", 6);
	if (result > 0)
		return (0);
	else
		return (-1);
}
