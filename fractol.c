/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:42:32 by miheider          #+#    #+#             */
/*   Updated: 2023/11/16 18:54:43 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	a;

	if (!s || !*s)
		return (0);
	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		a;
	char	*dupl;

	a = ft_strlen(s);
	dupl = malloc(sizeof(char) * a + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i < a)
	{
		dupl[i] = s[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol	red_thread;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) ||
		(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		red_thread.name = ft_strdup(argv[1]);
		init(&red_thread);
					// if true --> jump into programm;
					//++ --> initialisieren (connectin, window)
					//++ --> berechnen
					// --> darstellen
					//++ --> events
	}
	else
					//ERROR-MESSAGE + EXIT
	//2. berechnen&ausgeben:
	//if (argv[1] == mandelbrot)
	//	mandelbrot();
	//else
	//	julia();
	//3. events:
	events(&red_thread);

}
