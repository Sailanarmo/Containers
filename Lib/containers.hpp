#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <string>
#include <iostream>

#include "type.hpp"
#include "is_container.hpp"

namespace container
{
  // Helper from is_container
  template<typename T> 
  struct is_container : std::integral_constant<bool, has_const_iterator<T>::value && has_begin_end<T>::beg_value && has_begin_end<T>::end_value> { };


  // Sets up struct so we can test if the template parameter is a container
  template<typename T, typename Enable = void>
  struct Cont;

  // checks if T is a container, if it is not, it will throw a compiler error
  template <typename T>
  struct Cont<T, std::enable_if_t<is_container<T>::value>> : public T
  {
    Cont(const std::string &n) : name(n) {}
    std::string name;
  };

  // gives the ability to create a container with auto
  template<typename T>
  Cont<T> make_cont(const std::string &name)
  {
    return { name };
  }

  // prints a single value
  template <typename T>
  std::string printIt(const T &val)
  {
    return (std::to_string(val) + " ");
  }

  // prints values from a map
  template <typename T, typename U>
  std::string printIt(const std::pair<T,U> &val)
  {
    return ("{key: " + std::to_string(val.first) + " value: " + std::to_string(val.second) + "} ");
  }

  // base print function
  template <typename T>
  void print(const Cont<T> &p)
  {
    std::cout << "Container name: " << p.name << std::endl;
    //std::cout << "Container type: " << type_name<decltype(p)>() << std::endl; //uncomment if you want the type
    std::cout << "Container Contents: " << std::endl;

    for(const auto &e: p)
    {
      std::cout << printIt(e);
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }
}
#endif
