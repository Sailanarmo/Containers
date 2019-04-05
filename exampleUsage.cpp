#include "Lib/containers.hpp"

#include <array>
#include <vector>
#include <unordered_map>
#include <deque>

int main()
{
  
  // TODO: Figure out how to do assignment, ex: myArray = {1,2,3,4,5} does 
  //       not compile currently, however if you have a std::array<int,5>
  //       then you can do assignment. So maybe figure out how to overload
  //       the assignment operator for easy testing.
  
  container::Cont<std::array<int,5>> myArray("myArray");
  container::Cont<std::unordered_map<int,int>> myMap("myMap");
  container::Cont<std::deque<int>> myQueue("myQueue");

  auto myVector = container::make_cont<std::vector<int>>("myVector");
 
  myQueue.push_back(1); 
  myQueue.push_back(2); 
  myQueue.push_back(3); 
  
  myVector.push_back(1);
  myVector.push_back(2);
  myVector.push_back(3);
  
  for(int i = 0; i < myArray.size();++i)
  {
    myArray[i] = i;
  }

  myMap[0] = 10;
  myMap[1] = 11;
  myMap[2] = 12;

  std::cout << myVector << std::endl;
  std::cout << myArray << std::endl;
  std::cout << myMap << std::endl;
  std::cout << myQueue << std::endl;
}
