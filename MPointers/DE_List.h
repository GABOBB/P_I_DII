//
// Created by gbb on 31/08/24.
//

#ifndef DE_LIST_H
#define DE_LIST_H
#include "DE_Node.h"

template<class T>
class DE_List {
    private:
    DE_Node<T> *first;
    DE_Node<T> *last;
    int sz;

    public:
        DE_List(): first(nullptr), last(nullptr), sz(0) {};

    ~DE_List();
    void D_F_N();//hola


};



#endif //DE_LIST_H
