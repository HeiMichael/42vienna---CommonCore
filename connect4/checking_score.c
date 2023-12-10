/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:31:35 by miheider          #+#    #+#             */
/*   Updated: 2023/12/10 15:39:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int check_for_red(char **game, int row, int col, int *top)
{
	int i;
	int j;

	i = 0;										//three in a row - red - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == game[i][j+2] && game[i][j] == 'X')
			{
				if ((j+3) < col)
					if(top[j+3] == i)
					{
						//printf("found a three - red - horizontal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+4);
					}
				if ((j-1) >= 0)
					if (top[j-1] == i)
					{
						//printf("found a three - red - horizontal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
			}
			j++;
		}
		i++;
	}

	i = 0;										//2space1 - red - horizontal
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
	}

	i = 0;										//1space2 - red - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i][j+2] && game[i][j] == game[i][j+3] && game[i][j] == 'X')
			{
				
				if(top[j+1] == i)
				{
					//printf("1space2 - red - horizontal(j+2): i = %d, j = %d\n", i, j);
					return (j+2);
				}
			}
			j++;
		}
		i++;
	}
	i = 0;									//three in a row - red - vertical
	while (i < row-2)
	{
		j = 0;
		while (j < col)
		{
			if (game[i][j] == game[i+1][j] && game[i][j] == game[i+2][j] && game[i][j] == 'X')
			{
				if ((i-1) >= 0)
					if (top[j] == i-1)
					{
					//printf("found a three - red - verical(j+1): i = %d, j = %d\n", i, j);
						return (j + 1);
					}
			}
			j++;
		}
		i++;
	}	
	i = 2;									//three in a row - red - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-2][j+2] && game[i][j] == 'X')
			{
				if ((j-1) >= 0 && (i+1) < row)
					if(top[j-1] == i+1)
					{
						//printf("found a three - red - pos diagonal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
				if ((j+3) < col && (i-3) >= 0)
					if (top[j+3] == i-3)
					{
						//printf("found a three - red - pos diagonal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+4);
					}
			}
			j++;
		}
		i++;
	}
	i = 3;									//2space1 - red - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-3][j+3] && game[i][j] == 'X')
			{
				if (j >= 2)
					if(top[j-2] == i+2)
					{
						//printf("2space1 - red - pos diagonal(j-1): i = %d, j = %d\n", i, j);
						return (j-1);
					}
			}
			j++;
		}
		i++;
	}
	i = 3;									//1space2 - red - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i-2][j+2] && game[i][j] == game[i-3][j+3] && game[i][j] == 'X')
			{
				//printf("%d", j);
				if(top[j+1] == i-1)
				{
					//printf("1space2 - red - pos diagonal(j): i = %d, j = %d\n", i, j);
					return (j+2);
				}
			}
			j++;
		}
		i++;
	}	
	i = 0;										//three in a row - red - neg diagonal
	while (i < row-2)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == game[i+2][j+2] && game[i][j] == 'X')
			{
				if ((j-1) >= 0 && (i-1) >= 0)
					if(top[j-1] == i-1)
					{
						//printf("found a three - red - neg giagonal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
				if ((j+3) < col && (i+3) < row)
					if (top[j+3] == i+3)
					{
						//printf("found a three - red - neg giagonal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+4);
					}
			}
			j++;
		}
		i++;
	}
	i = 0;									//2space1 - red - neg diagonal
	while (i < row-3)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == game[i+3][j+3] && game[i][j] == 'X')
			{
				if(top[j+2] == i+2)
				{
					//printf("2space1 - red - neg diagonal(j+3): i = %d, j = %d\n", i, j);		
					return (j+3);
				}
			}
			j++;
		}
		i++;
	}	
	i = 0;									//1space2 - red - neg diagonal
	while (i < row-3)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i+2][j+2] && game[i][j] == game[i+3][j+3] && game[i][j] == 'X')
			{
				if(top[j+1] == i+1)
				{
					//printf("1space2 - red - neg diagonal(j+2): i = %d, j = %d\n", i, j);	
					return (j+2);
				}
			}
			j++;
		}
		i++;
	}	
	return (0);
}

int check_for_yellow(char **game, int row, int col, int *top)
{
	int i;
	int j;

	i = 0;										//three in a row - yellow - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == game[i][j+2] && game[i][j] == 'O')
			{
				if ((j+3) < col)
					if(top[j+3] == i)
					{
						//printf("found a three - yellow - horizontal_end(j+4): i = %d, j = %d\n", i, j);		
						return (j+4);
					}
				if ((j-1) >= 0)
					if (top[j-1] == i)
					{
						//printf("found a three - yellow - horizontal_front(j+4): i = %d, j = %d\n", i, j);		
						return (j);
					}
			}
			j++;
		}
		i++;
	}
	i = 0;										//2space1 - yellow - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i][j+1] && game[i][j] == game[i][j+3] && game[i][j] == 'O')
			{
				
				if(top[j+2] == i)
				{
					//printf("2space1 - yellow  - horizontal(j+3): i = %d, j = %d\n", i, j);
					return (j+3);
				}
			}
			j++;
		}
		i++;
	}

	i = 0;										//1space2 - yellow - horizontal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i][j+2] && game[i][j] == game[i][j+3] && game[i][j] == 'O')
			{
				if(top[j+1] == i)
				{
					//printf("1space2 - yellow - horizontal(j+2): i = %d, j = %d\n", i, j);				
					return (j+2);
				}
			}
			j++;
		}
		i++;
	}

	i = 0;									//three in a row - yellow - vertical
	while (i < row-2)
	{
		j = 0;
		while (j < col)
		{
			if (game[i][j] == game[i+1][j] && game[i][j] == game[i+2][j] && game[i][j] == 'O')
			{
				if ((i-1) >= 0)
					if (top[j] == i-1)
					{
						//printf("found a three - yellow - verical(j+1): i = %d, j = %d\n", i, j);		
						return (j + 1);
					}
			}
			j++;
		}
		i++;
	}	
	i = 2;											//three in a row - yellow - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-2][j+2] && game[i][j] == 'O')
			{
				if ((j-1) >= 0 && (i+1) < row)
					if(top[j-1] == i+1)
					{
						//printf("found a three - yellow - pos diagonal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
				if ((j+3) < col && (i-3) >= 0)
					if (top[j+3] == i-3)
					{
						//printf("found a three - yellow - pos diagonal_end(j+4): i = %d, j = %d\n", i, j);					
						return (j+4);
					}
			}
			j++;
		}
		i++;
	}	
	i = 3;									//2space1 - yellow - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i-1][j+1] && game[i][j] == game[i-3][j+3] && game[i][j] == 'O')
			{
				if (j >= 2)
					if(top[j-2] == i+2)
					{
						//printf("2space1 - yellow - pos diagonal(j-1): i = %d, j = %d\n", i, j);
						return (j-1);
					}
			}
			j++;
		}
		i++;
	}
	i = 3;									//1space2 - yellow - pos diagonal
	while (i < row)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i-2][j+2] && game[i][j] == game[i-3][j+3] && game[i][j] == 'O')
			{
				//printf("%d", j);
				if(top[j+1] == i-1)
				{
					//printf("1space2 - yellow - pos diagonal(j): i = %d, j = %d\n", i, j);
					return (j+2);
				}
			}
			j++;
		}
		i++;
	}	
	i = 0;											//three in a row - yellow - neg diagonal
	while (i < row-2)
	{
		j = 0;
		while (j < col-2)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == game[i+2][j+2] && game[i][j] == 'O')
			{
				if ((j-1) >= 0 && (i-1) >= 0)
					if(top[j-1] == i-1)
					{
						//printf("found a three -yellow - neg diagonal_front(j): i = %d, j = %d\n", i, j);
						return (j);
					}
				if ((j+3) < col && (i+3) < row)
					if (top[j+3] == i+3)
					{
						//printf("found a three -yellow - neg diagonal_end(j+4): i = %d, j = %d\n", i, j);
						return (j+4);
					}
			}
			j++;
		}
		i++;
	}	
	i = 0;									//2space1 - yellow - neg diagonal
	while (i < row-3)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i+1][j+1] && game[i][j] == game[i+3][j+3] && game[i][j] == 'O')
			{
				if(top[j+2] == i+2)
				{
					//printf("2space1 - yellow - neg diagonal(j+3): i = %d, j = %d\n", i, j);
					return (j+3);
				}
			}
			j++;
		}
		i++;
	}	
	i = 0;									//1space2 - yellow - neg diagonal
	while (i < row-3)
	{
		j = 0;
		while (j < col-3)
		{
			if (game[i][j] == game[i+2][j+2] && game[i][j] == game[i+3][j+3] && game[i][j] == 'O')
			{
				if(top[j+1] == i+1)
				{
					//printf("1space2 - yellow - neg diagonal(j+2): i = %d, j = %d\n", i, j);
					return (j+2);
				}
			}
			j++;
		}
		i++;
	}	
	return (0);
}

