/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:45:34 by miheider          #+#    #+#             */
/*   Updated: 2023/09/22 19:22:44 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if (!lst || !del)
		return;
	while (*lst)			//loop over list
	{
		save = (*lst)->next;   //point to the next element
		ft_lstdelone(*lst, del);   //fctn on current element
		*lst = save;       //pointer to next element
	}
	free(*lst);
}

