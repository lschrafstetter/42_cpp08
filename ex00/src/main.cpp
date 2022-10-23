/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:08:40 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/23 20:00:14 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(0);
  v.push_back(2);
  v.push_back(0);
  v.push_back(3);
  v.push_back(0);
  v.push_back(4);
  std::cout << *easyfind(v, 3) << std::endl;
  std::cout << *(++easyfind(v, 0)) << std::endl << std::endl;

  std::list<int> l;
  l.push_back(1);
  l.push_back(0);
  l.push_back(2);
  l.push_back(0);
  l.push_back(3);
  l.push_back(0);
  l.push_back(4);
  std::cout << *easyfind(l, 3) << std::endl;
  std::cout << *(++easyfind(l, 0)) << std::endl;
}