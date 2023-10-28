/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:43:35 by miheider          #+#    #+#             */
/*   Updated: 2023/09/30 09:35:07 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<limits.h>
#include "ft_printf.h"

int main(void)
{
	int		x;
	int		y;
	char	a;
	char	b[] = "First string test!";
	char	c[] = "";
	char	d[] = "%$/RT fgh h%&/ \n \\t";
	int		e;
	unsigned int	f;
	void	*g;
	char	h[] = "Heeeaavyyy!%";
	
	x = 0;
	y = 0;
	printf("\033[0;29m--------------- TEST 1 --- simple string ---------------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("First Test!");
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("First Test!");
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("");
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("");
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	 
	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("In the radio series and the first novel, a group of hyper-intelligent pan-dimensional beings demand to learn the Answer to the Ultimate Question of Life, The Universe, and Everything from the supercomputer Deep Thought, specially built for this purpose. It takes Deep Thought 7+1⁄2 million years to compute and check the answer, which turns out to be 42. Deep Thought points out that the answer seems meaningless because the beings who instructed it never knew what the question was.");
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("In the radio series and the first novel, a group of hyper-intelligent pan-dimensional beings demand to learn the Answer to the Ultimate Question of Life, The Universe, and Everything from the supercomputer Deep Thought, specially built for this purpose. It takes Deep Thought 7+1⁄2 million years to compute and check the answer, which turns out to be 42. Deep Thought points out that the answer seems meaningless because the beings who instructed it never knew what the question was.");
	printf("\t{%d}\n\t\t\t\t\t\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("Test!!!456&  §2Test!");
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("Test!!!456&  §2Test!");
	printf("\t{%d}\n\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 1 ---------------\n\n");

	x = 0;
	y = 0;
	a = 'l';
	printf("\033[0;29m--------------- TEST 2 --- character ---------------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%c", a);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%c", a);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	a = 'e';
	printf("\033[1;34mexpected: \n");
	x += printf("%c", a);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%c", a);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	a = 'Z';
	printf("\033[1;34mexpected: \n");
	x += printf("The character is: %c", a);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("The character is: %c", a);
	printf("\t{%d}\n\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 2 ---------------\n\n");


	x = 0;
	y = 0;
	printf("\033[0;29m--------------- TEST 3 --- string ---------------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%s", b);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%s", b);
	printf("\t{%d}\n\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%s", c);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%s", c);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%s", d);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%s", d);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 3 ---------------\n\n");

	x = 0;
	y = 0;
	e = -826423;
	printf("\033[0;29m--------------- TEST 4 --- integer ---------------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%d", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%d", e);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	e = 2147483647;
	printf("\033[1;34mexpected: \n");
	x += printf("%d", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%d", e);
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");

	x = 0;
	y = 0;
	e = -2147483648;
	printf("\033[1;34mexpected: \n");
	x += printf("%d", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%d", e);
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	e = -1;
	printf("\033[1;34mexpected: \n");
	x += printf("%d", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%d", e);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	e = 424242;
	printf("\033[1;34mexpected: \n");
	x += printf("%d", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%d", e);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	e = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%d", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%d", e);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 4 ---------------\n\n");
	
	x = 0;
	y = 0;
	printf("\033[0;29m--------------- TEST 5 --- %% ---------------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%%%%%%%%%%");
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%%%%%%%%%%");
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;

	printf("\033[1;34mexpected: \n");
	x += printf("What is this %% printing?%%");
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("What is this %% printing?%%");
	printf("\t{%d}\n\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 5 ---------------\n\n");
	
	x = 0;
	y = 0;
	f = 45789;
	printf("\033[0;29m--------------- TEST 6 --- unsigned int -----\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%u", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%u", e);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 4294967295;
	printf("\033[1;34mexpected: \n");
	x += printf("%u", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%u", f);
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%u", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%u", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 2147483647;
	printf("\033[1;34mexpected: \n");
	x += printf("%u", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%u", f);
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 475;
	printf("\033[1;34mexpected: \n");
	x += printf("%u", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%u", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 6 ---------------\n\n");
	
	x = 0;
	y = 0;
	f = 45789;
	printf("\033[0;29m--------------- TEST 7 --- hexa -------------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = -25478;
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 4294672;
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 11;
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 345678;
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 4294967295;
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 42672895;
	printf("\033[1;34mexpected: \n");
	x += printf("%x", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%x", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
		printf("\033[0;29m--------------- END --- TEST 7 ---------------\n\n");
	
	x = 0;
	y = 0;
	f = 45789;
	printf("\033[0;29m--------------- TEST 8 --- HEXA -------------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 4294672;
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 11;
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 345678;
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 4294967295;
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 42672895;
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	f = 31415;
	printf("\033[1;34mexpected: \n");
	x += printf("%X", f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%X", f);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 8 ---------------\n\n");	
		
	x = 0;
	y = 0;
	printf("\033[0;29m--------------- TEST 9 --- POINTER ----------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%p", &g);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%p", &g);
	printf("\t{%d}\n\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%p", (void *)-1);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%p", (void *)-1);
	printf("\t{%d}\n\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%p", (void *)0);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%p", (void *)0);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");	
	
	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("Kairo is located on the %p", (void *)0);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("Kairo is located on the %p", (void *)0);
	printf("\t{%d}\n\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("%p", (void *)11);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%p", (void *)11);
	printf("\t{%d}\n\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------- END --- TEST 9 ---------------\n\n");
	
	x = 0;
	y = 0;
	f = 4294995;
	printf("\033[0;29m-------------- TEST 10 --- GO CRAZY ---------\n\n");
	printf("\033[1;34mexpected: \n");
	x += printf("%c - %s - %i - %d - %u - %x - %X - %p - %%", a, b, e, 154, f, f, 68544389, &x);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("%c - %s - %i - %d - %u - %x - %X - %p - %%", a, b, e, 154, f, f, 68544389, &x);
	printf("\t{%d}\n\t\t\t\t\t\t\t\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	f = 1;
	printf("\033[1;34mexpected: \n");
	x += printf("numbers: %i - %d - %i - %d", 5235*354, f, (f + 3), f*f);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("numbers: %i - %d - %i - %d", 5235*354, f, (f + 3), f*f);
	printf("\t{%d}\n\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	printf("\033[1;34mexpected: \n");
	x += printf("     %     d   ", 5842*36);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("     %     d   ", 5842*36);
	printf("\t{%d}\n\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	f = 1;
	printf("\033[1;34mexpected: \n");
	x += printf("Heavy testing: %s", h);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("Heavy testing: %s", h);
	printf("\t{%d}\n\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
	
	x = 0;
	y = 0;
	e = 565874;
	printf("\033[1;34mexpected: \n");
	x += printf("     %     d   ", e);
	printf("\t{%d}\n", x);
	printf("\033[1;34moutput  : \n");
	y += ft_printf("     %     d   ", e);
	printf("\t{%d}\n\t\t\t\t", y);
	if (x == y)
		printf("\033[1;32m[OK]\n\n");
	else
		printf("\033[1;31m[KO †]\n\n");
		
	printf("\033[0;29m--------------------------------------------\n");
		
}
