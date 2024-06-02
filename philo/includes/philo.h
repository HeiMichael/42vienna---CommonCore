/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:03:11 by miheider          #+#    #+#             */
/*   Updated: 2024/06/01 14:14:17 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>   /*pthread*/
# include <sys/time.h>  /*gettimeofday*/
# include <stdlib.h>    /*malloc, free, write*/
# include <string.h>    /*memset*/
# include <unistd.h>    /*usleep*/

typedef struct s_phil	t_phil;

typedef struct s_rules
{
	long long		time_start;
	size_t			num_phil;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	int				num_meal;
	int				dead;
	int				finished_meal;
	pthread_t		is_dead;
	pthread_mutex_t	deads;
	pthread_mutex_t	eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	timestamp;
	struct s_phil	*philos;
}	t_rules;

typedef struct s_phil
{
	pthread_t			thread;
	int					id;
	long				time_death;
	int					count_meal;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		*right_f;
	t_rules				*game;
}	t_phil;

//main.c
int		main(int argc, char **argv);

//check_input.c
int		skip_whitespace_and_sign(char *str, int *j);
int		check_max(char *argv);
void	counter(int *j, int *counter);
int		check_substring(char *str);
int		check_input(char **argv);
//error.c
void	philo_error(int ret);
void	mutex_error(int ret, int status, int i, t_rules *game);
int		clean_up(t_rules *game);
//init.c
void	init_philos(t_rules *game);
int		alocate_memory(t_rules *game);
int		init_game(t_rules *game);
int		init_struct(t_rules *game);
int		insert_arg(t_rules *game, int argc, char **argv);
//main.c
int		main(int argc, char **argv);
//monoitor.c
int		check_for_dead(t_phil *philos);
void	print_message(t_phil *philos, int id, char *message);
void	*is_dead_cont(t_rules *game, int i);
void	*is_dead(void *arg);
//utils.c
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_philo_atoi(char *input);
//utils_two.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	my_usleep(unsigned int usec);
//time.c
long	timestamp(t_rules *game);
long	current_time(t_rules *game);
void	set_dead(t_phil *philos);
//routine.c
void	take_forks(t_phil *philos);
void	eating(t_phil *philos);
void	thinking(t_phil *philos);
void	sleeping(t_phil *philos);
void	*routine(void *arg);
//threads.c
int		init_and_create(t_rules *game, pthread_t *check);
int		create_philo(t_rules *game);
int		join_philo(t_rules *game);
int		create_threads(t_rules *game);

#endif
