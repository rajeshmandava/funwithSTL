#include <iostream>
#include <string>
#include <vector>

int main()
{
  auto i = 42;
  double f;
  auto d = f;

  // auto ch; //Error : can't deduce the type of ch
  // The type of a variable declared with auto is deduced from its initializer. Thus, an initialization is required:

  static auto val = 0.9; // Additional qualifiers are allowed.

  std::vector<std::string> sv;
  auto pos = sv.begin();   //pos has type vector<string>::iterator

  auto l = [&] (int x) -> bool {
    if( i == 42 )
    {
      return true;
    }
    return false;
  };
  // std::cout<<"lambda l returns :"<<l<<std::endl;

}