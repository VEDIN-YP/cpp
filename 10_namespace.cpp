#include <iostream>

namespace first {
    int x = 1;

}
namespace second {
    int x = 2;
}

int main() {
    using namespace second;

  int x = 0; // local variable    

std::cout << second::x; 


    return 0;
}