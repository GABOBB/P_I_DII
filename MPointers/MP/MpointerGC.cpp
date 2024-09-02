//
// Created by gbb on 31/08/24.
//

#include "MpointerGC.h"

MpointerGC::~MpointerGC() {
    running = false;
    if(GC.joinable()) {
        GC.join();
    }
};

void MpointerGC::_GC_() {
    while (running) {

    }
    GC.join();
};

MpointerGC& MpointerGC::getI() {
    static MpointerGC instance;
    return instance;
};


