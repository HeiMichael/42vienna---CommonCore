/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_02_nulltest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:56:03 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 11:57:10 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strlen_tests.h"

int	null_test(void)
{
	if (ft_strlen(NULL) == 0)
		return (0);
	else
		return (-1);
}
