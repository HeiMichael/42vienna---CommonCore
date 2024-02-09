/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:44:07 by miheider          #+#    #+#             */
/*   Updated: 2024/01/21 21:37:00 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libunit.h"
#include "strlen_tests.h"

int	strlen_launcher(void)
{
	t_test	*lst_test;

	lst_test = NULL;
	load_test(&lst_test, "ft_strlen: Basic test", &basic_test);
	load_test(&lst_test, "ft_strlen: NULL test", &null_test);
	load_test(&lst_test, "ft_strlen: Special string test", &special_test);
	load_test(&lst_test, "ft_strlen: Bigger string test", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test05", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test06", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test07", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test08", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test09", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test10", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test11", &long_test);
	load_test(&lst_test, "ft_strlen: strlen_test12", &long_test);
	return (run_test(lst_test));
}
