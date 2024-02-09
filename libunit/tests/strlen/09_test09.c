/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_09_test09.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:30:31 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 17:20:55 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strlen_tests.h"

int	strlen_test09(void)
{
	if (ft_strlen("What the \0 heck!") == 9)
		return (0);
	else
		return (-1);
}
