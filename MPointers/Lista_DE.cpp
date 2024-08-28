#include <iostream>

template<class T>
class N_DE {
  private:
    T Value;//cambiar a Mpointer
    N_DE<T>* N_n;
    N_DE<T>* P_n;

  public:
    N_DE(T v) : Value(v), N_n(nullptr), P_n(nullptr) {};

    void set_V(T v)        {Value = v;}
    void set_N(N_DE<T>* n) {N_n = n;}
    void set_P(N_DE<T>* n) {P_n = n;}

    T get_V() {return Value;}
    N_DE<T>* get_N() {return N_n;}
    N_DE<T>* get_P() {return P_n;}

};

template<class T>
class L_DE {
  private:
    N_DE<T>* first;
    N_DE<T>* last;
    int sz;

  public:
    L_DE() : first(nullptr), last(nullptr), sz(0) {};

    ~L_DE() {
      for(int i = 0; i < sz; i++) {
        first first.get_N()
      }
    }

    void D_f_N(N_DE<T>* n) {

    }

};

