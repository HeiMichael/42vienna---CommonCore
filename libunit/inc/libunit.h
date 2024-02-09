/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:57:54 by gwalchsh          #+#    #+#             */
/*   Updated: 2024/01/21 17:17:20 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# define TIMEOUT_DURATION 10
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h> //allowed?

typedef struct s_test
{
	char			*title;
	int				(*tester)(void);
	int				expected;
	int				result;
	struct s_test	*next;
}				t_test;
int		start(void);
void	load_test(t_test **test, char *name, int (*f)(void));
int		run_test(t_test *test);
#endif
