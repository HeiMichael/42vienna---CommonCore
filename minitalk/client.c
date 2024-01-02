/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:49:26 by miheider          #+#    #+#             */
/*   Updated: 2024/01/02 17:49:31 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

volatile sig_atomic_t	g_handshake = 1;

void	receive_handshake(int signal)
{
	if (signal == SIGUSR2)
		g_handshake = 1;
	if (signal == SIGUSR1)
		ft_printf("\nMessage sent successfully!\n\n");
}

void	send_char(int pid, unsigned char letter)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		while (g_handshake != 1)
			;
		bit = (letter >> (7 - i)) & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		g_handshake = 0;
		if (sleep(5) == 0)
			exit (1);
	}
}

void	checks(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		ft_printf("Error: Invalid input. Exactly two parameters needed!");
		exit (EXIT_FAILURE);
	}
	if (argv[1][0] == '\0')
	{
		ft_printf("Error: Invalid input. Please enter message.");
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (argv[0][i])
	{
		if (argv[0][i] < 48 || argv[0][i] > 57)
		{
			ft_printf("Error: Invalid PID. Only numbers allowed!");
			exit (EXIT_FAILURE);
		}
		else
			i++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	struct sigaction	client;

	client.sa_handler = receive_handshake;
	client.sa_flags = 0;
	sigemptyset(&client.sa_mask);
	sigaction(SIGUSR2, &client, NULL);
	sigaction(SIGUSR1, &client, NULL);
	checks(argc - 1, argv + 1);
	pid = ft_atoi(argv[1]);
	i = 0;
	usleep(10000);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (EXIT_SUCCESS);
}
