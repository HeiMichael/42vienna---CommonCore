/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:13:26 by miheider          #+#    #+#             */
/*   Updated: 2023/12/29 23:05:15 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef MAX_PID
#  define MAX_PID				4194304
# endif

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>		//write, sleep, usleep
# include <stdlib.h>		//EXIT

#endif
