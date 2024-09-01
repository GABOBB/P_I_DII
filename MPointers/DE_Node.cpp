//
// Created by gbb on 31/08/24.
//

#include "DE_Node.h"

template<class T>
void DE_Node<T>::setV(T V) {Value = V;}

template<class T>
void DE_Node<T>::setN(DE_Node<T> *n) {N=n;}

template<class T>
void DE_Node<T>::setP(DE_Node<T> *p) {P=p;}

template<class T>
T DE_Node<T>::getV() {return Value;}
template<class T>
DE_Node<T>* DE_Node<T>::getN() {return N;}
template<class T>
DE_Node<T> *DE_Node<T>::getP() {return P;}

