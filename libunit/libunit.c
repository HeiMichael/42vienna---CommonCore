/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:56:47 by gwalchsh          #+#    #+#             */
/*   Updated: 2024/01/21 23:39:15 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libunit.h"

void	load_test(t_test **test, char *name, int (*f)(void))
{
	t_test	*new;

	new = malloc(sizeof(t_test));
	if (!new)
	{
		perror("malloc");
		exit(errno);
	}
	new->title = ft_strdup(name);
	new->tester = f;
	new->next = *test;
	new->expected = 0;
	*test = new;
}

static int	analyze_results(t_test *test)
{
	int		status;
	int		exit_code;
	int		passed;

	passed = 1;
	wait(&status);
	if (WIFSIGNALED(status))
	{
		passed = 0;
		exit_code = WTERMSIG(status);
		if (exit_code == SIGSEGV)
			ft_printf("%s: \x1b[1;35m[SIGSEGV ERROR]\x1b[0m\n", test->title);
		else if (exit_code == SIGBUS)
			ft_printf("%s: \x1b[1;33m[SIGBUS ERROR]\x1b[0m\n", test->title);
		else if (exit_code == SIGALRM)
			ft_printf("%s: \x1b[1;36[TIMEOUT]\x1b[0m\n", test->title);
		return (-1);
	}
	exit_code = WEXITSTATUS(status);
	if (exit_code == test->expected && passed == 1)
		return (ft_printf("%s: \x1b[1;32m[OK]\x1b[0m\n", test->title), 0);
	else if (exit_code != test->expected && passed == 1)
		return (ft_printf("%s: \x1b[1;31m[KO]\x1b[0m\n", test->title), -1);
	return (exit_code);
}

static int	run_single_test(t_test *test)
{
	pid_t	pid;
	int		result;

	pid = fork();
	result = -99;
	if (pid == -1)
	{
		perror("fork");
		exit(errno);
	}
	if (pid == 0)
	{
		alarm(TIMEOUT_DURATION);
		exit((test)->tester());
	}
	else
		result = analyze_results(test);
	return (result);
}

int	run_test(t_test *test)
{
	int	success;

	success = 0;
	while (test)
	{
		if (!run_single_test(test))
			success++;
		test = test->next;
	}
	return (success);
}
