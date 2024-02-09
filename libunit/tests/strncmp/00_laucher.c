/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_laucher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:49:55 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 21:37:17 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strncmp_tests.h"

int	strncmp_launcher(void)
{
	t_test	*lst_test;

	lst_test = NULL;
	load_test(&lst_test, "ft_strncmp: same", &basic);
	load_test(&lst_test, "ft_strncmp: greater0", &greater);
	load_test(&lst_test, "ft_strncmp: smaller0", &smaller);
	return (run_test(lst_test));
}
