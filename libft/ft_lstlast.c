/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:29:00 by miheider          #+#    #+#             */
/*   Updated: 2023/09/16 10:36:56 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		lst = lst->next;
	}
	return (len);
}
if (*lst == NULL)
	*lst = new;
else
	new->next = *lst;
*lst = new;
}