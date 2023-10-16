/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:43:36 by miheider          #+#    #+#             */
/*   Updated: 2023/10/16 15:10:41 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <fcntl.h>
#undef STDIN_FILENO
int STDIN_FILENO = 1;

static int	free_and_ret(int ret_code, t_vla *vla, void *key, void *value)
{
	vla_free(vla);
	free(key);
	free(value);
	return (ret_code);
}

static int	input_process(t_vla *vla)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(STDIN_FILENO);
		if (key == NULL)
			return (free_and_ret(READ_ERROR, vla, NULL, NULL));
		if (*key == '\n')
		{
			free(key);
			break ;
		}
		if (vla->sz * 100 / vla->buf_sz > REALLOC_PERCENT)
		{
			if (!vla_realloc(vla))
				free_and_ret(MALLOC_ERROR, vla, key, NULL);
		}
		value = get_next_line(STDIN_FILENO);
		if (value == NULL)
			return (free_and_ret(READ_ERROR, vla, key, value));
		vla_store(vla, key, value);
	}
	return (NO_ERROR);
}

// break if empty line or eof
static void	search_display(t_vla *vla)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(STDIN_FILENO);
		if (NULL == key)
			break ;
		if (*key == '\n')
		{
			free(key);
			break ;
		}
		value = vla_search(vla, key);
		print_search_result(key, value);
		free(key);
	}
}

//STDIN_FILENO = open("1.txt", O_RDONLY);
int	main(void)
{
	t_vla	vla;
	int		code;

	if (!vla_init(&vla, INIT_BUFF_SZ))
		return (free_and_ret(MALLOC_ERROR, &vla, NULL, NULL));
	code = input_process(&vla);
	if (code != NO_ERROR)
		return (code);
	search_display(&vla);
	return (free_and_ret(NO_ERROR, &vla, NULL, NULL));
}
