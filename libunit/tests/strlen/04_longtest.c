/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_04_longtest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:30:31 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 17:01:36 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strlen_tests.h"

int	long_test(void)
{
	if (ft_strlen("RfDLvNEAl RfDLvNEAl RfDLvNEAl RfDLvNEAl RfDLvNEAl R") == 51)
		return (0);
	else
		return (-1);
}
