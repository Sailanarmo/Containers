#include "containers.hpp"

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

int main()
{
  auto myArray = containers::make_cont<int,4>("myArray");
  myArray.array = {1,2,3,4};
  print(myArray);

  auto myMap = containers::make_cont<int,int>("myMap");
  myMap.unordered_map[0] = 3;
  print(myMap, UMP);

  auto myList = containers::make_cont<int>("myList");
  myList.list = {1,2,3,4};
  print(myList, LIS);
}
