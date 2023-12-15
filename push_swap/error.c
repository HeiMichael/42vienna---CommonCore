/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:12:20 by miheider          #+#    #+#             */
/*   Updated: 2023/12/14 21:50:52 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	error_message(int error)
{
	if (error == 2)
		ft_printf("Error: Invalid input. No duplicates allowed!\n");
	if (error == 3)
		ft_printf("Error: Invalid input. Input out of range!\n");
	if (error == 4)
		ft_printf("Error: Invalid input. Space only is not accepted!\n");
	if (error == 5)
		ft_printf("Error: Invalid input. Sign only is not accepted!\n");
	if (error == 6)
		ft_printf("Input is already sorted. No action needed!\n");
	if (error == 7)
		ft_printf("Error: Invalid input.\n");
	exit (1);
}
