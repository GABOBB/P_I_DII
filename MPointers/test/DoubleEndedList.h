//
// Created by gbb on 31/08/24.
//

#ifndef DE_LIST_H
#define DE_LIST_H
#include "DoubleEndedNode.h"

template<class T>
class DoubleEndedList {
    private:
    DoubleEndedNode<T> *first;
    DoubleEndedNode<T> *last;
    int size;

    public:
        DoubleEndedList(): first(nullptr), last(nullptr), size(0) {};

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
            DoubleEndedNode<T>* newNodo = new DoubleEndedNode<T>(value);
            if(size==0) {
                first = newNodo;
                last = newNodo;
            }else {
                newNodo->setNext(first);
                first->setPrevious(newNodo);
                first = newNodo;
            }
            size++;
        };

        void BubbleSort() {
            if(size < 2) {return;}

            bool sorted;
            do {
                sorted = false;
                DoubleEndedNode<T>* act = first;
                while(act->getNext()) {
                    if(act->getValue() < act->getNext()->getValue()) {
                        T temp = act->getValue();
                        act->setValue(act->getNext()->getValue());
                        act->getNext()->setValue(temp);
                        sorted = true;
                    }
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
            DoubleEndedNode<T>* act = first;
            for(int i = 1; i <= size; i++) {
                std::cout << "elemento #"<<i<<": "<<act->getValue()<<std::endl;
                act = act->getNext();
            }
        };
};



#endif //DE_LIST_H
