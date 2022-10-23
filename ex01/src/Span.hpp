/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:37:45 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/22 17:33:34 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

#define DEFAULT "\033[39m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Span {
 public:
  // Canonical form
  Span();
  Span(int size);
  Span(const Span &copy);
  ~Span();
  Span &operator=(Span other);

  // Getters & Setters
  int size(void) const;

  // Functions
  void addNumber(const int &number);
  void printContents(void) const;
  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const;
  void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while (begin < end) {
      try {
        this->addNumber(*begin);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      begin++;
    }
  }

  // Exceptions
  class OutOfCapacityException : public std::exception {
   public:
    const char *what() const throw();
  };
  class NoSpanPossibleException : public std::exception {
   public:
    const char *what() const throw();
  };

 private:
  std::vector<int> contents_;
  uint size_;
};

#endif