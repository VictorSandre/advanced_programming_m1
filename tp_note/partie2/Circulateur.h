//
// Created by victor SANDRE.
//

#ifndef TP_NOTE_CIRCULATEUR_H
#define TP_NOTE_CIRCULATEUR_H
#include"SequenceCirculaire.h"

template<typename T>
class SequenceCirculaire;

template<typename T>
class Circulateur {
public:
    Circulateur(int, SequenceCirculaire<T> &);

    bool operator==(const Circulateur &) const;

    bool operator!=(const Circulateur &) const;

    T& operator *();

    void operator++();

    Circulateur& operator=(const Circulateur<T>&);
private:
    int _position;
    SequenceCirculaire<T>& _circulaire;
};

template<typename T>
Circulateur<T>::Circulateur(int position, SequenceCirculaire<T>& circulaire) :
_position(position),
_circulaire(circulaire) {
}

template<typename T>
bool Circulateur<T>::operator==(const Circulateur<T> & autre) const{
    return (&_circulaire == &autre._circulaire &&
            (_position%_circulaire._nbElem) == (autre._position%autre._circulaire._nbElem));
}

template<typename T>
bool Circulateur<T>::operator!=(const Circulateur &autre) const {
    return !(autre == *this);
}

template<typename T>
T &Circulateur<T>::operator*() {
    return _circulaire[_position];
}

template<typename T>
void Circulateur<T>::operator++() {
    ++_position;
}

template<typename T>
Circulateur<T> &Circulateur<T>::operator=(const Circulateur<T> & autre) {
    _circulaire = autre._circulaire;
    _position = autre._position;

    return *this;
}


#endif //TP_NOTE_CIRCULATEUR_H
