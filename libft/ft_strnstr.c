/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:36:41 by miheider          #+#    #+#             */
/*   Updated: 2023/09/15 10:38:54 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*string;
	char	*small;
	size_t	i;
	size_t	a;

	string = (char *)big;
	small = (char *)little;
	if (*small == '\0')
		return (string);
	a = ft_strlen(small);
	if (ft_strlen(string) < a || len <= 0 || a == 0)
		return (NULL);
	i = 0;
	while (((i + a) <= len) && string[i] != '\0')
	{
		if (string[i] == small[0])
		{
			string = &string[i];
			if (ft_strncmp(string, small, a) == 0)
				return (string);
			else if (ft_strncmp(string, small, a) != 0)
				i++;
		}
		else
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	char big[] = "aaabcabcd";
	char little[] = "abcd";
	int    len = 9;

	printf("%s", ft_strnstr(big, little, len));
//    printf("\n%s", strnstr(big, little, len));
	return (0);
}*/
