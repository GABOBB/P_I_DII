//
// Created by gbb on 25/08/24.
//
#ifndef MPOINTER_H
#define MPOINTER_H

#include "MpointerGC.h"
#include <iostream>
//using namespace std;

template<typename T>
class Mpointer {
public:
    MpointerGC *GC;
    int id;
    T *m_ptr;

    Mpointer() : id(0),GC(MpointerGC::getI()), m_ptr(nullptr){
        id = GC->add_Mp(this);
    };



    ~Mpointer() = default;

    static Mpointer<T> New() {
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
            GC->RefCount_Manager( id, false);
            *m_ptr = value;

        }
        return *this;
    }

    Mpointer<T>& operator=(const Mpointer<T> Mptr) {

        if(this->m_ptr != Mptr.m_ptr) {
            GC->RefCount_Manager(id,false);
            GC->RefCount_Manager(Mptr.id,true);

            this->m_ptr = Mptr.m_ptr;


        }
        return *this;
    }

    Mpointer<T>& operator=(T* prt) {
        if(m_ptr != prt) {
            if(m_ptr) {
                GC->RefCount_Manager(id,false);
            }
            m_ptr = prt;
        }
        return *this;

    }

    template<typename U>
    Mpointer<T>& operator=(const U& value) {
        if(this->m_ptr != nullptr) {
            GC->RefCount_Manager(id,false);
        }
        return *this;
    }

};

#endif //MPOINTER_H
