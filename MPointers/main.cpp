#include <iostream>

#include "MP/Mpointer.h"
#include "MP/MpointerGC.h"

int main() {
    std::cout << "Hello World!" << std::endl;
    Mpointer<int> mp1 = Mpointer<int>::New();
    *mp1 = 66655;
std::cout << *mp1 << std::endl;
    Mpointer<int> mp2 = Mpointer<int>::New();
    *mp2 = 6665;
std::cout << *mp2 << std::endl;
    Mpointer<int> mp3 = Mpointer<int>::New();
    *mp3 = 666;

    MpointerGC::getI()->debug();

    return 0;
};
