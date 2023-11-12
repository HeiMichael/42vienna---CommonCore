/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:42:58 by miheider          #+#    #+#             */
/*   Updated: 2023/10/15 21:21:15 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# define NO_ERROR 0
# define READ_ERROR 1
# define MALLOC_ERROR 2

# define FT_GNL_READ_BUFFER_SIZE 1024
# define FT_GNL_ACCUM_INIT_SIZE 256

# define INIT_BUFF_SZ 64000
# define REALLOC_PERCENT 70
# define EXPAND_CONST 4
// just random prime number
# define HASH_CONSTANT 31

typedef struct s_gnl_buf
{
	char	*buf;
	size_t	len;
	size_t	buf_sz;
}		t_gnl_buf;

typedef struct s_gnl_st_buf
{
	char	buf[FT_GNL_READ_BUFFER_SIZE];
	char	*start;
	size_t	len;
}		t_gnl_st_buf;

typedef struct s_hot
{
	char	*key;
	char	*value;
	size_t	id;
}	t_hot;

typedef struct s_vla
{
	size_t	sz;
	size_t	buf_sz;
	t_hot	*buf;
}	t_vla;

// helpers
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);

void	vla_store(t_vla *buf, char *key, char *value);
char	*vla_search(t_vla *buf, char *key);

void	print_search_result(char *key, char *value);
t_hot	*vla_init(t_vla *vla, size_t buf_sz);
t_hot	*vla_realloc(t_vla *vla);
void	vla_free(t_vla *vla);

#endif  // HOTRACE_H
