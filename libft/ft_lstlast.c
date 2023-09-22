/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:45:19 by miheider          #+#    #+#             */
/*   Updated: 2023/09/22 13:13:37 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_lstlast(t_list *lst)
{
	if (*lst == NULL)
		return (NULL);
	while (lst != '\0')
	{	
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
