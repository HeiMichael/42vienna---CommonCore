/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiochal < sgiochal@student.42vienna.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:38:33 by sgiochal          #+#    #+#             */
/*   Updated: 2023/11/12 20:32:15 by sgiochal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

char		footer[FOOTER_COUNT];

int	import_dict(const char *path, char dict[MAX_WORD_COUNT][6])
{
	FILE	*file;
	int		line_count = 0;

	file = fopen(path, "r");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		exit(1);
	}
	while (fscanf(file, "%6s", dict[line_count]) == 1 && line_count < 12972)//fgets(dict[line_count], COUNT + 2, file) != NULL
	{
		dict[line_count][strcspn(dict[line_count], "\n")] = '\0';
		line_count++;
	}
	/*if (feof(file))
		fclose(file);
	else if (ferror(file))
	{
		printf("Error reading dictionary.");
		exit(1);
	}*/
//	fclose(file);
	if (fclose(file) == EOF)
	{
		printf("Error closing file.");
		exit(1);
	}
	return line_count;
}
void	refresh_screen(int total_words, char display[COUNT +1][COUNT], \
	char footer[FOOTER_COUNT], char dcolor[COUNT + 1][COUNT], char acolor[26]);

int	get_input(char guess_array[COUNT + 1], int i)
{
	char input[50];

	printf("Input: "); 
	int a = scanf("%49s", input);
	if (a == 1) //fgets(input, sizeof(input), stdin
	{
		input[strcspn(input, "\n")] = 0;
		if (strcmp(input, "cheatme") == 0)
		{
			return (-8);
		}
		if(is_valid((char *)input))
		{
			sprintf(guess_array, "%s", input);
			char s[63]; 
			sprintf(s, "Cool! %d tries left.", 6 - i - 1);
			update_footer(s);
			for (int i = 0; i < COUNT; i++)
				guess_array[i] = toupper(guess_array[i]);
			return (1);
		}
		else
		{
			update_footer("Error. Invalid input. Please enter a 5-letter word");
			return (0);
		}
	}
	else
	{
		if (feof(stdin))
		{
			update_footer("No input. Exiting!");
			return (-10);
		}
		else if (ferror(stdin))
		{
			printf("Error reading dictionary.");
			exit(1);
		}
		return (0);
	}
}

void	refresh_screen(int total_words, char display[COUNT +1][COUNT], \
	char footer[FOOTER_COUNT], char dcolor[COUNT + 1][COUNT], char acolor[26])
{
	print_intro();
	printf("                Total words available: %d\n", total_words);
	printf("\n");
	print_display(display, dcolor);
	printf("\n");
	print_alphabet(acolor);
	printf("\n");
	print_footer(footer);
}

void	refresh_congrat(int total_words, char display[COUNT +1][COUNT], \
	char footer[FOOTER_COUNT], char dcolor[COUNT + 1][COUNT], char acolor[26])
{
	print_intro();
	printf("                Total words available: %d\n", total_words);
	printf("\n");
	print_display(display, dcolor);
	printf("\n");
	print_alphabet(acolor);
	printf("\n");
	print_congrat(footer);
}

void	refresh_looser(int total_words, char display[COUNT +1][COUNT], \
	char footer[FOOTER_COUNT], char dcolor[COUNT + 1][COUNT], char acolor[26])
{
	print_intro();
	printf("                Total words available: %d\n", total_words);
	printf("\n");
	print_display(display, dcolor);
	printf("\n");
	print_alphabet(acolor);
	printf("\n");
	print_looser(footer);
}

void	init_arrays(char dict[MAX_WORD_COUNT][COUNT + 1], char display[COUNT + 1][COUNT], \
	char d_color[COUNT + 1][COUNT], char acolor[26])
{
	fill_array((char *)dict, COUNT + 1, MAX_WORD_COUNT, '\0');
	fill_array((char *)display, COUNT, COUNT + 1, '_');
	fill_array((char *)footer, FOOTER_COUNT, 1, ' ');
	fill_array((char *)d_color, COUNT, COUNT + 1, C_GRAY);
	for (int i = 0; i < 26; i++)
		acolor[i] = 0;
}

int	wloop(	char dict[MAX_WORD_COUNT][COUNT + 1],
				char display[COUNT + 1][COUNT],
				char d_color[COUNT + 1][COUNT],
				char guess[COUNT + 1],
				char acolor[26],
				char *solution,
				int	*ln)
{
	int			i;

	i = 0;
	init_arrays(dict, display, d_color, acolor);
	*ln = import_dict("src/words.txt", dict);
	if (!*ln)
	{
		printf("Error reading dictionary.");
		exit(1);
	}
	solution = dict[rand_idx(*ln)];
	for (int i = 0; i < COUNT + 1; i++)
		solution[i] = toupper(solution[i]);
	update_footer("Please enter a 5-letter word.");
	refresh_screen(*ln, display, footer, d_color, acolor);
	while (i < COUNT + 1)
	{
		int c = get_input(guess, i);
		if (c == -10)
		{
			refresh_screen(*ln, display, footer, d_color, acolor);
			exit(0);
		}
		if (!c)
		{
			refresh_screen(*ln, display, footer, d_color, acolor);
			continue ;
		}
		if (c == -8)
		{
			update_footer(solution);
			refresh_screen(*ln, display, footer, d_color, acolor);
			continue;
		}
		if (!is_in_dictionary(guess, dict, *ln))
		{
			update_footer("Sorry, word is not in the dictionary. Try again.");
			refresh_screen(*ln, display, footer, d_color, acolor);
			continue;
		}
		else if (c == -1)
		{
			printf("Program Error. Couldn't read input.");
			exit(1);
		}
		strncpy((char *)display[i], guess, 5);
		update_color(solution, guess, d_color[i], acolor);
		if (strncmp(solution, guess, 5) == 0)
		{
			update_footer("CONGRATULATIONS! YOU WON! TRY AGAIN? (Y/N)");
			refresh_congrat(*ln, display, footer, d_color, acolor);
			return (0);
		}
		refresh_screen(*ln, display, footer, d_color, acolor);
		i++;
	}
	char s[50];
	sprintf(s, "[Solution: %s] SORRY YOU LOST!!! TRY AGAIN? (Y/N)", solution);
	update_footer(s);
	refresh_looser(*ln, display, footer, d_color, acolor);
	return (0);
}

int main(void)
{
	char		dict[MAX_WORD_COUNT][COUNT + 1];
	char		display[COUNT + 1][COUNT];
	char		d_color[COUNT + 1][COUNT];
	char		guess[COUNT + 1];
	char		acolor[26] = {0};
	char		*solution;
  	char	    answer[100] ={0};
	int			ln;

	solution = NULL;
	wloop(dict, display, d_color, guess, acolor, solution, &ln); 
	while (1)
	{
		int c = scanf("%s", answer);
		if (c == -1)
		{
			exit(0);
		}
		if(strlen(answer) != 1 || (answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] != 'N'))
		{
			clear_input_buffer();
            update_footer("Wrong input! Please press Y for yes or N for no!");
			refresh_screen(ln, display, footer, d_color, acolor);
			continue ;
		}
		if (*answer == 89 || *answer == 121)
		{
			clear_input_buffer();
			wloop(dict, display, d_color, guess, acolor, solution, &ln); 
			update_footer("Thanks for playing again. Choose a word.");
		}
        else if (*answer == 78 || *answer == 110)
            break ;
        else
            update_footer("Wrong input! Please press Y for yes or N for no!");
	}
}
