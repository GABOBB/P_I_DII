#include <iostream>

#include "MP/Mpointer.h"

int main() {
    std::cout << "Hello World!" << std::endl;
    Mpointer<int> mp1 = Mpointer<int>::New();
    *mp1 = 666;
    std::cout << &mp1 << std::endl;
    return 0;
};
