/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiochal < sgiochal@student.42vienna.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:14 by sgiochal          #+#    #+#             */
/*   Updated: 2023/11/12 18:18:55 by sgiochal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <ctype.h>
# include <signal.h>

# define COUNT 5
# define MAX_WORD_COUNT 13000
# define FOOTER_COUNT 65

# define C_GRAY 30
# define C_GREEN 32
# define C_ORANGE 33 

void 		clear_input_buffer();
void		update_color(char *solution, char *guess, char *color, char acolor[26]);
void		print_display(char display[COUNT + 1][COUNT], char d_color[COUNT + 1][COUNT]);
void		print_footer(char footer[FOOTER_COUNT]);
void		print_congrat(char footer[FOOTER_COUNT]);
void		print_looser(char footer[FOOTER_COUNT]);
int			is_in_dictionary(const char *str, char dict[MAX_WORD_COUNT][COUNT + 1], int dict_len);
void		clear_screen();
void		print_intro();
int			rand_idx(int max_index);
void		update_footer(const char *str);
int			is_valid(const char *str);
void		fill_array(char *array, int columns, int rows, char c);
void		print_alphabet(char acolor[26]);

#endif
