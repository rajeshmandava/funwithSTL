#include <iostream>
#include <vector>
#include <string>
#include <complex>

// Classes with initializer list 

class P{
public:
  P(int a, int b)
  {
    std::cout<<" Constructor with two arguments"<<"\n";
  }
  P(std::initializer_list<int>)
  {
    std::cout<<"Constructor with initializer list"<<"\n";
  }
};

void fp(const P&)
{
  std::cout<<"function fp"<<"\n";
}

void print( std::initializer_list<int> vals)
{
  for( auto p = vals.begin(); p!=vals.end(); ++p)
  {
    // Process a list of values
    std::cout<<*p<<"\n";
  }
}

int main()
{
  // Before C++11, C++ developers, especially beginners, could easily become confused by the question of how to initialize a varaible of an object.
  // Intialization could happen with parantheses, braces, and/or assignment operators.
  // For this reason, C++11 introduced the concept of uniform initialiation, which means that for any initializtion, you can use one common sytax. This syntax uses braces, so the following is possible now:

  int values[] {1,2,3,4,5,6};
  std::vector<int> v{2,4,5,6,234,32,34,23,10,879};
  std::vector<std::string> cities{"Berlin", "New York", "London", "Braunschweig", "Cairo", "Cologne"};

  std::complex<std::double_t> c{4.0, 3.0};  //Equivalent to c(4.0, 3.0
  
  // Uniform initialization with fundamental data types
  int i; // i has undefined value
  int j{}; // j is initialized by 0
  int* p;  //p has undefined value
  int* q{};  // q is initialized to nullptr

  std::cout<<q<<std::endl; // Output 0

  // narrowing initializations

  int x1(5.3);    //OK, but OUCH: x1 becomes 5
  int x2 = 5.3;   //OK, but OUCH x2 becomes 5
  // int x3{5.0};    //ERROR: narrowing
  // int x4 = {5.5}; //ERROR: narrowing
  char c1{7};     //OK: even though 7 is an int, this is not narrowing
  // char c2{99999}; //ERROR: narrowing (if 99999 doesn't fit into a char)
  std::vector<int> v1{1,2,3,4,5}; // OK
  // std::vector<int> v2{1,2.3,4,5.6};  //ERROR: narrowing doubles to char

  print({12,3,4,5,7,11,13,17});

  P p_argument(77,5);    //calls P::P(int,int)
  P q_intializer_list{77,5};    //calls P::P(initializer_list)
  P r{77,5,10}; //calls P::P(initializer_list)
  P s = {77,5}; //calls P::P(initializer_list)

  fp({47,11});     //OK, implicit conversion of {47,11} into P
  fp({47,11,13});  //OK, implicit conversion of {47,11,13} into P
  fp({P{47,11}});  //OK, explicit conversion of {47,11} into P
  fp(P{47,11,3});  //OK, explicit conversion of {47,11,3} into P
}
