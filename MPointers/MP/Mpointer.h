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
private:
    MpointerGC *GC;
    int id;
    T *m_ptr;

    Mpointer() : id(0),GC(MpointerGC::getI()), m_ptr(nullptr){
        id = GC->add_Mp(this);
    };

public:
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

    Mpointer<T>& operator=(const Mpointer<T> mptr) {

        if(this->m_ptr != mptr.m_ptr) {
            delete this->m_ptr;
            this->m_ptr = mptr.m_ptr;
            GC->RefCount_Manager(id,false);
            GC->RefCount_Manager(mptr.id,true);

        }
        return *this;

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
