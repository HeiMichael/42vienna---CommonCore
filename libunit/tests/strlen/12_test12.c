/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_12_test12.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:30:31 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 17:21:13 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strlen_tests.h"

int	strlen_test12(void)
{
	if (ft_strlen("End") == 3)
		return (0);
	else
		return (-1);
}
