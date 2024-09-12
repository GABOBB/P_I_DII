//
// Created by gbb on 31/08/24.
//

#ifndef DE_NODE_H
#define DE_NODE_H


template<class T>
class DoubleEndedNode {
    private:
        T Value;
        DoubleEndedNode<T>* next;
        DoubleEndedNode<T>* previous;
    public:

    DoubleEndedNode(T V):Value(V),next(nullptr),previous(nullptr) {};

    void setValue(T V);
    void setNext(DoubleEndedNode<T>* N);
    void setPrevious(DoubleEndedNode<T>* P);

    T getValue();
    DoubleEndedNode<T>* getNext();
    DoubleEndedNode<T>* getPrevious();
};



#endif //DE_NODE_H
