/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:29:50 by miheider          #+#    #+#             */
/*   Updated: 2023/10/10 13:10:09 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stddef.h>			/*size_t, NULL*/
# include <stdlib.h>			/*size_t, NULL*, malloc*/
# include <fcntl.h>			
# include <unistd.h>			/*read*/

typedef struct s_text
{
	char			*line;
	struct s_text	*next;
}	t_text;

void	ft_clean_up(t_text **list, t_text *current, char *buffer);
void	ft_set_up(t_text **list);
int		ft_str_len(t_text **list);
char	*ft_get_line(t_text *list);
void	ft_store_line(char *buffer, t_text **list);
void	ft_read_the_file(int fd, t_text **list);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);

#endif
