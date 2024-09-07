//
// Created by gbb on 25/08/24.
//
#ifndef MPOINTER_H
#define MPOINTER_H

#include "MpointerGC.h"

using namespace std;

template<typename T>
class Mpointer {
    MpointerGC *GC;

private:
    bool ocupated;
    int id;
    T *m_ptr;

    Mpointer() : GC(MpointerGC::getI()), ocupated(false), m_ptr(nullptr){
    };

public:
    ~Mpointer() = default;

    static Mpointer<T> New() {
        return Mpointer<T>();
    }

    T &operator*() {
        return *m_ptr;
    };

    Mpointer<T>& operator=(T other) {
        if(this->m_ptr != other) {
            ocupated = true;
            if(m_ptr) {
                int c = GC->Mng_RC(id,false);
                if(c>0) {
                    delete m_ptr; m_ptr=nullptr;
                }
            }
            this->m_ptr=other;
        }
        return *this;
    }

    Mpointer<T>& operator=(const Mpointer<T>& otr_ptr) {
        if(&otr_ptr != this) {
            this.m_ptr = otr_ptr.m_ptr;
            GC->Mng_RC(otr_ptr.id,true);
            ocupated = true;

        }
        return *this;
    }
};

#endif //MPOINTER_H
