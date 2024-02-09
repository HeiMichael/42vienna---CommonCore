/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_01_basictest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:53:18 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 16:29:58 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strlen_tests.h"

int	basic_test(void)
{
	if (ft_strlen("Hello, World!") == 13)
		return (0);
	else
		return (-1);
}
