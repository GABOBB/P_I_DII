//
// Created by gbb on 25/08/24.
//

#include <stdexcept>
#include <type_traits>

template <typename T>
class Mpointer {
    int id;
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

    T& operator*() {
        if(!ptr) {
            throw std::runtime_error("Mpointer::operator*(): pointer is null");
        }
        return *ptr;
    }

    const T& operator*() const {
        if(!*ptr) {
            throw std::runtime_error("Mpointer::operator*(): pointer is null");
        }
        return *ptr;
    }

    T operator&(){//sobrecarga del operador
        if(!*ptr) {
            throw std::runtime_error("Mpointer::operator&(): pointer is null");
        }
        return *ptr;
    }

    const T operator&() const {
        if(!*ptr) {
            throw std::runtime_error("Mpointer::operator&(): pointer is null");
        }
        return *ptr;
    }

    Mpointer<T>& operator=(const T& value) {
        if (ptr == nullptr) {
            ptr = new T();
            R_C = new int(1); // Inicializar contador de referencias
        }
        *ptr = value;
        return *this;
    }

    Mpointer<T>& operator=(const Mpointer<T>& other) {
        if(this != other) {

        }

    }
};
