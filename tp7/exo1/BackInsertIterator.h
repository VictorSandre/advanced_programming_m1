//
// Created by victor SANDRE.
//

#ifndef EXO1_BACKINSERTITERATOR_H
#define EXO1_BACKINSERTITERATOR_H

#include "Array.h"

template <typename T, int ENLARGEMENT>
class Array;


/**
 * Cet itérateur est un itérateur d'insertion, il permet d'inserer un élément a la fin de la liste.
 *
 * @tparam Container et non T* comme sur l'itérateur precedent car si on ajoute un élément dans le tableau d'éléments
 * de la classe Array, alors celui-ci change d'adresse (car sa taille change donc on le copie dans un nouveau tableau
 * plus grand à une nouvelle adresse).
 *
 */
 /*
template<class Container>
class BackInsertIterator {
public:
    BackInsertIterator(Container& container);

    BackInsertIterator<Container>& operator=(const BackInsertIterator<Container>& iterator);

    BackInsertIterator<Container>& operator=(const typename Container::value_type& value);

    // Ne sert à rien.
    const Container& operator*() const;

    // Ne sert à rien.
    BackInsertIterator<Container>& operator++();

private:
    Container* _container;
};

template<class Container>
BackInsertIterator<Container>::BackInsertIterator(Container &container) : _container(container) {}

template<class Container>
BackInsertIterator<Container> &BackInsertIterator<Container>::operator=(const BackInsertIterator<Container> &iterator) {
    _container = iterator._container;
    return *this;
}

template<class Container>
BackInsertIterator<Container> &BackInsertIterator<Container>::operator=(const typename Container::value_type& value) {
    _container->add(value);
    return *this;
}

template<class Container>
const Container &BackInsertIterator<Container>::operator*() const {
    return *this;
}

template<class Container>
BackInsertIterator<Container> &BackInsertIterator<Container>::operator++() {
    return *this;
}
*/
#endif //EXO1_BACKINSERTITERATOR_H
