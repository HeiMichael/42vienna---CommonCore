/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:16:25 by miheider          #+#    #+#             */
/*   Updated: 2023/09/16 10:16:35 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_list
{
	void	*content;
	struct	s_list	*next;
}	t-list;


t_list	*ft_lstnew(void *content)
{
	t_list	*new_node

	new_node = (t_list *)malloc(sizeof(*new_node))
	if (new_node = NULL)
		return;
	
	new_node->next = NULL;				//Abfrage if(start==NULL)???????????
	new_node->content = content;
}

int	main(void)
{




}
