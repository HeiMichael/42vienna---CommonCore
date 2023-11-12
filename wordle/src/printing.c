/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiochal < sgiochal@student.42vienna.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:22:06 by sgiochal          #+#    #+#             */
/*   Updated: 2023/11/12 20:09:50 by sgiochal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

extern char		footer[FOOTER_COUNT];

void	print_display(char display[COUNT + 1][COUNT], char d_color[COUNT + 1][COUNT])
{	
	int foreColorR = 255;  // Red value for foreground color
	int foreColorG = 255;    // Green value for foreground color
	int foreColorB = 255;    // Blue value for foreground color
	int bgColorR = 0;      // Red value for background color
	int bgColorG = 0;    // Green value for background color
	int bgColorB = 0;      // Blue value for background color

	for (int i = 0; i < COUNT + 1; i++)
	{
		printf("                         ");
		for (int j = 0 ; j < COUNT; j++)
		{
			foreColorR = 255;  // Red value for foreground color
			foreColorG = 255;    // Green value for foreground color
			foreColorB = 255;    // Blue value for foreground color
			bgColorR = 0;      // Red value for background color
 			bgColorG = 0;    // Green value for background color
 			bgColorB = 0;      // Blue value for background color
			switch(d_color[i][j])
			{
				case C_GRAY:
					bgColorR = 20; bgColorG = 20;	bgColorB = 20;
					foreColorR = 160; foreColorG = 160; foreColorB = 160;
					break;
				case C_GREEN:
					bgColorR = 0; bgColorG = 100; bgColorB = 0;
					break;
				case C_ORANGE:
					bgColorR = 160; bgColorG = 120; bgColorB = 0;
					break;
				default:
					;
			}
			printf("\033[38;2;%d;%d;%dm", foreColorR, foreColorG, foreColorB); // Set foreground color
   		 	printf("\033[48;2;%d;%d;%dm", bgColorR, bgColorG, bgColorB); // Set background color
			printf("%c\033[0m ", display[i][j]);
		}
		printf("\n");
	}
}

void	print_footer(char footer[FOOTER_COUNT])
{
	printf("---------------------------------------------------------------\n");
    printf("%-61s\n", footer);
    printf("---------------------------------------------------------------\n");
}

void	print_congrat(char footer[FOOTER_COUNT])
{
	if (system("play sounds/win.mp3 >/dev/null 2>&1 &") != 0)
	{
		printf("Error playing sound. Exiting");
		exit(1);
	}
	printf("🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳\n");
    printf("🥳%-60s🥳\n", footer);
	printf("🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳\n");
}

void	print_looser(char footer[FOOTER_COUNT])
{
	if(system("play sounds/fail.mp3 >/dev/null 2>&1 &") != 0)
	{
		printf("Error playing sound. Exiting");
		exit(1);
	}
	printf("😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭\n");
    printf("😭%-60s😭\n", footer);
	printf("😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭\n");
}

void	clear_screen()
{
	printf("\033[2J");	
	printf("\033[1;1H");
}

void	print_intro()
{
	clear_screen();
	printf("           .---.                             ,--,              \n");
	printf("          /. ./|                      ,---,,--.'|              \n");
	printf("      .--'.  ' ;  ,---.    __  ,-.  ,---.'||  | :              \n");
	printf("     /__./ \\ : | '   ,'\\ ,' ,'/ /|  |   | ::  : '             \n");
	printf(" .--'.  '   \\' ./   /   |'  | |' |  |   | ||  ' |      ,---.   \n");
	printf("/___/ \\ |    ' '.  ; ,. :|  |   ,',--.__| |'  | |     /     \\ \n");
	printf(";   \\  \\;      :'  | |: :'  :  / /   ,'   ||  | :    /    /  | \n");
	printf("\\   ;  `      |'   | .; :|  | ' .   '  /  |'  : |__ .    ' / | \n");
	printf(" .   \\    .\\  ;|   :    |;  : | '   ; |:  ||  | '.'|'   ;   /| \n");
	printf("  \\   \\   ' \\ | \\   \\  / |  , ; |   | '/  ';  :    ;'   |  / | \n");
	printf("   :   '  |--\"   `----'   ---'  |   :    :||  ,   / |   :    | \n");
	printf("    \\   \\ ;                      \\   \\  /   ---`-'   \\   \\  /  \n");
	printf("     '---\"                        `----'              `----'   \n");
	printf("          by Michael Heider and Spyridon Giochalas\n");
}

void	print_alphabet(char acolor[26])
{
	int foreColorR = 255;  // Red value for foreground color
	int foreColorG = 255;    // Green value for foreground color
	int foreColorB = 255;    // Blue value for foreground color
	int bgColorR = 25;      // Red value for background color
	int bgColorG = 25;    // Green value for background color
	int bgColorB = 25;      // Blue value for background color
	char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N', \
					'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	printf("\n     ");
	for (int i = 0; i < 26; i++)
	{
		foreColorR = 255;  // Red value for foreground color
		foreColorG = 255;    // Green value for foreground color
		foreColorB = 255;    // Blue value for foreground color
		bgColorR = 25;      // Red value for background color
		bgColorG = 25;    // Green value for background color
		bgColorB = 25;      // Blue value for background color
		switch(acolor[i])
		{
			case C_GRAY:
				bgColorR = 20; bgColorG = 20;	bgColorB = 20;
				foreColorR = 70; foreColorG = 70; foreColorB = 70;
				break;
			case C_GREEN:
				bgColorR = 0; bgColorG = 100; bgColorB = 0;
				break;
			case C_ORANGE:
				bgColorR = 160; bgColorG = 120; bgColorB = 0;
				break;
			default:
				;
		}
		printf("\033[38;2;%d;%d;%dm", foreColorR, foreColorG, foreColorB); // Set foreground color
		printf("\033[48;2;%d;%d;%dm", bgColorR, bgColorG, bgColorB); // Set background color
		printf("%c\033[0m ", alpha[i]);
	}
	//printf("\n");
}