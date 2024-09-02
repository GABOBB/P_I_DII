//
// Created by gbb on 25/08/24.
//

#include <stdexcept>
#include <type_traits>
#include "Mpointer.h"
#include "MpointerGC.h"

template<class T>
Mpointer<T>::Mpointer() : ptr(nullptr), R_C(nullptr) {
    MpointerGC &GC = MpointerGC::getI();
};

template<class T>
Mpointer<T>::~Mpointer() {
    if(R_C && --(*R_C) == 0) {
        delete R_C;
        delete ptr;
    }
}

template<class T>
T& Mpointer<T>::operator*() {
    if(!ptr) {throw std::runtime_error("Mpointer::operator*(): pointer is null");}
    return *ptr;
}

template<class T>
T Mpointer<T>::operator&() {

}

template<class T>
Mpointer<T>& Mpointer<T>::operator=(const Mpointer<T> &other) {}

template<class T>
Mpointer<T>& Mpointer<T>::operator=(const T* other){}

