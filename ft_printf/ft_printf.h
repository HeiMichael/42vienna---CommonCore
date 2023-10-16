/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:08:10 by miheider          #+#    #+#             */
/*   Updated: 2023/09/27 13:14:27 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_dec_hexa(unsigned int number, char c);
int	ft_integer(int nb);
int	ft_percent(void);
int	ft_character(int character);
int	ft_string(const char *string);
int	ft_pointer(void *number);
int	ft_printf(const char *format, ...);

#endif
