//
// Created by gbb on 02/09/24.
//

#include "Mp_l.h"

void Mp_l::add_MP(int id, void* dir){//, DT t) {
    Mp_n* new_N = new Mp_n(id, dir,1,nullptr);//,t);
    if(frt == nullptr) {
        frt = new_N;
    }else {
        Mp_n* act = frt;
        for(int i =0;i < sz;i++) {
            act = act->Nxt;
        }
        act->Nxt = new_N;
    }
    sz++;
}

void Mp_l::rmv_MP(int id) {
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
