/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:52:48 by mhuszar           #+#    #+#             */
/*   Updated: 2023/12/10 22:01:02 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	value_calc(char **grid, int x, int y, int color, int *top)
{
    int cur = 0;
    int val = 0;
    int best_col = -1;
    int best_val = 0;
    int last = y - 1;
    char goal;
    //color is 0 for red (X), 1 for yellow (O)
    if (color == 1)
        goal = 'O';
    else
        goal = 'X';
    while (cur < x)
    {
        if (top[cur] == -1)
        {
            last = y - 1;
            cur++;
            continue ;
        }
        while (grid[last][cur] != 'F' && last >= 0)
            last--;
        if (last + 1 < y)
        {
            if (grid[last + 1][cur] == goal)
                val++;
        }
        if (cur + 1 < x)
        {
            if (grid[last][cur + 1] == goal)
                val++;
        }
        if (cur - 1 > -1)
        {
            if (grid[last][cur - 1] == goal)
                val++;
        }
        if (last + 1 < y && cur + 1 < x)
        {
            if (grid[last + 1][cur + 1] == goal)
                val++;
        }
        if (last + 1 < y && cur - 1 > -1)
        {
            if (grid[last + 1][cur - 1] == goal)
                val++;
        }
        if (val > best_val)
        {
            best_val = val;
            best_col = cur;
        }
        val = 0;
        last = y - 1;
        cur++;
    }
    if (best_col == -1)
    {
        //best_col = value_calc(grid, x, y, 0) - 1;
        srand(time(NULL));
        best_col = (rand() % (x - 1));
    }
    return (best_col + 1);
}

int danger(char ***ancestor, int x, int y, int col, int *top)
{
	//ft_printf("\nenter danger function. Chosen column: %d\n", col);
	char **grid = *ancestor;
	int b = check_for_red(grid, y, x, top);
	//printf("\nGrid column %d top is before: %c\n", col, grid[top[col - 1]][col - 1]);
	modify_grid(ancestor, x, y, col, 1);
	//printf("\nGrid column %d top is after: %c\n", col, grid[top[col - 1]][col - 1]);
	top[col - 1]--;
	int a = check_for_red(grid, y, x, top);
	//printf("\nvalue of a is: %d\n", a);
	top[col - 1]++;
	grid[top[col - 1]][col - 1] = 'F';
	if (a && !b)
	{
		//ft_printf("DANGER!!!! IN COLUMN: %d\n", col);
		return (1);
	}
	else
		return(0);
}


int	insit(int *danger_zone, int col, int i)
{
	int counter = 0;
	while (counter <= i)
	{
		if (danger_zone[counter] == col)
			return (counter + 1);
		else
			counter++;
	}
	return (0);
}


int destroyer(char ***grid, int x, int y)
{
    //1, yellow or O is AI
    //check for 3
    //defend function
    //ft_printf("Hi, i'm destroyer!!");
    int proxy = 0;
	int	danger_zone[100];
	int	i = 0;
    int col = 0;
    int counter = 0;
    srand(time(NULL));
	ft_bzero(danger_zone, 100);
    int *top = top_list(*grid, x, y);
    if (!top)
        return (0);
    //ft_printf("what's up!!");
    beginning:
    col = check_for_yellow(*grid, y, x, top);
    if (col)
    	goto finish;
    if (!col || col == proxy)
    	col = check_for_red(*grid, y, x, top);
    if (!col || col == proxy)
    	col = check_for_two_yellow(*grid, y, x, top);
    if (!col || col == proxy)
    	col = check_for_two_red(*grid, y, x, top);
    //ft_printf("OIOIOI!!");
    //if (!col)// && y > 6)
    	//col = value_calc(*grid, x, y, 1, top);
    //ft_printf("Do we reach this?");
    if (!col || col == proxy)
    {
        col = (rand() % x + 1);
    }
    //int col = value_calc(*grid, x, y, 1);
    while (top[col - 1] == -1 || col == proxy)
    	col = (rand() % x + 1);
    if (!danger(grid, x, y, col, top))
    {
    	if (insit(danger_zone, col, i))
    		danger_zone[insit(danger_zone, col, i) - 1] = 0;
    	finish:
    	modify_grid(grid, x, y, col, 1);
    }
    else
    {
    	while(top[counter] == -1 || counter == col - 1 || insit(danger_zone, col, i))
		{
			counter++;
			ft_printf("counter: %d", counter);
			if (counter >= x)
				goto finish;
		}
		counter = 0;
		if (i < 100 && !insit(danger_zone, col, i))
		{
    		danger_zone[i] = col;
    		i++;
    	}
		proxy = col;
    	//col = 0;
    	//while (top[col - 1] == -1 || col == proxy)
    		//col = (rand() % x + 1);
    	goto beginning;
    }
    free(top);
    ft_printf("DESTROYER chooses column %d!", col);
    return (1);
}
