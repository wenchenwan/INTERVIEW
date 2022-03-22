/**
 * @file templateCpp2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>

template <typename T>
T my_max(T value) {
  return value;
}

template <typename T, typename... Types>
T my_max(T value, Types... args) {
  return std::max(value, my_max(args...));
}

int main(int argc, char *argv[]) {
  std::cout << my_max(1, 5, 8, 4, 6) << std::endl;

	return 0;
}