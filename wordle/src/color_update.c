/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiochal < sgiochal@student.42vienna.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:47:05 by miheider          #+#    #+#             */
/*   Updated: 2023/11/12 17:34:01 by sgiochal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wordle.h>

static void repeat(char *counter, int *sol_count)
{
	int i;

	i = -1;
	while (counter[++i])
		sol_count[counter[i] - 65] += 1;
}

void update_color(char *solution, char *guess, char *color, char acolor[26])
{
	int		sol_count[27] = {0};
	int		gue_count[27] = {0};
	int 	i;
	int		j;

	repeat(solution, sol_count);
	i = -1;
	while (guess[++i])
	{
		if (guess[i] == solution[i])
		{
			color[i] = C_GREEN;
			acolor[guess[i] - 65] = C_GREEN;
			gue_count[guess[i] - 65] += 1;
		}
	}
	i = -1;
	while (guess[++i])
	{
		j = -1;
		while (solution[++j])
		{
			if (guess[i] == solution[j] && i != j && (gue_count[guess[i] - 65] < sol_count[guess[i] - 65]) && color[i] != C_GREEN)
			{
				color[i] = C_ORANGE;
				if (acolor[guess[i] - 65] != C_GREEN)
					acolor[guess[i] - 65] = C_ORANGE;
				gue_count[guess[i] - 65] += 1;
				break ;
			}
			else
			{
				if (sol_count[guess[i] - 65] == 0 && acolor[guess[i] - 65] != C_ORANGE && \
										 acolor[guess[i] - 65] != C_GREEN) 
					acolor[guess[i] - 65] = C_GRAY;
			}
		}
	}
}
/*
int main()
{
	char	solution[6] = "SPYRO";
	char	guess[6] = "SAYGO";
	int		color[6] = {C_GREY, C_GREY, C_GREY, C_GREY, C_GREY, '\0'};
	int 	i = -1;
	update_color(solution, guess, color);
	while(++i < 6)
		printf("[%d]-%d\n",i, color[i]);
	return (0);


}
*/