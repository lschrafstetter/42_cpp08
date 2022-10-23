/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:10:01 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/23 16:51:08 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  // Canonical Form
  MutantStack() {}
  MutantStack(const MutantStack &copy) { *this = copy; }
  virtual ~MutantStack() {}
  MutantStack &operator=(const MutantStack &other) {
    std::stack<T>::operator=(other);
    return *this;
  }

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

  iterator begin(void) { return (std::stack<T>::c.begin()); }
  iterator end(void) { return (std::stack<T>::c.end()); }
  const_iterator begin(void) const { return (std::stack<T>::c.begin()); }
  const_iterator end(void) const { return (std::stack<T>::c.end()); }
  reverse_iterator rbegin(void) { return (std::stack<T>::c.rbegin()); }
  reverse_iterator rend(void) { return (std::stack<T>::c.rend()); }
  const_reverse_iterator rbegin(void) const { return (std::stack<T>::c.rbegin()); }
  const_reverse_iterator rend(void) const { return (std::stack<T>::c.rend()); }
};

#endif