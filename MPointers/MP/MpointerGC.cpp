//
// Created by gbb on 31/08/24.
//

#include "MpointerGC.h"
#include <iostream>
#include <mutex>
MpointerGC::MpointerGC() {
    GC = std::thread(&MpointerGC::_GC_,this);
}
MpointerGC::~MpointerGC() {
    running = false;
    if(GC.joinable()) {
        GC.join();
    }
};
MpointerGC* MpointerGC::getI() {
    std::lock_guard<std::mutex> lock(mutexx);
    if(instance == nullptr) {
        instance = new MpointerGC();
    }
    return instance;
};


void MpointerGC::_GC_() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::lock_guard<std::mutex> lock(mutexx);

        Mp_n* act = this->listado.get_frt();
        while (act != nullptr) {
            if(act->R_C < 1) {
                listado.rmv_MP(act->id);

            }
            act = act->Nxt;
        }
    }
    GC.join();
};


int MpointerGC::add_Mp(void* dir) {
    listado.add_MP(++id_c,dir);
    return id_c;
}

int MpointerGC::Mng_RC(int id, bool c) {
    Mp_n* act = this->listado.get_frt();
    while (act != nullptr) {
        if(act->id == id) {
            return this->listado.ref_mg(id,c);
        }
    }
    return 0;
}
void MpointerGC::debug() {
    std::cout << "~~~~~~~~~~~~~~~~~~MpointerGC::listado~~~~~~~~~~~~~~~~~~" << std::endl;
    Mp_n* act = this->listado.get_frt();
    for(int i = 0; i <= listado.get_RC();i++) {
        std::cout << "valor #" << i <<":   "
                  << &act <<std::endl;
        act = act->Nxt;
    }
}


