//
// Created by gbb on 02/09/24.
//

#ifndef MP_L_H
#define MP_L_H

#include <iostream>
#include <ostream>

enum class DT {
    INT,
    DOUBLE,
    FLOAT,
    UNKNOWN
};

struct Mp_n {
    int id;
    void* dir = nullptr;
    int R_C = 0;
    Mp_n* Nxt = nullptr;
    DT tp;
    Mp_n(int id = 0, void* dir = nullptr, int C_dir = 0, Mp_n* next = nullptr, DT type = DT::INT):
          id(id), dir(dir), R_C(C_dir), Nxt(next), tp(type){}
};
class Mp_l {
    private:
    Mp_n* frt = nullptr;
    int sz = 0;

    public:
    Mp_l();
    ~Mp_l()=default;

    void add_MP(int id, void* dir);//, DT t);
    void rmv_MP(int id);
    int ref_mg(int id,bool c);


};



#endif //MP_L_H
