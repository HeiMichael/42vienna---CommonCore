/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:28:59 by mhuszar           #+#    #+#             */
/*   Updated: 2023/12/10 22:01:48 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

//grid limits
#define X_MIN 7
#define X_CUTOFF 35
#define X_MAX 2147483647
#define Y_MIN 6
#define Y_CUTOFF 45
#define Y_MAX 2147483647

//ft_printf
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
int		ft_printf(const char *tipus, ...);
void	ft_putchar(char c);
int		print_i(int i);
int		print_x(unsigned int x);
int		print_xup(unsigned int x);
int		print_c(char c);
int		print_s(char *str);
int		print_p(void *ptr);
int		print_u(unsigned int u);

//get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
typedef struct s_text
{
	char			*line;
	struct s_text	*next;
}					t_text;
void	ft_clean_up(t_text **list, t_text *current, t_text	*save);
void	ft_set_up(t_text **list, char *buf);
int		ft_str_len(t_text **list);
char	*ft_get_line(t_text *list, int length);
int		ft_store_line(char *buffer, t_text **list, t_text *current);
void	ft_read_the_file(int fd, t_text **list);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

//connect4_functions
# include <time.h>
void	ft_putstr_fd(char *s, int fd);
int     error_msg(char **grid, int y);
char    **make_grid(int x, int y);
long int ft_atoi(const char *str);
int     display(char **grid, int y, int x);
int		check_for_winning(char **game, int row, int col);
int 	destroyer(char ***grid, int x, int y);
int 	modify_grid(char ***ancestor, int x, int y, int input_col, int color);
int 	check_for_two_yellow(char **game, int row, int col, int *top);
int 	check_for_two_red(char **game, int row, int col, int *top);
int		*top_list(char **grid, int x, int y);
int 	check_for_three(char **game, int row, int col, int *top);
int 	check_for_red(char **game, int row, int col, int *top);
int 	check_for_yellow(char **game, int row, int col, int *top);

#endif
