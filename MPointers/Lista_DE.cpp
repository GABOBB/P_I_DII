class L_DE {

};

template<class T>
class N_DE {
  private:
    T Value;
    N_DE<T>* N_n;
    N_DE<T>* P_n;

  public:
    N_DE(T v) : Value(v), N_n(nullptr), P_n(nullptr) {};

    

};