#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
  std::vector<int> arr;
  arr.push_back(1);
  arr.push_back(-1);
  arr.push_back(3);
  arr.push_back(5);

  try
  {
    easyfind(arr, 11);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << "\n";
  }

  try
  {
    easyfind(arr, 3);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << "\n";
  }
  int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::deque<int> deq(arr2, arr2 + 10);
  std::list<int> list(arr2, arr2 + 10);

  try
  {
    easyfind(deq, 1);
    easyfind(deq, 11);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << "\n";
  }

  try
  {
    easyfind(list, 1);
    easyfind(list, 11);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << "\n";
  }

  return 0;
}
