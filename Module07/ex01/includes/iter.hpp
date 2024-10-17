/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:08:27 by miheider          #+#    #+#             */
/*   Updated: 2024/10/16 13:32:06 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

template <typename T>
void    iter(T* addr, int length, void (*func)(T& test))
{
    if (addr == NULL || func == NULL)
        return ;
    for (int i = 0; i < length; i++)
        func(addr[i]);
}

template <typename T>
void    iter(T* addr, int length, void (*func)(const T& test))
{
    if (addr == NULL || func == NULL)
        return ;
    for (int i = 0; i < length; i++)
        func(addr[i]);
}
