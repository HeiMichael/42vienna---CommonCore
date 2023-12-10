/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_winning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:34:31 by miheider          #+#    #+#             */
/*   Updated: 2023/12/09 14:02:17 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "connect4.h"

int	winning(char W)
{
	if (W == 'X')
		ft_printf("\nYou win!\n");
	if (W == 'O')
		ft_printf("\nDESTROYER wins!\n");
	return (1);
}

int	check_for_winning(char **game, int row, int col)
{
	int	i;
	int	j;

//check horizontal
	i = 0;															
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == game[i][j+2] && game[i][j]
				== game[i][j+3] && game[i][j] == 'X') 
				return (winning('X'));
			if (game[i][j] == game[i][j+1] && game[i][j] == game[i][j+2] && game[i][j]
				== game[i][j+3] && game[i][j] == 'O')
				return (winning('O'));
			j++;
		}
	i++;
	}
//check vertical
	i = 0;
	while (i < row-3)
	{
		j = 0;
		while (j < col)
		{
			if (game[i][j] == game[i+1][j] && game[i][j] == game[i+2][j] && game[i][j] 
				== game[i+3][j] && game[i][j] == 'X') 
				return (winning('X'));
			if (game[i][j] == game[i+1][j] && game[i][j] == game[i+2][j] && game[i][j]
				== game[i+3][j] && game[i][j] == 'O')
				return (winning('O'));
			j++;
		}
		i++;
	}
//check positivly sloped diagonal
	i = 3;
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-2][j+2] && game[i][j]
				== game[i-3][j+3] && game[i][j] == 'X') 
				return (winning('X'));
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-2][j+2] && game[i][j]
				== game[i-3][j+3] && game[i][j] == 'O')
				return (winning('O'));
			j++;
		}
		i++;
	}
//check negatively sloped diagonal
	i = 0;
	while (i < row-3)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == game[i+2][j+2] && game[i][j]
				== game[i+3][j+3] && game[i][j] == 'X') 
				return (winning('X'));
			if (game[i][j] == game[i+1][j+1] && game[i][j] == game[i+2][j+2] && game[i][j]
				== game[i+3][j+3] && game[i][j] == 'O')
				return (winning('O'));
			j++;
		}
		i++;
	}
	return (0);
}
/*
int main(void) {
    char game[6][8] = {
        {70,70,70,70,70,70,70,70},
        {70,70,70,70,70,70,70,70},
        {70,70,70,70,70,70,70,70},
        {70,70,70,70,70,70,70,70},
        {70,70,70,70,70,70,70,70},
        {70,70,70,70,70,70,70,70}
    };
    
    int row = 6;
    int col = 8;
    check_for_winning(game, row, col);
    printf("Nobody won! Game not over yet!");
    return (0);
}*/
