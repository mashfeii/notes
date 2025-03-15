#include <iostream>
#define NAME(world) #world
int main() {
#line 100
  std::cout << "Hello, " << NAME(world) << " from " << __FILE__
            << " and a line #" << __LINE__ << std::endl;
}
