//
// Created by gbb on 31/08/24.
//

#ifndef MPOINTERGC_H
#define MPOINTERGC_H
#include <any>
#include <thread>
#include "DE_List.h"
#include "Mpointer.h"


class MpointerGC {

    protected:
        std::thread GC;
        bool running;

        MpointerGC(): GC(&MpointerGC::_GC_, this) {};

    void _GC_();
    private:
        DE_List<Mpointer<>> listado;

    public:
        static MpointerGC& getI();

        ~MpointerGC();

        MpointerGC(const MpointerGC&) = delete;
        MpointerGC(MpointerGC&&) = delete;
        MpointerGC& operator=(const MpointerGC&) = delete;
        MpointerGC& operator=(MpointerGC&&) = delete;
};



#endif //MPOINTERGC_H
