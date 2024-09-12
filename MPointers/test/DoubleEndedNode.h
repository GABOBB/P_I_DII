//
// Created by gbb on 31/08/24.
//

#ifndef DE_NODE_H
#define DE_NODE_H


template<class T>
class DoubleEndedNode {
    private:
        T Value;
        Mpointer<DoubleEndedNode> next;
        Mpointer<DoubleEndedNode> previous;
    public:

    DoubleEndedNode(T V):Value(V),next(Mpointer<DoubleEndedNode<T>>::New()),previous(Mpointer<DoubleEndedNode<T>>::New()) {};

    void setValue(T V) {
        Value = V;
    };
    void setNext(Mpointer<DoubleEndedNode> N) {
        next = N;
    };
    void setPrevious(Mpointer<DoubleEndedNode> P) {
        previous = P;
    };

    T getValue() {
        return Value;
    };
    Mpointer<DoubleEndedNode> getNext() {
        return next;
    };
    Mpointer<DoubleEndedNode> getPrevious() {
        return previous;
    };
};



#endif //DE_NODE_H
