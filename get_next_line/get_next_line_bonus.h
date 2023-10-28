/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:29:50 by miheider          #+#    #+#             */
/*   Updated: 2023/10/22 15:39:58 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h> /*size_t, NULL*, malloc*/
# include <unistd.h> /*read*/

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

#endif
