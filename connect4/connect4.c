/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:21:16 by mhuszar           #+#    #+#             */
/*   Updated: 2023/12/09 11:21:19 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	tie_checker(char **grid, int x, int y)
{
	int counter = 0;
	int *tops = top_list(grid, x, y);
	if (!tops)
		return (-1);
	while(tops[counter] == -1)
	{
		counter++;
		if (counter >= x)
			break ;
	}
	free(tops);
	if (counter == x)
		return (1);
	else
		return (0);
}

char **make_grid(int x, int y)
{
    int counter = 0;
    int i = 0;
    char **grid = malloc(sizeof(char *) * y);
    if (!grid)
        return (NULL);
    while (counter < y)
    {
        grid[counter] = malloc(x + 1);
        if (!grid[counter])
            return (NULL);
        while (i < x)
        {
            grid[counter][i] = 'F';
            i++;
        }
        grid[counter][i] = '\0';
        i = 0;
        counter++;
    }
    return(grid);
}

void free_grid(char **grid, int y)
{
    int counter = 0;
    
    if (grid)
    {
        while (counter < y)
        {
            if (grid[counter])
                free(grid[counter]);
            counter++;
        }
        free(grid);
    }
}

int modify_grid(char ***ancestor, int x, int y, int input_col, int color)
{
    char **grid = *ancestor;
    int *tops = top_list(grid, x, y);
        if (!tops)
            return (-1);
    //color 0 is red, 1 is yellow

    if (tops[input_col - 1] == -1)
    {
    	free(tops);
    	return (0);
    }
    if (grid[tops[input_col - 1]][input_col - 1] == 'F')
    {
    	if (color == 0)
                grid[tops[input_col - 1]][input_col - 1] = 'X';
            else
                grid[tops[input_col - 1]][input_col -1 ] = 'O';
    }
    else
    {
    	free(tops);
    	return (0);
    }
    free(tops);
    return (1);
}

int init_game(char **grid, int x, int y, int cutoff_flag)
{
    int flag = 1;
    char *line = NULL;
    int input = 0;
    srand(time(NULL));
    int color = rand() % 2; //0 for red, 1 for yellow
    int counter = 0;
    int line_flag = 0;
    int a = 0;
    int b = 0;
    //int *tops = 0;

    ft_printf("\nWelcome to: \033[0;92mconnect4\033[0;39m!\nYour opponent is: \033[0;91mDESTROYER\033[0;39m the genius AI!\n");
    if (cutoff_flag)
    	ft_printf("\nThe grid size you requested is too large.\n(X cutoff is: 35, Y cutoff is: 45).\nTherefore you will have no display provided.\nYou will have to keep note of all the progress in your head!\n");
    if (color == 1)
    	ft_printf("\nDESTROYER starts the game!\n");
    else
    	ft_printf("\nYou start the game!\n");
    while (flag)
    {
        if (color == 0 && !cutoff_flag)
            display(grid, x, y);
        if (color == 1)
        {
            if (!destroyer(&grid, x, y))
                return(error_msg(grid, y));
            goto done;
        }
        ft_printf("\nPlease select a column: ");
        take_data:
        line = get_next_line(0);
        if (!line)
            return(error_msg(grid, y));
        else
            line_flag = 1;
        input = ft_atoi(line);
        if (input < 1 || input > x)
        {
            ft_printf("Invalid input. Please select a column: ");
            free(line);
            line = NULL;
            goto take_data;
        }
        a = modify_grid(&grid, x, y, input, color);
        if (a == -1)
        {
            return(error_msg(grid, y));
        }
        else if (!a)
        {
            ft_printf("Line is full. Please select another column: ");
            free(line);
            line = NULL;
            goto take_data;
        }
        else
        {
            done:
            if (color == 1)
                color = 0;
            else if (color == 0)
                color = 1;
        }
        if (check_for_winning(grid, y, x))
        {
            ft_printf("\n");
            if (!cutoff_flag)
            	display(grid, x, y);
            flag = 0;
        }
        b = tie_checker(grid, x, y);
        if (b == -1)
        	return(error_msg(grid, y));
        else if (b)
        {
            ft_printf("\n");
            if (!cutoff_flag)
            	display(grid, x, y);
            ft_printf("\nIt's a tie!\n");
            flag = 0;
        }
        counter++;
        if (line_flag)
        {
            free(line);
            line_flag = 0;
        }
        ft_printf("\n\n");
    }
    free_grid(grid, y);
    ft_printf("Game over!\n"); //i mean we still have to work something out here
    //CHECK FOR A TIE TOO!
    //CHECK FOR HEX INPUT
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return (error_msg(NULL, 0));
    long int x = ft_atoi(argv[1]);
    long int y = ft_atoi(argv[2]);
    int cutoff_flag = 0;
    if (x < X_MIN || x > X_MAX)
        return (error_msg(NULL, 0));
    if (y < Y_MIN || y > Y_MAX)
        return (error_msg(NULL, 0));
    if (y > Y_CUTOFF || x > X_CUTOFF)
        cutoff_flag = 1;
    char **grid = make_grid(x, y);
    if (!grid)
        return (error_msg(NULL, 0));
    return (init_game(grid, x, y, cutoff_flag));
}

