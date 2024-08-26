//
// Created by gbb on 25/08/24.
//

#include <type_traits>

template <typename T>
class Mpointer {
    T* ptr;
    int* R_C; //reference count

    Mpointer() : ptr(nullptr), R_C(nullptr) {}

    public:
    ~Mpointer() {//destructor
        if(R_C && --(*R_C) == 0) {
            delete R_C;
            delete ptr;
        }
    }

    static Mpointer<T> New() {
        static_assert(std::is_arithmetic<T>::value || std::is_same<T, char>::value, "type must be arithmetic or char");
        Mpointer<T> m_p;
        m_p.ptr = new T();
        m_p.R_C = new int(1);
        return m_p;
    }
    
};
