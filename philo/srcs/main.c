/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:33:25 by miheider          #+#    #+#             */
/*   Updated: 2024/05/30 15:39:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_rules	game;

	if (argc < 5 || argc > 6)
		return (philo_error(-1), 1);
	ret = check_input(argv + 1);
	if (ret <= -1 && ret >= -3)
		return (philo_error(ret), 1);
	if (insert_arg(&game, argc - 1, argv) == -1)
		return (philo_error(-4), 1);
	if (init_struct(&game) != 0)
		return (1);
	if (create_threads(&game))
		return (1);
	clean_up(&game);
	return (0);
}
