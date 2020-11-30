//
// Created by victor SANDRE.
//

#ifndef TP_NOTE_SEQUENCECIRCULAIRE_H
#define TP_NOTE_SEQUENCECIRCULAIRE_H

#include <ostream>
#include <iostream>
#include "Circulateur.h"

template<typename T>
class Circulateur;

template <typename T>
class SequenceCirculaire {
public:
    typedef T value_type;

    friend class Circulateur<T>;
    // TODO affichage en exterieur
    friend std::ostream &operator<<(std::ostream &os, const SequenceCirculaire &circulaire) {
        os << "_nbElem : " << circulaire._nbElem << " capacite : " << circulaire._capacite << std::endl;
        os << "[ ";
        for (int i=0 ; i<circulaire._nbElem ; ++i) {
            os << circulaire._periode[i] << " ";
        }
        os << "]" << std::endl;
        return os;
    }

    SequenceCirculaire();

    SequenceCirculaire(int, int);

    SequenceCirculaire(int, const T&);

    SequenceCirculaire(const SequenceCirculaire<T>&);

    SequenceCirculaire(SequenceCirculaire<T>&&) noexcept;

    SequenceCirculaire& operator=(const SequenceCirculaire<T>&);

    SequenceCirculaire& operator=(SequenceCirculaire<T>&&) noexcept ;

    void insertion(int, const T&);

    const T& operator[](int) const;

    T& operator[](int);

    int recherche(const T&) const;

    Circulateur<T> makeCirculateur(int);

    ~SequenceCirculaire();

private:
    int _nbElem;
    int _capacite;
    T* _periode;
};

template<typename T>
SequenceCirculaire<T>::SequenceCirculaire() : SequenceCirculaire(0,10) {}

template<typename T>
SequenceCirculaire<T>::SequenceCirculaire(int nbElement, int capacite) :
_capacite(capacite),
_nbElem(nbElement),
_periode(new T[_capacite]) {
}

template<typename T>
SequenceCirculaire<T>::SequenceCirculaire(int nbElements, const T & valeur) :
SequenceCirculaire(nbElements, nbElements){
    // TODO appeler insertion(valeur); sur un while plutot ?
    for (int i=0 ; i<_capacite ; ++i) {
        _periode[i] = valeur;
    }
}

template<typename T>
SequenceCirculaire<T>::SequenceCirculaire(const SequenceCirculaire<T> &copie) :
SequenceCirculaire(copie._nbElem, copie._capacite) {
    //todo voir si je ne peux pas le faire avec l'algorithme de copie de la std::copy
    for (int i=0 ; i<_nbElem ; ++i) {
        _periode[i] = copie._periode[i];
    }
}

template<typename T>
SequenceCirculaire<T>::SequenceCirculaire(SequenceCirculaire<T> && tmpSeq) noexcept :
_nbElem(tmpSeq._nbElem),
_capacite(tmpSeq._capacite),
_periode(tmpSeq._periode) {
    tmpSeq._periode = nullptr;
    tmpSeq._nbElem = 0;
}

template<typename T>
SequenceCirculaire<T> &SequenceCirculaire<T>::operator=(const SequenceCirculaire<T> & autreSequenceC) {
    if (this != &autreSequenceC) {
        _nbElem = autreSequenceC._nbElem;
        _capacite = autreSequenceC._capacite;

        delete [] _periode;
        _periode = new T[_capacite];
        //Todo voir si je ne fais pas avec sdt:copie
        for (int i=0 ; i<_nbElem ; ++i) {
            _periode[i] = autreSequenceC._periode[i];
        }

    }
    return *this;
}

template<typename T>
SequenceCirculaire<T> &SequenceCirculaire<T>::operator=(SequenceCirculaire<T> && autreSequenceC) noexcept {
    std::cout << "Test d'affectation par déplacement" << std::endl;
    if (this != &autreSequenceC) {
        _nbElem = autreSequenceC._nbElem;
        _capacite = autreSequenceC._capacite;

        delete[] _periode;
        _periode = autreSequenceC._periode;

        autreSequenceC._nbElem = 0;
        autreSequenceC._periode = nullptr;
    }
    return *this;
}

template<typename T>
void SequenceCirculaire<T>::insertion(int index, const T & element) {
    if (index >= 0 && index <= _nbElem) {
        if (_nbElem == _capacite)
            _capacite *= 2;

        // Copie dans le nouveau tableau;
        T *tmp = new T[_capacite];
        for (int i = 0; i < index; ++i)
            tmp[i] = _periode[i];

        // Ajout de l'élément.
        tmp[index] = element;
        ++_nbElem;

        for (int i = index + 1; i < _nbElem; ++i)
            tmp[i] = _periode[i - 1];

        delete[] _periode;

        _periode = tmp;
    } else // TODO peut etre faire une insersion a la fin plutot ?
        throw std::out_of_range("index hors du nombre d'elements + 1");
}

template<typename T>
const T &SequenceCirculaire<T>::operator[](int index) const {
    if (index < 0) {
        index *= -1;
        int reverseIndex = _nbElem - (index % _nbElem);
        return _periode[reverseIndex];
    }
    else
        return _periode[index % _nbElem];
}

template<typename T>
T &SequenceCirculaire<T>::operator[](int index) {
    if (index < 0) {
        index *= -1;
        int reverseIndex = _nbElem - (index % _nbElem);
        return _periode[reverseIndex];
    }
    else
        return _periode[index % _nbElem];
}

template<typename T>
SequenceCirculaire<T>::~SequenceCirculaire<T>() {
    delete [] _periode;
}

template<typename T>
Circulateur<T> SequenceCirculaire<T>::makeCirculateur(int position) {
    return Circulateur<T>(position, *this);
}

template<typename T>
int SequenceCirculaire<T>::recherche(const T & element) const {
    for (int i = 0; i < _nbElem; ++i) {
        if (_periode[i] == element)
            return i;
    }

    return -1;
}

#endif //TP_NOTE_SEQUENCECIRCULAIRE_H
