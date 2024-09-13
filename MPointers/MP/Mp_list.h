//
// Created by gbb on 02/09/24.
//

#ifndef MP_L_H
#define MP_L_H



struct Mp_nodo {
    int id;
    void* mp_dir = nullptr;
    int R_C = 0;//ref count
    Mp_nodo* Nxt = nullptr;

    Mp_nodo(int id = 0, void* dir = nullptr, int R_C = 0, Mp_nodo* Nxt = nullptr):
          id(id), mp_dir(dir), R_C(R_C), Nxt(Nxt){}
};
class Mp_list {
private:
    Mp_nodo* frt = nullptr;
    int sz = 0;

public:
    Mp_list()=default;
    ~Mp_list()=default;


    void add_MP(int id, void* dir);
    void remove_MP(int id);
    int ref_mg(int id,bool c);
    Mp_nodo* get_frt(){return frt;}
    int get_RC(){return sz;}

    void debug(bool c);

};


#endif //MP_L_H
