#include <iostream>

#include "MP/Mpointer.h"
#include "MP/MpointerGC.h"
#include "test/DoubleEndedList.h"
int main() {
    //descomentar esto para probrar directamente el Mpointer.
    Mpointer<int> mp1 = Mpointer<int>::New();
    *mp1 = 1;
    //MpointerGC::getI()->debug(false);
    Mpointer<int> mp2 = Mpointer<int>::New();
    *mp2 = 2;
    //MpointerGC::getI()->debug(false);
    Mpointer<int> mp3 = Mpointer<int>::New();
    mp3 = mp2;
    //MpointerGC::getI()->debug(false);
    Mpointer<int> mp4 = Mpointer<int>::New();
    mp4 = mp2;
    //MpointerGC::getI()->debug(false);
    //*mp3 = 3;
    *mp4 = 5;
    //MpointerGC::getI()->debug(false);
    *mp3 = 35;
    MpointerGC::getI()->debug(true);
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "M1 "<< *mp1 <<", M2 "<< *mp2 <<", M3 "<< *mp3 <<", M4 "<< *mp4<< std::endl;
    //*/
    //bubbleSort
    std::cout << "~~~~~~~~~~~~~~~~~~~BubbleSort~~~~~~~~~~~~~~~~~~~" << std::endl;
    DoubleEndedList<int> Lista;
    Lista.addNodoFirst(123);
    Lista.addNodoFirst(5);
    Lista.addNodoFirst(101);
    Lista.addNodoFirst(15);
    Lista.addNodoFirst(201);
    Lista.Print();
    Lista.BubbleSort();
    Lista.Print();

    //InsertionSort
    std::cout <<"~~~~~~~~~~~~~~~~~~~InsertionSort~~~~~~~~~~~~~~~~~~~" << std::endl;
    DoubleEndedList<int> Lista2;
    Lista2.addNodoFirst(123);
    Lista2.addNodoFirst(5);
    Lista2.addNodoFirst(101);
    Lista2.addNodoFirst(15);
    Lista2.addNodoFirst(201);
    Lista2.Print();
    Lista2.InsertionSort();
    Lista2.Print();

    //Quicksort
    std::cout <<"~~~~~~~~~~~~~~~~~~~QuickSort~~~~~~~~~~~~~~~~~~~"<< std::endl;
    DoubleEndedList<int> Lista1;
    Lista1.addNodoFirst(123);
    Lista1.addNodoFirst(5);
    Lista1.addNodoFirst(101);
    Lista1.addNodoFirst(15);
    Lista1.addNodoFirst(201);
    Lista1.Print();
    Lista1.QuickSort();
    Lista1.Print();

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    MpointerGC::getI()->debug(false);


    return 0;

};

