#include <algorithm>
#include <iostream>
#include <vector>

void PrintFunc (int x) {
  std::cout << x << std::endl;
}

int main()
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  std::for_each(v.begin(), v.end(), PrintFunc);
}