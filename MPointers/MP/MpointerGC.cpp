//
// Created by gbb on 31/08/24.
//

#include "MpointerGC.h"
#include <iostream>
#include <mutex>

MpointerGC* MpointerGC::instance = nullptr;
std::mutex MpointerGC::mutexx;

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
    if(MpointerGC::instance == nullptr) {
        MpointerGC::instance = new MpointerGC();
    }
    return MpointerGC::instance;
};


void MpointerGC::_GC_() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::lock_guard<std::mutex> lock(mutexx);
        std::cout << MpointerGC::instance << " is running." << std::endl;

        Mp_nodo* act = this->listado.get_frt();
        while (act != nullptr) {
            std::cout <<act->R_C << std::endl;
            if(act->R_C < 1) {
                listado.remove_MP(act->id);

            }
            act = act->Nxt;
        }
    }

};


int MpointerGC::add_Mp(void* dir) {
    listado.add_MP(++id_c,dir);
    return id_c;
}

int MpointerGC::RefCount_Manager(int id, bool c) {
    Mp_nodo* act = this->listado.get_frt();
    while (act != nullptr) {
        //std::cout << "si llega"<<std::endl;
        if(act->id == id) {
            return this->listado.ref_mg(id,c);
        }
        act = act->Nxt;
    }
    return 0;
}
void MpointerGC::debug(bool c) {
    std::cout << "\n~~~~~~~~~~~~~~~~~~MpointerGC::listado::inicio~~~~~~~~~~~~~~~~~~" << std::endl;
    listado.debug(c);
    std::cout << "~~~~~~~~~~~~~~~~~~MpointerGC::listado::final~~~~~~~~~~~~~~~~~~" << std::endl;
}


