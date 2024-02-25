#include <iostream>
#include <vector>
#include "Span.hpp"
#include <limits.h>
#include <list>
int main()
{
  try
  {
    Span sp = Span(7);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    sp.addNumber(INT_MAX);
    sp.addNumber(INT_MIN);
    std::cout << "Difference between int_max and int_min: " << sp.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  std::cout << "===================================================\n";
  try
  {
    // add a lot of numbers
    Span sp3 = Span(12000);
    std::cout << "Before addManyNumbers - sp3.size : " << sp3.getVector().size() << ", sp3.capacity : " << sp3.getVector().capacity() << std::endl;
    std::vector<int> v;
    for (int num = 0; num < 12000; ++num)
    {
      v.push_back(num);
    }
    sp3.addManyNumbers(v);
    std::cout << "After addManyNumbers - sp3.size : " << sp3.getVector().size() << ", sp3.capacity : " << sp3.getVector().capacity() << std::endl;

    std::cout << "sp3 [0 - 9] iter :";
    for (std::vector<const int>::iterator iter = sp3.getVector().begin(); iter < sp3.getVector().begin() + 10; ++iter)
      std::cout << " " << *iter;

    std::cout << std::endl
              << "sp3 [11990 - 11999] iter :";

    for (std::vector<const int>::iterator iter = sp3.getVector().end() - 10; iter < sp3.getVector().end(); ++iter)
      std::cout << " " << *iter;
    std::cout << std::endl;

    sp3.addNumber(12000); // 여기서 터져야해요.
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  std::cout << "===================================================\n";

  try
  {
    // input list to Span and get vector
    Span sp3 = Span(12);
    std::cout << "Before addManyNumbers - sp3.size : " << sp3.getVector().size() << ", sp3.capacity : " << sp3.getVector().capacity() << std::endl;

    std::list<int> lst;
    for (int num = 0; num < 12; ++num)
    {
      lst.push_back(num);
    }

    sp3.addManyNumbers(lst);
    std::vector<int> retList = sp3.getVector();
    for (int i = 0; i < (int)retList.size(); i++)
    {
      std::cout << retList[i] << " ";
    }

    // std::cout << retList[0] << "\n";
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}