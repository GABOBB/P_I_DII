//
// Created by gbb on 02/09/24.
//

#ifndef MP_L_H
#define MP_L_H



struct Mp_n {
    int id;
    void* mp_dir = nullptr;
    int R_C = 0;
    Mp_n* Nxt = nullptr;

    Mp_n(int id = 0, void* dir = nullptr, int R_C = 0, Mp_n* Nxt = nullptr):
          id(id), mp_dir(dir), R_C(R_C), Nxt(Nxt){}
};
class Mp_l {
private:
    Mp_n* frt = nullptr;
    int sz = 0;

public:
    Mp_l()=default;
    ~Mp_l()=default;


    void add_MP(int id, void* dir);
    void remove_MP(int id);
    int ref_mg(int id,bool c);
    Mp_n* get_frt(){return frt;}
    int get_RC(){return sz;}

    void debug();

};


#endif //MP_L_H
