#include<iostream>
#include<vector>

/* 
C++11 introduces a new form of for loop, which iterates over all elements of a given range, array or collection. It's what in other programming languages would be called a foreach loop. The general syntax is as follows. 

  for( decl : coll ) {
    statement
  }

 */

template<typename T>
void printElements(const T& coll)
{
  for(const auto& e: coll)
  {
    std::cout<<e<<"\n";
  }
}

int main()
{
  for(int i : {2,3,5,7,11,13,17,19})
    std::cout<<i<<"\n";
  std::vector<int> vec= {1,1,1,1,1};
  for(auto& e: vec)
    std::cout<<e*3<<"\n";

    int array[] = {1,2,3,4,5,6};

    long sum = 0;
    for (int x:array)
      sum+=x;
    for(auto e: {sum, sum*2, sum*4})
    {
      std::cout<<e<<"\n";
    }

    

}