/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:16:46 by miheider          #+#    #+#             */
/*   Updated: 2024/02/02 19:39:23 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (src[x] != '\0')
		x++;
	if (size == 0)
		return (x);
	y = 0;
	while (src[y] != '\0' && y < (size -1))
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (x);
}

int check_string(char input, char next)
{
    char special[11];
    char *special_ptr = special;

    ft_strlcpy(special, "*?[()]<>|$", 10);
	printf("input: %c\n", input);
	printf("next: %c\n", next);
    while (*special_ptr)
    {
		printf("ptr: %c\n", *special_ptr);
        if (*special_ptr == input && input == next)
            return (2);
        else if (*special_ptr == input || input == 34)
            return (1);
        else
            special_ptr++;
    }

    return 0;
}

void	preparing_input(char *input)
{
	size_t	wc;				//word counter (zählt alle Wörter)
	size_t	i;
	size_t	cc;				//char-count (zählt alle nicht-spaces)

	cc = 0;
	wc = 0;
	while (*input)
	{
		while (*input && *input == 32)
			input++;
		if (*input != 32)
		{
			wc++;
		}
		while (*input && *input != 32)
		{
			if (check_string(*input, *(input+1)) == 0)
			{
				cc++;
				input++;
				printf("Hallo\n");
			}
			else if (check_string(*input, *(input+1)) == 1)
			{
				if (*(input-1) == 32)
				{
					wc += 1;
					cc++;
					input++;
				}
				else
				{
					wc += 2;
					cc++;
					input++;
				}
				printf("Wie\n");
			}
			else if (check_string(*input, *(input+1)) == 2)
			{
				wc += 2;
				cc += 2;
				input++;
				input++;
				printf("gehts?\n");
			}
		}
	}
	printf("wc: %zu\n", wc);
	printf("cc: %zu\n", cc);
}



int	main(int argc, char **argv)
{
	char	*input;

	input = NULL;
	preparing_input(argv[1]);
	return (0);
}