//
// Created victor SANDRE.
//

#ifndef EXO2_ITERATOR_H
#define EXO2_ITERATOR_H
#include "Array.h"

template <typename T, int ENLARGEMENT>
class Array;

template<typename T>
class Iterator {
public:
    Iterator(T *currentElementPtr);

    Iterator(const T &currentElementPtr);

    Iterator<T>& operator=(const Iterator<T>& iterator);

    const T& operator*() const; // En lecture seulement ici. Si en ecriture enlever le premier const.

    Iterator<T>& operator++();

    bool operator!=(const Iterator<T>& iterator) const;

private:
    T* _currentElementPtr;
};

template<typename T>
Iterator<T>::Iterator(T * currentElementPtr)
: _currentElementPtr(currentElementPtr) {}

template<typename T>
Iterator<T>::Iterator(const T & currentElementPtr)
: _currentElementPtr(currentElementPtr) {}

template<typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &iterator) {
    _currentElementPtr = iterator._currentElementPtr;//TODO ne faut il pas plutot faire une copie à la place ?
    return *this;
}

template<typename T>
const T &Iterator<T>::operator*() const {
    return *_currentElementPtr;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++() {
    _currentElementPtr++;
    return *this;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &iterator) const {
    if (_currentElementPtr != iterator._currentElementPtr)
        return true;
    else
        return  false;
}

#endif //EXO2_ITERATOR_H
