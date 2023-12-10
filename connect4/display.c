/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:28:23 by mhuszar           #+#    #+#             */
/*   Updated: 2023/12/09 11:28:25 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

/*#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m*/

int display(char **grid, int x, int y)
{
    int row = 0;
    int col = 0;
    int counter = 1;

    while (counter <= x)
    {
        //THINK ABOUT POSITION OF NUMBERS ABOVE 9 - RIGHT NOW ITS IN HEX
        ft_printf("\033[0;92m %X \033[0;39m", counter);
        counter++;
    }
    ft_printf("\n\n");
    while (row < y)
    {
        while (col < x)
        {
            if (grid[row][col] == 'X')
                ft_printf("\033[0;91m O \033[0;39m");
            else if (grid[row][col] == 'O')
                ft_printf("\033[0;93m O \033[0;39m");
            else if (grid[row][col] == 'F')
                ft_printf("\033[0;90m O \033[0;39m");
            else
                return (error_msg(grid, y));
            col++;
        }
        ft_printf("\n");
        row++;
        col = 0;
    }
    return(1);
}
/*
int main(void)
{
    char *grid[7];
    grid[0] = "FFFFFFFFFFFFFFFF";
    grid[1] = "FFFFFFFFFFFFFFFF";
    grid[2] = "FFFFFFFFFFFFFFFF";
    grid[3] = "FOFFFFFFFFFFFFFF";
    grid[4] = "XXFFFFFFFFFFFFFF";
    grid[5] = "OOOXFFFFFFFFFFFF";
    grid[6] = "XXXOFFFFFFFFFFFF";
    display(grid, 7, 15);
}*/

