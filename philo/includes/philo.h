/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:03:11 by miheider          #+#    #+#             */
/*   Updated: 2024/05/28 17:57:44 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>   /*pthread*/
# include <sys/time.h>  /*gettimeofday*/
# include <stdio.h>     /*printf*/
# include <stdlib.h>    /*malloc, free, write*/
# include <string.h>    /*memset, write*/
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

//check_input
int		check_input(char **argv);
void	counter(int *j, int *counter);
int		check_max(char *argv);

//init.c
int		insert_arg(t_rules *game, int argc, char **argv);
int		init_struct(t_rules *game);
void	init_philos(t_rules *game);
int		alocate_memory(t_rules *game);
int		init_game(t_rules *game);

//error
void	philo_error(int ret);
void	philo_free(int ret);

//utils.c
int		ft_strlen(const char *str);
long	timestamp(t_rules *game);
int		clean_up(t_rules *game);
int		create_threads(t_rules *game);
void	*is_dead(void *arg);
void	philo_error(int ret);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_philo_atoi(char *input);

#endif
