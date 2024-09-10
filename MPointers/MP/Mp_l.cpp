//
// Created by gbb on 02/09/24.
//

#include "Mp_l.h"
#include <iostream>

#include "Mpointer.h"

void Mp_l::add_MP(int id, void* dir){
    Mp_n* new_N = new Mp_n(id, dir,1,nullptr);
    std::cout<<"Mp_l::add_MP"<<id<<"::";
    if(frt == nullptr) {
        frt = new_N;
    }else {
        Mp_n* act = frt;
        for(int i =0;i < sz-1;i++) {
            act = act->Nxt;
        }
        act->Nxt = new_N;
    }
    sz++;
}

void Mp_l::remove_MP(int id) {
    Mp_n* act = frt;
    Mp_n* pst = nullptr;

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

int Mp_l::ref_mg(int id, bool c) {
    Mp_n* act = frt;
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

void Mp_l::debug() {

    Mp_n* act = this->frt;
    std::cout<<"sz:" <<this->sz<<std::endl;
    for(int i = 0; i < sz;i++) {
        Mpointer<int>* mmp = static_cast<Mpointer<int>*>(act->mp_dir);
        std::cout << "valor #" << i <<":   "
                  << **(mmp)  <<std::endl;
        if(act->Nxt != nullptr) {
            act = act->Nxt;
        }

    }
}
