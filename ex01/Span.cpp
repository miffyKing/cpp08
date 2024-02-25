#include "Span.hpp"

Span::Span() : _vector(0, 0)
{
  this->_vector.reserve(0);
}

Span::Span(unsigned int N) : _vector(0, 0)
{
  this->_vector.reserve(N);
}

// Span::Span()
// {
//     _vector = {}; // c++ 11
// }

// Span::Span(unsigned int N)
// {
//     _vector = std::vector<int>(N, 0);
// }

Span::Span(const Span &ref)
{
  *this = ref;
}

Span &Span::operator=(const Span &ref)
{
  if (this != &ref)
  {
    this->_vector.reserve(ref.getVector().capacity());
    if (this->_vector.capacity() != 0)
      std::copy(ref.getVector().begin(), ref.getVector().end(), std::back_inserter(this->_vector));
  }
  return *this;
}

Span::~Span()
{
  this->_vector.clear();
}

/////////////////

void Span::addNumber(int num)
{
  if (this->_vector.size() >= this->_vector.capacity())
    throw CanNotStoreNumber();
  else
    this->_vector.push_back(num);
}

const std::vector<int> &Span::getVector() const
{
  return this->_vector;
}

long Span::shortestSpan()
{
  if (this->_vector.size() <= 1)
    throw NotEnoughElement();
  std::vector<int> sortedVector = this->getVector();
  std::sort(sortedVector.begin(), sortedVector.end());
  std::vector<int>::iterator iter = sortedVector.begin() + 1;
  long returnValue = std::abs(*iter - *(iter - 1));
  while (iter != sortedVector.end())
  {
    if (returnValue >= std::abs(*iter - *(iter - 1)))
      returnValue = std::abs(*iter - *(iter - 1));
    ++iter;
  }
  return returnValue;
}

long Span::longestSpan()
{
  if (this->_vector.size() <= 1)
    throw NotEnoughElement();
  std::vector<int> sortedVector = this->getVector();
  std::sort(sortedVector.begin(), sortedVector.end());
  return static_cast<long>(static_cast<long>(sortedVector.back()) - static_cast<long>(sortedVector.front()));
}

const char *Span::CanNotStoreNumber::what() const throw()
{
  return "Span array size is full.. cant store more number..";
}

const char *Span::NotEnoughElement::what() const throw()
{
  return "element too few. Can't calculate span.";
}
