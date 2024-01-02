/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:49:41 by miheider          #+#    #+#             */
/*   Updated: 2024/01/02 00:55:10 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(int x)
{
	if (x == 1)
		ft_printf("Error: Invalid bit sequence!");
	if (x == 2)
		ft_printf("Error: Memory allocation failed!");
	exit(EXIT_FAILURE);
}

void	print_result(char **result, char *input, siginfo_t *info)
{
	char	*temp;

	temp = ft_strjoin(result[info->si_pid], input);
	if (!temp)
		exit(2);
	free(result[info->si_pid]);
	result[info->si_pid] = temp;
	if (*input == '\0')
	{
		if (result[info->si_pid])
		{
			ft_printf("%s\n", result[info->si_pid]);
			free(result[info->si_pid]);
			kill(info->si_pid, SIGUSR1);
		}
	}
}

void	print_input(int signal, siginfo_t *info, void *ucontext)
{
	static int		i;
	static char		input[MAX_PID];
	static char		*result[MAX_PID];

	(void)ucontext;
	if (signal == SIGUSR2)
		input[info->si_pid] |= (1 << (7 - i));
	else if (signal != SIGUSR1)
		exit(1);
	i++;
	if (i == 8)
	{
		if (!result[info->si_pid])
		{
			result[info->si_pid] = (char *)malloc(sizeof(char));
			if (!result[info->si_pid])
				exit(2);
			result[info->si_pid][0] = '\0';
		}
		print_result(result, &input[info->si_pid], info);
		i = 0;
		ft_memset(input, 0, MAX_PID);
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	server;

	ft_printf("PID_server: %d\n", getpid());
	server.sa_flags = SA_SIGINFO;
	server.sa_sigaction = &print_input;
	sigemptyset(&server.sa_mask);
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
