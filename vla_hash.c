/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:22:14 by vvilensk          #+#    #+#             */
/*   Updated: 2023/10/15 21:27:22 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static size_t	calc_hash(char *str, size_t modulo, size_t *id)
{
	size_t	h;
	size_t	x;

	x = 1;
	h = 0;
	while (*str != '\n' && *str)
	{
		x *= HASH_CONSTANT;
		h = h + x * *str++;
	}
	*id = h;
	return (h % modulo);
}

// check repetitions?
//terminate / update/ ignore?
void	vla_store(t_vla *vla, char *key, char *value)
{
	size_t	idx;
	size_t	id;

	idx = calc_hash(key, vla->buf_sz, &id);
	while (vla->buf[idx].key != NULL)
	{
		if (id == vla->buf[idx].id && 0 == ft_strcmp(vla->buf[idx].key, key))
		{
			free(vla->buf[idx].value);
			vla->buf[idx].value = value;
			return ;
		}
		idx = (idx + 1) % vla->buf_sz;
	}
	vla->buf[idx].key = key;
	vla->buf[idx].value = value;
	vla->buf[idx].id = id;
	vla->sz++;
}

char	*vla_search(t_vla *vla, char *key)
{
	size_t	idx;
	size_t	id;

	idx = calc_hash(key, vla->buf_sz, &id);
	while (vla->buf[idx].key != NULL)
	{
		if (id == vla->buf[idx].id && 0 == ft_strcmp(vla->buf[idx].key, key))
			return (vla->buf[idx].value);
		idx = (idx + 1) % vla->buf_sz;
	}
	return (NULL);
}
