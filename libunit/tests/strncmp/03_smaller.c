/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_03_smaller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:57:02 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 15:06:33 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strncmp_tests.h"

int	smaller(void)
{
	int	result;

	result = ft_strncmp("Evaluation", "Nice", 6);
	if (result < 0)
		return (0);
	else
		return (-1);
}
