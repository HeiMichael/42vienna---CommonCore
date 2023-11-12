/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:22:14 by vvilensk          #+#    #+#             */
/*   Updated: 2023/10/16 16:13:45 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*realloc_accum(t_gnl_buf *accum, size_t sz)
{
	const size_t	total_sz = accum->len + sz;
	char			*realloced;
	size_t			realloc_sz;

	if (accum->buf_sz >= total_sz)
		return (accum->buf);
	else if (accum->buf_sz == 0)
		realloc_sz = FT_GNL_ACCUM_INIT_SIZE;
	else
		realloc_sz = accum->buf_sz;
	while (realloc_sz < total_sz)
		realloc_sz *= 2;
	realloced = malloc(sizeof(char) * realloc_sz);
	if (!realloced)
		return (NULL);
	ft_memcpy(realloced, accum->buf, accum->len);
	accum->buf = realloced;
	accum->buf_sz = realloc_sz;
	return (accum->buf);
}

static char	*get_stored_from_buffer(
	t_gnl_st_buf *st_buf, t_gnl_buf *accum)
{
	size_t	len;

	len = 0;
	while (len < st_buf->len && st_buf->start[len] != '\n')
		len++;
	len += (len < st_buf->len && st_buf->start[len] == '\n');
	if (!realloc_accum(accum, len + 1))
		return (NULL);
	ft_memcpy(accum->buf + accum->len, st_buf->start, len);
	accum->len += len;
	accum->buf[accum->len] = '\0';
	st_buf->len -= len;
	if (st_buf->len == 0)
		st_buf->start = st_buf->buf;
	else
		st_buf->start = st_buf->start + len;
	return (accum->buf);
}

static char	*read_next(int fd, t_gnl_st_buf *st_buf, t_gnl_buf *accum)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, st_buf->buf, FT_GNL_READ_BUFFER_SIZE);
	st_buf->len = read_bytes * (read_bytes > 0);
	if (read_bytes < 0)
		accum->len = 0;
	if (read_bytes <= 0)
		return (NULL);
	if (!get_stored_from_buffer(st_buf, accum))
		accum->len = 0;
	return (accum->buf);
}

char	*get_next_line(int fd)
{
	static t_gnl_st_buf	st_buf = {.len = 0, .start = st_buf.buf};
	t_gnl_buf			accum;

	accum.buf_sz = 0;
	accum.len = 0;
	accum.buf = NULL;
	if (!get_stored_from_buffer(&st_buf, &accum))
		return (free(accum.buf), NULL);
	if (accum.len && accum.buf[accum.len - 1] == '\n')
		return (accum.buf);
	while (read_next(fd, &st_buf, &accum))
		if (accum.len && accum.buf[accum.len - 1] == '\n')
			return (accum.buf);
	if (accum.len != 0)
		return (accum.buf);
	free(accum.buf);
	return (NULL);
}
