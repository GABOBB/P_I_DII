#include <iostream>

#include "MP/Mpointer.h"
#include "MP/MpointerGC.h"
#include "test/DoubleEndedList.h"
int main() {
    //DoubleEndedList<int> Lista;
    //Lista.addNodoFirst(5);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    MpointerGC::getI()->debug();

    ///*
    Mpointer<int> mp1 = Mpointer<int>::New();
    *mp1 = 1;
    MpointerGC::getI()->debug();
    Mpointer<int> mp2 = Mpointer<int>::New();
    *mp2 = 2;
    MpointerGC::getI()->debug();
    Mpointer<int> mp3 = Mpointer<int>::New();
    mp3 = mp2;
    MpointerGC::getI()->debug();
    Mpointer<int> mp4 = Mpointer<int>::New();
    mp4 = mp2;
    MpointerGC::getI()->debug();
    //*mp3 = 3;
    *mp4 = 5;
    MpointerGC::getI()->debug();
    *mp3 = 35;
    MpointerGC::getI()->debug();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "M1 "<< *mp1 <<", M2 "<< *mp2 <<", M3 "<< *mp3 <<", M4 "<< *mp4<< std::endl;
    return 0;//*/
};

