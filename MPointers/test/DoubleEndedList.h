//
// Created by gbb on 31/08/24.
//

#ifndef DE_LIST_H
#define DE_LIST_H
#include "DoubleEndedNode.h"

template<class T>
class DoubleEndedList {
    private:
    Mpointer<DoubleEndedNode<T>> first = Mpointer<DoubleEndedNode<T>>::New();
    Mpointer<DoubleEndedNode<T>> last = Mpointer<DoubleEndedNode<T>>::New();
    int size;

    public:
        DoubleEndedList(): size(0) {};

        ~DoubleEndedList()=default;
        void DeleteFirstNode() {
            if(first) {
                DoubleEndedNode<T>* temp = first;
                first = first->getNext();
                delete temp;
            }
            size--;
        };
        void addNodoFirst(T value) {
            Mpointer<DoubleEndedNode<T>> newNodo = Mpointer<DoubleEndedNode<T>>::New();
            newNodo = new DoubleEndedNode<T>(value);
            std::cout <<newNodo.m_ptr->getValue() << std::endl;
            if(size==0) {
                first = newNodo;
                last = newNodo;
            }else {
                newNodo.m_ptr->setNext(first);
                first.m_ptr->setPrevious(newNodo);
                first = newNodo;
            }
            size++;
        };

        void BubbleSort() {
            if(size < 2) {return;}

            bool sorted;
            do {
                sorted = false;
                Mpointer<DoubleEndedNode<T>> act = first;
                while(act.m_ptr->getNext().m_ptr) {
                    if(act.m_ptr->getValue() < (act.m_ptr->getNext()).m_ptr->getValue()) {
                        T temp = act.m_ptr->getValue();
                        act.m_ptr->setValue((act.m_ptr->getNext()).m_ptr->getValue());
                        ((act.m_ptr)->getNext()).m_ptr->setValue(temp);
                        sorted = true;
                    }
                    act = act.m_ptr->getNext();
                }
            }while (sorted);
        };
        void InsertionSort() {
            if(size < 2) {return;}

            Mpointer<DoubleEndedNode<T>> act = first.m_ptr->getNext();

            while(act.m_ptr) {
                T key = act.m_ptr->getValue();
                Mpointer<DoubleEndedNode<T>> prev = act.m_ptr->getPrevious();
                while(prev.m_ptr && prev.m_ptr->getValue() > key) {
                    prev.m_ptr->getNext().m_ptr->setValue(prev.m_ptr->getValue());
                    prev = prev.m_ptr->getPrevious();
                }

                if(prev.m_ptr) {
                    prev.m_ptr->getNext().m_ptr->setValue(key);
                }else {
                    first.m_ptr->setValue(key);
                }
                act = act.m_ptr->getNext();
            }
        };
    void QuickSort() {
        QuickSortRecursive(first, last);
    }

    void QuickSortRecursive(Mpointer<DoubleEndedNode<T>> low, Mpointer<DoubleEndedNode<T>> high) {
        if (low.m_ptr != nullptr && high.m_ptr != nullptr && low.m_ptr != high.m_ptr && low.m_ptr != high.m_ptr->getNext().m_ptr) {
            Mpointer<DoubleEndedNode<T>> pivotNode = Partition(low, high);

            QuickSortRecursive(low, pivotNode.m_ptr->getPrevious());
            QuickSortRecursive(pivotNode.m_ptr->getNext(), high);
        }
    }

    Mpointer<DoubleEndedNode<T>> Partition(Mpointer<DoubleEndedNode<T>> low, Mpointer<DoubleEndedNode<T>> high) {
        T pivotValue = high.m_ptr->getValue(); // Elige el último nodo como pivote
        Mpointer<DoubleEndedNode<T>> i = low.m_ptr->getPrevious(); // i marca el nodo menor a la partición

        for (Mpointer<DoubleEndedNode<T>> j = low; j.m_ptr != high.m_ptr; j = j.m_ptr->getNext()) {
            if (j.m_ptr->getValue() < pivotValue) {
                i = (i.m_ptr == nullptr) ? low : i.m_ptr->getNext(); // Mueve el puntero i hacia el siguiente nodo
                // Intercambia los valores de i y j
                T tempValue = i.m_ptr->getValue();
                i.m_ptr->setValue(j.m_ptr->getValue());
                j.m_ptr->setValue(tempValue);
            }
        }

        // Coloca el pivote en la posición correcta
        i = (i.m_ptr == nullptr) ? low : i.m_ptr->getNext(); // Mueve el puntero i al siguiente
        T tempValue = i.m_ptr->getValue();
        i.m_ptr->setValue(high.m_ptr->getValue());
        high.m_ptr->setValue(tempValue);

        return i; // Retorna la nueva posición del pivote
    }


        void Print() {
            Mpointer<DoubleEndedNode<T>> act = first;
            std::cout << size << std::endl;
            for(int i = 1; i <= size; i++) {
                std::cout << "elemento #"<<i<<": "<<act.m_ptr->getValue()<<std::endl;
                act = act.m_ptr->getNext();
            }
        };
};



#endif //DE_LIST_H
