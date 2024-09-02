//
// Created by gbb on 31/08/24.
//

#include "DE_List.h"

#include <cstdlib>

template<class T>
DE_List<T>::~DE_List() {
    while(sz>0) {
        D_F_N();
    }
}

template<class T>
void DE_List<T>::D_F_N() {
    if(first) {
        DE_Node<T>* temp = first;
        first = first->getN();
        delete temp;
    }
    sz--;
}