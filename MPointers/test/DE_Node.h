//
// Created by gbb on 31/08/24.
//

#ifndef DE_NODE_H
#define DE_NODE_H


template<class T>
class DE_Node {
    private:
        T Value;
        DE_Node<T>* N;
        DE_Node<T>* P;
    public:

    DE_Node(T V):Value(V),N(nullptr),P(nullptr) {};

    void setV(T V);
    void setN(DE_Node<T>* N);
    void setP(DE_Node<T>* P);

    T getV();
    DE_Node<T>* getN();
    DE_Node<T>* getP();
};



#endif //DE_NODE_H
