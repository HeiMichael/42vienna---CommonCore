/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:31:25 by miheider          #+#    #+#             */
/*   Updated: 2024/10/14 17:36:01 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void    easyfind(T& vec, int target) {
    typename T::iterator iterator = std::find(vec.begin(), vec.end(), target);
    if (iterator != vec.end())
        std::cout << "Target " << target << " found" << std::endl;
    else
        throw NumberNotFoundException();
}

const char* NumberNotFoundException::what() const throw() {
    return "No occurence found";
}
