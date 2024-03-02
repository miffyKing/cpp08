#ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Span
{
private:
  std::vector<int> _vector;

  Span();

public:
  Span(unsigned int N);
  Span(const Span &ref);
  Span &operator=(const Span &ref);
  ~Span();

  long shortestSpan();
  long longestSpan();
  const std::vector<int> &getVector() const;

  void addNumber(int num);

  template <typename T>
  void addManyNumbers(T &container);

  class CanNotStoreNumber : public std::exception
  {
  public:
    const char *what() const throw();
  };

  class NotEnoughElement : public std::exception
  {
  public:
    const char *what() const throw();
  };
};

template <typename T>
void Span::addManyNumbers(T &container)
{
  if (std::distance(container.begin(), container.end()) > static_cast<int>(this->_vector.capacity() - this->_vector.size()))
    throw CanNotStoreNumber();
  typename T::iterator iter = container.begin();
  while (iter != container.end())
  {
    this->_vector.push_back(*iter);
    ++iter;
  }
}
#endif
