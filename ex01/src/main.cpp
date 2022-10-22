/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:08:40 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/22 12:07:11 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
  // Deep copy test
  {
    std::cout << GREEN << "----- testing for deep copy -----" << std::endl;
    Span span(5);
    span.addNumber(42);

    std::cout << "Original Span:" << std::endl;
    span.printContents();

    std::cout << std::endl << "*copying and assigning*" << std::endl;
    Span copy(span);
    Span assigned;
    assigned = span;

    std::cout << std::endl
              << "*adding another number to original Span*" << std::endl;
    span.addNumber(21);

    std::cout << std::endl << "Span afer:" << std::endl;
    span.printContents();
    std::cout << std::endl << "Copy afer:" << std::endl;
    copy.printContents();
    std::cout << std::endl << "Assigned afer:" << std::endl;
    assigned.printContents();
    std::cout << std::endl << std::endl;
  }

  // Capacity exceptions and simple Span tests
  {
    std::cout << RED << "----- Out of capacity test -----" << std::endl;
    Span span(10);
    for (int i = 0; i < 12; i++) {
      try {
        span.addNumber(i);
        std::cout << "added " << i << " to span" << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
    }
    std::cout << YELLOW << std::endl << "----- Spans: -----" << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }

  // Testing NoSpanPossibleException
  {
    std::cout << BLUE << std::endl
              << "----- 'No Span possible' test -----" << std::endl;
    Span span_empty;
    Span span_size_1(1);
    span_size_1.addNumber(42);
    try {
      span_empty.shortestSpan();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      span_empty.longestSpan();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      span_size_1.shortestSpan();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      span_size_1.longestSpan();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  
  // BIG NUMBERS (fillSpan test)
  {
    std::cout << MAGENTA << std::endl
              << "----- Adding a range of numbers -----" << std::endl;
    Span span(300);
    std::vector<int> vector;
    
    for (int i = 1000; i < 1100; i++) {
      try {
        span.addNumber(i);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
    }
    
    for (int i = -500; i < -400; i++) {
      vector.push_back(i);
    }
    
    try {
      span.fillSpan(vector.begin(), vector.end());
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    
    try {
      std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
      std::cout << "Longest span: " << span.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  // Ridiculous numbers test
  {
    std::cout << CYAN << std::endl
              << "----- Ridiculous pdf test -----" << std::endl;
    std::vector<int> vector;
    Span span(10001);

    srand(1);
    std::cout << "Adding 10001 numbers to vector" << std::endl;
    for (int i = 0; i < 10001; i++) {
      try {
        vector.push_back(rand());
      } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
      }
    }
    std::cout << "Adding 10001 numbers to vector complete" << std::endl;
    std::cout << "Adding vector to span" << std::endl;

    try {
      span.fillSpan(vector.begin(), vector.end());
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "Adding vector to span complete" << std::endl;
    // uncomment at own risk
    // span.printContents();
    try {
      std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
      std::cout << "Longest span: " << span.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}