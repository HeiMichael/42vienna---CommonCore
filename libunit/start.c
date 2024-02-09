/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:54:35 by gwalchsh          #+#    #+#             */
/*   Updated: 2024/01/21 23:35:13 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libunit.h"
#include "tests/strlen/strlen_tests.h"
#include "tests/strncmp/strncmp_tests.h"
#include "tests/routine/routine_tests.h"

//make && cc main.c libunit.a inc/libft/libft.a -L. && ./a.out

int	start(void)
{
	int	strlentests;
	int	strncmptests;
	int	routine;
	int	exit_code;

	strlentests = 0;
	strncmptests = 0;
	routine = 0;
	strlentests = strlen_launcher();
	strncmptests = strncmp_launcher();
	routine = routine_launcher();
	if (strlentests == 12 && strncmptests == 3 && routine == 4)
		exit_code = 0;
	else
		exit_code = -1;
	ft_printf("--------\nft_strlen tests: %d of 12 successful.\n", strlentests);
	ft_printf("ft_strncmp tests: %d of 3 successful.\n", strncmptests);
	ft_printf("ft_routine tests: %d of 4 successful. \n", routine);
	return (exit_code);
}
