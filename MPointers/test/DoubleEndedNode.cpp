//
// Created by gbb on 31/08/24.
//

#include "DoubleEndedNode.h"

template<class T>
void DoubleEndedNode<T>::setValue(T V) {Value = V;}

template<class T>
void DoubleEndedNode<T>::setNext(DoubleEndedNode<T> *n) {next=n;}

template<class T>
void DoubleEndedNode<T>::setPrevious(DoubleEndedNode<T> *p) {previous=p;}

template<class T>
T DoubleEndedNode<T>::getValue() {return Value;}
template<class T>
DoubleEndedNode<T>* DoubleEndedNode<T>::getNext() {return next;}
template<class T>
DoubleEndedNode<T> *DoubleEndedNode<T>::getPrevious() {return previous;}

