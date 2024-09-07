//
// Created by gbb on 25/08/24.
//

#ifndef MPOINTER_H
#define MPOINTER_H
#include <stdexcept>
#include <type_traits>
#include "MpointerGC.h"

using namespace std;
template<class T>
class Mpointer {

    MpointerGC* GC;

private:
    bool ocupated;
    int id;
    T* m_ptr;

    Mpointer();

    public:

    ~Mpointer() = default;
    static Mpointer<T> New();

    T& operator*() {
        return *m_ptr;
    };
    T operator&() {
        return *m_ptr;
    };


    Mpointer<T>& operator=(const Mpointer<T>& other);
    Mpointer<T>& operator=( T* other);

    Mpointer& operator=(Mpointer&& other) noexcept;
};


//#include "Mpointer.cpp"
#endif //MPOINTER_H
