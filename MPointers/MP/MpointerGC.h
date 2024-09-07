//
// Created by gbb on 31/08/24.
//
#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <thread>
#include "Mp_l.h"

#include <mutex>

class MpointerGC {

private:
    static MpointerGC *instance;
    Mp_l listado;
    static std::mutex mutexx;
    std::thread GC;
    bool running;
    int id_c = 0;


    MpointerGC();

    void _GC_();

public:
    static MpointerGC *getI();

    int add() {
        return 2;
    }

    int Mng_RC(int id, bool c);

    ~MpointerGC();

    //MpointerGC(const MpointerGC&) = delete;
    //MpointerGC(MpointerGC&&) = delete;
    //MpointerGC& operator=(const MpointerGC&) = delete;
    //MpointerGC& operator=(MpointerGC&&) = delete;

    int add_Mp(void *dir);
    void debug();
};

#endif //MPOINTERGC_H
