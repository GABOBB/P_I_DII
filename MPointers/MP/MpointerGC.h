//
// Created by gbb on 31/08/24.
//

#ifndef MPOINTERGC_H
#define MPOINTERGC_H


#include <thread>
#include "Mp_l.h"
#include "Mpointer.h"
#include <mutex>

class MpointerGC {

    protected:
        std::thread GC;
        bool running;
        int id_c = 0;
        static std::mutex mutexx;

        MpointerGC(): GC(&MpointerGC::_GC_, this) {};

    void _GC_();
    private:
        Mp_l listado;

    public:
        static MpointerGC& getI();

        int Mng_RC(int id, bool c);
        ~MpointerGC();


        MpointerGC(const MpointerGC&) = delete;
        MpointerGC(MpointerGC&&) = delete;
        MpointerGC& operator=(const MpointerGC&) = delete;
        MpointerGC& operator=(MpointerGC&&) = delete;

        int add_Mp(void* dir);
};



#endif //MPOINTERGC_H
