/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:23:59 by miheider          #+#    #+#             */
/*   Updated: 2023/10/16 15:29:45 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_hot	*vla_init(t_vla *vla, size_t buf_sz)
{
	t_hot	*allocated;

	allocated = (t_hot *)malloc(sizeof(t_hot) * buf_sz);
	if (!allocated)
		return (NULL);
	vla->buf = allocated;
	vla->sz = 0;
	vla->buf_sz = buf_sz;
	while (buf_sz > 0)
	{
		buf_sz--;
		vla->buf[buf_sz].key = NULL;
	}
	return (vla->buf);
}

t_hot	*vla_realloc(t_vla *vla)
{
	size_t	old_size;
	t_hot	*old_buf;

	old_size = vla->buf_sz;
	old_buf = vla->buf;
	if (NULL == vla_init(vla, (old_size * EXPAND_CONST)))
		return (NULL);
	while (old_size > 0)
	{
		old_size--;
		if (old_buf[old_size].key)
			vla_store(vla, old_buf[old_size].key, old_buf[old_size].value);
	}
	free (old_buf);
	return (vla->buf);
}

void	vla_free(t_vla *vla)
{
	size_t	i;

	i = 0;
	while (i < vla->buf_sz)
	{
		if (vla->buf[i].key != NULL)
		{
			free (vla->buf[i].key);
			free (vla->buf[i].value);
		}
		i++;
	}
	free (vla->buf);
}
