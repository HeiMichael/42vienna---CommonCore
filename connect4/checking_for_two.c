/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_for_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:31:35 by miheider          #+#    #+#             */
/*   Updated: 2023/12/10 16:39:01 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int check_for_two_red(char **game, int row, int col, int *top)
{
	int i;
	int j;

	i = 0;										//two in a row - red - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-1)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == 'X')
			{
				if ((j+2) < col)
					if(top[j+2] == i)
					{
						//printf("found a two - red - horizontal_end(j+3): i = %d, j = %d\n", i, j);
						return (j+3);
					}
				if ((j-1) >= 0)
					if (top[j-1] == i)
					{
						//printf("found a two - red - horizontal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
			}
			j++;
		}
		i++;
	}
/*
	i = 0;										//1space1 - red - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == game[i][j+3] && game[i][j] == 'X')
			{
				if(top[j+2] == i)
				{
					//printf("2space1 - red - horizontal(j+3): i = %d, j = %d\n", i, j);
					return (j+3);
				}
			}
			j++;
		}
		i++;
	}*/
	i = 0;									//two in a row - red - vertical
	while (i < row-1)
	{
		j = 0;
		while (j < col)
		{
			if (game[i][j] == game[i+1][j] && game[i][j] == 'X')
			{
				if ((i-1) >= 0)
					if (top[j] == i-1)
					{
					//printf("found a two - red - verical(j+1): i = %d, j = %d\n", i, j);
						return (j + 1);
					}
			}
			j++;
		}
		i++;
	}	
	i = 1;									//two in a row - red - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-1)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == 'X')
			{
				if ((j-2) >= 0 && (i+2) < row)
					if(top[j-2] == i+2)
					{
						//printf("found a two - red - pos diagonal_front(j): i = %d, j = %d\n", i, j);
						return (j-1);
					}
				if ((j+1) < col && (i-1) >= 0)
					if (top[j+1] == i-1)
					{
						//printf("found a two - red - pos diagonal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+2);
					}
			}
			j++;
		}
		i++;
	}
/*	i = 2;									//1space1 - red - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-3][j+3] && game[i][j] == 'X')
			{
				if(top[j-2] == i+2)
				{
					//printf("2space1 - red - pos diagonal(j-1): i = %d, j = %d\n", i, j);
					return (j-1);
				}
			}
			j++;
		}
		i++;
	}*/
	i = 0;										//two in a row - red - neg diagonal
	while (i < row-1)
	{
		j = 0;
		while (j < col-1)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == 'X')
			{
				if ((j-1) >= 0 && (i-1) >= 0)
					if(top[j-1] == i-1)
					{
						//printf("found a two - red - neg giagonal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
				if ((j+2) < col && (i+2) < row)
					if (top[j+2] == i+2)
					{
						//printf("found a two - red - neg giagonal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+3);
					}
			}
			j++;
		}
		i++;
	}
	i = 0;									//1space1 - red - neg diagonal
	while (i < row-2)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == 'X')
			{
				if ((j+2) < col)
					if(top[j+2] == i+2)
					{
						//printf("1space1 - red - neg diagonal(j+3): i = %d, j = %d\n", i, j);		
						return (j+3);
					}
			}
			j++;
		}
		i++;
	}	
	return (0);
}


int check_for_two_yellow(char **game, int row, int col, int *top)
{
	int i;
	int j;

	i = 0;										//two in a row - yellow - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-1)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == 'O')
			{
				if ((j+2) < col)
					if(top[j+2] == i)
					{
						//printf("found a two - yellow - horizontal_end(j+3): i = %d, j = %d\n", i, j);
						return (j+3);
					}
				if ((j-1) >= 0)
					if (top[j-1] == i)
					{
						//printf("found a two - yellow - horizontal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
			}
			j++;
		}
		i++;
	}
/*
	i = 0;										//1space1 - yellow - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == game[i][j+3] && game[i][j] == 'O')
			{
				if(top[j+2] == i)
				{
					//printf("2space1 - yellow - horizontal(j+3): i = %d, j = %d\n", i, j);
					return (j+3);
				}
			}
			j++;
		}
		i++;
	}*/
	i = 0;									//two in a row - yellow - vertical
	while (i < row-1)
	{
		j = 0;
		while (j < col)
		{
			if (game[i][j] == game[i+1][j] && game[i][j] == 'O')
			{
				if ((i-1) >= 0)
					if (top[j] == i-1)
					{
					//printf("found a two - yellow - verical(j+1): i = %d, j = %d\n", i, j);
						return (j + 1);
					}
			}
			j++;
		}
		i++;
	}	
	i = 1;									//two in a row - yellow - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-1)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == 'O')
			{
				if ((j-2) >= 0 && (i+2) < row)
					if(top[j-2] == i+2)
					{
					//	printf("found a two - yellow - pos diagonal_front(j): i = %d, j = %d\n", i, j);
						return (j-1);
					}
				if ((j+1) < col && (i-1) >= 0)
					if (top[j+1] == i-1)
					{
						//printf("found a two - yellow - pos diagonal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+2);
					}
			}
			j++;
		}
		i++;
	}
/*	i = 2;									//1space1 - yellow - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-3][j+3] && game[i][j] == 'X')
			{
				if(top[j-2] == i+2)
				{
					//printf("2space1 - yellow - pos diagonal(j-1): i = %d, j = %d\n", i, j);
					return (j-1);
				}
			}
			j++;
		}
		i++;
	}*/
	i = 0;										//two in a row - yellow - neg diagonal
	while (i < row-1)
	{
		j = 0;
		while (j < col-1)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == 'O')
			{
				if ((j-1) >= 0 && (i-1) >= 0)
					if(top[j-1] == i-1)
					{
						//printf("found a two - yellow - neg giagonal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
				if ((j+2) < col && (i+2) < row)
					if (top[j+2] == i+2)
					{
						//printf("found a two - yellow - neg giagonal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+3);
					}
			}
			j++;
		}
		i++;
	}
	i = 0;									//1space1 - yellow - neg diagonal
	while (i < row-2)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == 'O')
			{
				if(top[j+2] == i+2)
				{
					//printf("1space1 - yellow - neg diagonal(j+3): i = %d, j = %d\n", i, j);		
					return (j+3);
				}
			}
			j++;
		}
		i++;
	}	
	return (0);
}

