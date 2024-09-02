//
// Created by gbb on 25/08/24.
//

#ifndef MPOINTER_H
#define MPOINTER_H
#include <stdexcept>
#include <type_traits>
#include "MpointerGC.h"

template<class T>
class Mpointer {
    protected:
    int id;
    T* ptr;
    int* R_C;
    Mpointer();

    public:

    ~Mpointer();
    static Mpointer<T> New();

    T& operator*();
    const T& operator*() const;

    T operator&();
    const T operator&() const;

    Mpointer<T>& operator=(const Mpointer<T>& other);
    Mpointer<T>& operator=(const T* other);

    Mpointer& operator=(Mpointer&& other) noexcept;
};



#endif //MPOINTER_H
