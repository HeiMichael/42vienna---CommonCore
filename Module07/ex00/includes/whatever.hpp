/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:08:27 by miheider          #+#    #+#             */
/*   Updated: 2024/10/08 09:50:03 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void   swap (T &x, T &y) {
    T   temp;

    temp = x;
    x = y;
    y = temp;
}

template <typename T>
T   min (T const& x, T const& y) {
    if (x < y)
        return x;
    else
        return y;
}

template <typename U>
U   max (U const& x, U const& y) {
    if (x > y)
        return x;
    else
        return y;
}
