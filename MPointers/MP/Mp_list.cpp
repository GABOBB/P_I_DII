//
// Created by gbb on 02/09/24.
//

#include "Mp_list.h"
#include <iostream>

#include "Mpointer.h"
#include "../test/DoubleEndedNode.h"

void Mp_list::add_MP(int id, void* dir){
    Mp_nodo* new_N = new Mp_nodo(id, dir,1,nullptr);
    //std::cout<<"Mp_l::add_MP"<<id<<"::";
    if(frt == nullptr) {
        frt = new_N;
    }else {
        Mp_nodo* act = frt;
        for(int i =0;i < sz-1;i++) {
            act = act->Nxt;
        }
        act->Nxt = new_N;
    }
    sz++;
}

void Mp_list::remove_MP(int id) {
    Mp_nodo* act = frt;
    Mp_nodo* pst = nullptr;

    while(act != nullptr && act->id != id) {
        pst = act;
        act = act->Nxt;
    }

    if(act == nullptr) {
        return;
    }
    if(pst != nullptr) {
        pst->Nxt = act->Nxt;
    }else {
        frt = act->Nxt;
    }
    delete act;
}

int Mp_list::ref_mg(int id, bool c) {
    Mp_nodo* act = frt;
    for(int i =0;i < sz;i++) {
        if(act->id == id) {
            if(c) {
                act->R_C++;
            }else {
                act->R_C--;
            }
            return act->R_C;
        }

    }
    return 0;
}

void Mp_list::debug(bool c) {
    if(c) {
        Mp_nodo* act = this->frt;
        std::cout<<"sz:" <<this->sz<<std::endl;
        for(int i = 0; i < sz;i++) {
            Mpointer<DoubleEndedNode<int>>* mmp = static_cast<Mpointer<DoubleEndedNode<int>>*>(act->mp_dir);
            if(mmp != nullptr) {
                std::cout << "valor #" << i <<":   "
                        << mmp->m_ptr->getValue()  <<std::endl;//<<"\n reference count:  "<< act->R_C
                if(act->Nxt != nullptr) {
                    act = act->Nxt;
                }
            }
        }
    }else {
        Mp_nodo* act = this->frt;
        std::cout<<"sz:" <<this->sz<<std::endl;
        for(int i = 0; i < sz;i++) {
            Mpointer<int>* mmp = static_cast<Mpointer<int>*>(act->mp_dir);
            if(mmp != nullptr) {
                std::cout << "valor #" << i <<":   "
                        << mmp->m_ptr  <<std::endl;//<<"\n reference count:  "<< act->R_C
                if(act->Nxt != nullptr) {
                    act = act->Nxt;
                }
            }
        }
    }
}
