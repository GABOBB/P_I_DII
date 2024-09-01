#include <iostream>

template<class T>
class N_DE {
  private:
    T Value;//cambiar a Mpointer
    N_DE<T>* N_n;
    N_DE<T>* P_n;

  public:
    N_DE(T v) : Value(v), N_n(nullptr), P_n(nullptr) {};

    void set_V(T v) {
      Value = v;}

    void set_N(N_DE<T>* n) {
      N_n = n;}

    void set_P(N_DE<T>* n) {
      P_n = n;}

    T get_V() {
      return Value;}

    N_DE<T>* get_N() {
      return N_n;}

    N_DE<T>* get_P() {
      return P_n;}

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
      for(int i = 0; i <= sz; i++) {
          D_f_N();
      }
    }

    void D_f_N() {
      if(first != nullptr && sz > 0) {
        N_DE temp = first;
        first = first->get_N();
        delete temp;
      }
    }

    void Add_l_N(T Value) {
      if(Value != nullptr) {
        N_DE new_D = new N_DE<T>(Value);
        if(first == nullptr) {
          first = new_D;
          last = new_D;
        }else{
          last -> set_N(new_D);
          new_D->set_P(last);
          last = new_D;
        }
        sz++;
      }
    }
};


