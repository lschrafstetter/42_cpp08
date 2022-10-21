/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:13:50 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/21 15:29:48 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, const int &target) {
  typename T::iterator it = std::find(container.begin(), container.end(), target);
  return it;
}