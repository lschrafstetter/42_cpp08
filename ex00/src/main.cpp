/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:08:40 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/21 15:33:05 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) {
  std::vector<int> v = { 1, 0, 2, 0, 3, 0, 4 };
  std::cout << *easyfind(v, 3) << std::endl;
  std::cout << *(easyfind(v, 0)++) << std::endl << std::endl;

  std::list<int> l = { 1, 0, 2, 0, 3, 0, 4 };
  std::cout << *easyfind(l, 3) << std::endl;
  std::cout << *(easyfind(l, 0)++) << std::endl;
}