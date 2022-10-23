/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:08:40 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/23 18:17:29 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>

int main(void) {  
  std::cout << YELLOW << "----- original stack -----" << std::endl;

  std::stack<int> stack;
  
  std::cout << "*pushing and popping some stuff*" << std::endl;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.pop();
  stack.push(5);
  std::cout << "Emptying stack from top to bottom:" << std::endl;
  while (!stack.empty()) {
    std::cout << stack.top() << std::endl;
    stack.pop();
  }

  std::cout << GREEN << "----- mutant stack -----" << std::endl;
  
  MutantStack<int> mutant_stack;

  std::cout << "*pushing and popping some stuff*" << std::endl;
  mutant_stack.push(1);
  mutant_stack.push(2);
  mutant_stack.push(3);
  mutant_stack.push(4);
  mutant_stack.pop();
  mutant_stack.push(5);
  std::cout << "Now iterable, much wow!" << std::endl;
  for (MutantStack<int>::iterator it = mutant_stack.begin(); it != mutant_stack.end(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout << "Printed everything and it is not empty. Amazing!" << std::endl;
  std::cout << "Emptying stack from top to bottom:" << std::endl;
  while (!mutant_stack.empty()) {
    std::cout << mutant_stack.top() << std::endl;
    mutant_stack.pop();
  }
  return 0;
}