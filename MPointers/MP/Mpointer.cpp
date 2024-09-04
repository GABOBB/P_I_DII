//
// Created by gbb on 25/08/24.
//

#include <stdexcept>
#include <type_traits>
#include "Mpointer.h"
#include "MpointerGC.h"

template<class T>
Mpointer<T>::Mpointer() : GC(),ocupated(false), m_ptr(nullptr){
    MpointerGC &GC = MpointerGC::getI();
};



template<class T>
Mpointer<T>& Mpointer<T>::operator=(const Mpointer<T> &other) {}


template<class T>
Mpointer<T>& Mpointer<T>::operator=(const T* other) {
    if(this->m_ptr != other) {
        if(m_ptr) {
            ocupated = true;
            if(m_ptr) {
                int c = GC.Mng_RC(id,false);
                if(c>0){ delete m_ptr; m_ptr=nullptr; }
            }
        }
    }
}

