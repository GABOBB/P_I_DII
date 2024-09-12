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

            DoubleEndedNode<T>* act = first->getNext();

            while(act) {
                T key = act->getValue();
                DoubleEndedNode<T>* prev = act->getPrev();
                while(prev && prev->getValue() > key) {
                    prev->getNext()->setValue(prev->getValue());
                    prev = prev->getPrevious();
                }

                if(prev) {
                    prev->getNext()->setValue(key);
                }else {
                    first->setValue(key);
                }
            }
        };
        void QuickSort();

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
