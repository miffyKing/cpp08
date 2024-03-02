#ifndef easy_HPP
#define easy_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T a, int b)
{

  // for (typename T::size_type i = 0; i < a.size(); i++)
  // {
  //   if (a[i] == b)
  //   {
  //     std::cout << "found b in " << i << "\n";
  //     return;
  //   }
  // }
  if (std::find(a.begin(), a.end(), b) != a.end())
  {
    std::cout << "found b"
              << "\n";
    return;
  }
  throw std::out_of_range("Element not found");
}

#endif