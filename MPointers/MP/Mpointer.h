//
// Created by gbb on 25/08/24.
//
#ifndef MPOINTER_H
#define MPOINTER_H

#include "MpointerGC.h"

//using namespace std;

template<typename T>
class Mpointer {
private:
    MpointerGC *GC;
    //bool ocupated;
    int id;
    T *m_ptr;

    Mpointer() : id(0),GC(MpointerGC::getI()), m_ptr(nullptr){
    std::cout << "Mpointer constructor" << std::endl;
    };

public:
    ~Mpointer() = default;

    static Mpointer<T> New() {
        std::cout << "Mpointer<T>::New()" << std::endl;
        //GC.
        Mpointer<T> MP;
        return MP;
    }

    T& operator*() {
        if(m_ptr==nullptr) {
            delete m_ptr;
            m_ptr = new T();
        }
        return *m_ptr;
    };

    Mpointer<T>& operator=(const T& value) {
        if(m_ptr != nullptr && *m_ptr != value) {
            GC->Mng_RC( id, false);
            *m_ptr = value;
            return *this;
        }

    }

    Mpointer<T>& operator=(T* ptr) {
        if(*m_ptr != ptr && m_ptr != nullptr) {

        }

  }

    //Mpointer<T>& operator=(const Mpointer<T>& otr_ptr) {
    //    if(&otr_ptr != this) {
    //        this.m_ptr = otr_ptr.m_ptr;
    //        GC->Mng_RC(otr_ptr.id,true);
    //        ocupated = true;
    //
    //    }
    //    return *this;
    //}
};

#endif //MPOINTER_H
