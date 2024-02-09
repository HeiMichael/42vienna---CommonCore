/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:44:07 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 21:36:20 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "routine_tests.h"

int	routine_launcher(void)
{
	t_test	*lst_test;

	lst_test = NULL;
	load_test(&lst_test, "ft_strlen: OK - Test", &ok_test);
	load_test(&lst_test, "ft_strlen: KO - Test", &ko_test);
	load_test(&lst_test, "ft_atoi: SIGSEV - Test", &sigsev_test);
	load_test(&lst_test, "ft_strlen: BUS - Test", &bus_test);
	return (run_test(lst_test));
}
