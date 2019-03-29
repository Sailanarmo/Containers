#include <iostream>
#include <string>
#include <type_traits>

// Needed for T,size_t
#include <array>

// Single template <T>
#include <vector>
#include <deque>
#include <queue> //has std::queue and std::priority_queue
#include <forward_list>
#include <list>
#include <stack>
#include <set> //has std::set and std::multiset
#include <unordered_set> //has std::unordered_set and std::unordered_multiset


// Double Template <T,U>
#include <map> //has std::map and std::multimap
#include <unordered_map> //has std::unordered_map and std::unordered_multimap

namespace containers
{

  #define ARR "array"
  #define VEC "vector"
  #define DEQ "deque"
  #define QUE "queue"
  #define PRQ "pQueue"
  #define FLI "fList"
  #define LIS "list"
  #define STK "stack"
  #define SET "set"
  #define MST "mSet"
  #define UST "unSet"
  #define UMS "unMSet"
  #define MAP "map"
  #define MMP "muMap"
  #define UMP "uMap"
  #define UMM "uMuMap"


  template<typename...>
  struct Cont; 
 
  template<typename T, typename U, U SIZE>
  struct Cont<T,std::integral_constant<U,SIZE>>
  {
    Cont(const std::string n) : name(n){}

    std::string name;
    std::array<T,SIZE> array;
  };

  template<typename T>
  struct Cont<T>
  {
    Cont(const std::string n) : name(n){}

    std::string name;

    std::vector<T>             vector;
    std::deque<T>              deque;
    std::queue<T>              queue;
    std::priority_queue<T>     priority_queue;
    std::forward_list<T>       forward_list;
    std::list<T>               list;
    std::stack<T>              stack;
    std::set<T>                set;
    std::multiset<T>           multiset;
    std::unordered_set<T>      unordered_set;
    std::unordered_multiset<T> unordered_multiset;
  };
  
  template<typename T, typename U>
  struct Cont<T,U>
  {
    Cont(const std::string n) : name(n){}

    std::string name;

    std::map<T,U>                map;
    std::multimap<T,U>           multimap;
    std::unordered_map<T,U>      unordered_map;
    std::unordered_multimap<T,U> unordered_multimap;
  };

  template<typename... T>
  Cont<T...> make_cont(const std::string name)
  {
    return { std::move(name) };
  }

  template<typename T,std::size_t SIZE>
  Cont<T,std::integral_constant<std::size_t,SIZE>> make_cont(const std::string name)
  {
    return { std::move(name) };
  }

  template<typename T>
  void printSingle(const T& p)
  {
    for(const auto & e: p)
    {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }

  template<typename T>
  void printQueue(T& q)
  {
    while(!q.empty())
    {
      auto p = q.front();
      std::cout << p << " ";
      q.pop(); 
    }
    std::cout << std::endl;
  }
  
  template<typename T>
  void printDeque(T& q)
  {
    while(!q.empty())
    {
      auto p = q.front();
      std::cout << p << " ";
      q.pop_front(); 
    }
    std::cout << std::endl;
  }
  
  template<typename T>
  void printStack(T& q)
  {
    while(!q.empty())
    {
      auto p = q.top();
      std::cout << p << " ";
      q.pop(); 
    }
    std::cout << std::endl;
  }

  template<typename T>
  void printMap(T& m)
  {
    for(const auto &e : m)
    {
      std::cout << "{ key: " << e.first << " value: " << e.second << " } ";
    }
    std::cout << std::endl;
  }
  
  template<typename T, typename U, U SIZE>
  void print(const Cont<T,std::integral_constant<U,SIZE>> &p)
  {
    std::cout << "Container name: " << p.name << std::endl;
    printSingle(p.array);
  }

  template<typename T>
  void print(Cont<T> &p,const std::string &MAC)
  {
    std::cout << "Container name: " << p.name << std::endl;

    if(MAC == VEC)
      printSingle(p.vector);

    if(MAC == DEQ)
    {
      auto cpyDeque = p.deque;
      printDeque(p.deque);
      p.deque = cpyDeque;
    }
    if(MAC == QUE)
    {
      auto cpyQueue = p.queue;
      printQueue(p.queue);
      p.queue = cpyQueue;
    }
    if(MAC == PRQ)
    {
      auto cpyPriority = p.priority_queue;
      printStack(p.priority_queue);
      p.priority_queue = cpyPriority;
    }
    if(MAC == FLI)
      printSingle(p.forward_list);
    if(MAC == LIS)
      printSingle(p.list);
    if(MAC == STK)
    {
      auto cpyStack = p.stack;
      printStack(p.stack);
      p.stack = cpyStack;
    }
    if(MAC == SET)
      printSingle(p.set);
    if(MAC == MST)
      printSingle(p.multiset);
    if(MAC == UST)
      printSingle(p.unordered_set);
    if(MAC == UMS)
      printSingle(p.unordered_multiset); 
    
  }
  
  template<typename T, typename U>
  void print(const Cont<T,U> &p, const std::string &MAC)
  {
    std::cout << "Container name: " << p.name << std::endl;

    if(MAC == MAP)
      printMap(p.map);
    if(MAC == MMP)
      printMap(p.multimap);
    if(MAC == UMP)
      printMap(p.unordered_map);
    if(MAC == UMM)
      printMap(p.unordered_multimap);
  }
  
}
