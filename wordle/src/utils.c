/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiochal < sgiochal@student.42vienna.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:27:24 by sgiochal          #+#    #+#             */
/*   Updated: 2023/11/11 17:45:38 by sgiochal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

extern char		footer[FOOTER_COUNT];

int	rand_idx(int max_index)
{
	srand(time(0));
	return (rand() % max_index);
}

void	update_footer(const char *str)
{
	int len = strlen(str);
	int begin_spaces = (FOOTER_COUNT - len - 4)/2;
	for (int i = 0; i < FOOTER_COUNT; i++)
		footer[i] = ' ';
	strncpy((footer+begin_spaces), str, FOOTER_COUNT);
}

int	is_valid(const char *str)
{
	int	len;
	int	i;

	len = strlen(str);
	if (len != 5)
		return (0);
	i = 0;
	while (i < len)
	{
		if (!isalpha(str[i]))
			return (0);
		i++;
	}	
	return (1);
}

int	is_in_dictionary(const char *str, char dict[MAX_WORD_COUNT][COUNT + 1], int dict_len)
{
	int		i;
	char	c[6] = {0};

	i = 0;
	while (i < dict_len)
	{
		for (int j = 0; j < COUNT; j++)
			c[j] = toupper(dict[i][j]);
		if (strncmp(str, c, 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	fill_array(char *array, int columns, int rows, char c)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			array[columns * i +  j] = c;
}

void clear_input_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}