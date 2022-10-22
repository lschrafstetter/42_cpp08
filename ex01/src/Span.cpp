/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:37:40 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/22 11:43:18 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical form
Span::Span() : size_(0) {}

Span::Span(int size) : size_(size) {}

Span::Span(const Span &copy) {
  this->size_ = copy.size();
  this->contents_ = copy.contents_;
}

Span::~Span() {}

Span &Span::operator=(Span other) {
  this->size_ = other.size();
  std::swap(this->contents_, other.contents_);
  return *this;
}

// Getters & Setters
int Span::size(void) const { return this->size_; }

// Functions
void Span::addNumber(const int &number) {
  if (this->contents_.size() < this->size_) {
    this->contents_.push_back(number);
    return;
  }
  throw OutOfCapacityException();
}

void Span::printContents(void) const {
  std::vector<int>::const_iterator it;
  std::vector<int>::const_iterator end = this->contents_.end();
  for (it = this->contents_.begin(); it < end; it++) {
    std::cout << *it << std::endl;
  }
}

unsigned int Span::shortestSpan(void) const {
  if (this->size_ < 2) throw NoSpanPossibleException();
  std::vector<int> tmp = this->contents_;
  std::sort(tmp.begin(), tmp.end());
  std::vector<int>::const_iterator it = tmp.begin();
  std::vector<int>::const_iterator end = tmp.end();
  unsigned int shortest = *(it + 1) - *it;
  for (++it; it < end; it++) {
    shortest = std::min(shortest, static_cast<unsigned int>(*(it + 1) - *it));
  }
  return shortest;
}

unsigned int Span::longestSpan(void) const {
  if (this->size_ < 2) throw NoSpanPossibleException();
  int max = *(std::max_element(this->contents_.begin(), this->contents_.end()));
  int min = *(std::min_element(this->contents_.begin(), this->contents_.end()));
  return max - min;
}

// Exceptions

const char *Span::OutOfCapacityException::what() const throw() {
  return "out of capacity";
}

const char *Span::NoSpanPossibleException::what() const throw() {
  return "no span possible";
}