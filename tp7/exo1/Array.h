//
// Created by victor SANDRE.
//

#ifndef EXO2_ARRAY_H
#define EXO2_ARRAY_H

#include <ostream>
#include <iostream>

template <typename T, int ENLARGEMENT>
class Array;

template <typename T, int ENLARGEMENT>
std::ostream &operator<<(std::ostream &os, const Array<T,ENLARGEMENT> &array);

template<typename T, int ENLARGEMENT>
class Array {
    //class BackInsertIterator;
public:
    Array();

    Array(const Array& array);

    Array(const T* array);

    void add(const T& element);

    int size() const;

    const T& operator[](int i) const;

    T& operator[](int i);

    Array<T,ENLARGEMENT>& operator=(const Array& array);

    ~Array();

    friend std::ostream &operator<< <T, ENLARGEMENT> (std::ostream &os, const Array<T,ENLARGEMENT> &array);

    class BackInsertIterator;
    BackInsertIterator backInsertIterator() {
        return BackInsertIterator(*this);
    }

    class BackInsertIterator {
    public:
        BackInsertIterator(Array<T, ENLARGEMENT>& container) : _container(&container){}

        BackInsertIterator& operator=(const T& value) {
            _container->add(value);
            return *this;
        }

        // Ne sert à rien.
        const Array& operator*() const { return *this; }

        // Ne sert à rien.
        BackInsertIterator& operator++() { return *this; }

    private:
        Array* _container;
    };
private:
    T* _head;
    int _size;
    int _capacity;

    void enlargeArray();



};

template<typename T, int ENLARGEMENT>
Array<T, ENLARGEMENT>::Array() {
    _capacity = ENLARGEMENT;
    _size = 0;
    _head = new T[_capacity];
}

template<typename T, int ENLARGEMENT>
Array<T, ENLARGEMENT>::Array(const Array& array) {
    _size = array._size;
    _capacity = array._capacity;
    _head = new T[_capacity];

    for (int i = 0; i < array._size; ++i) {
        _head[i] = array._head[i];
    }
}

template<typename T, int ENLARGEMENT>
Array<T, ENLARGEMENT>::Array(const T *array) {
    if (array != nullptr) {
        int size = (sizeof(array)/sizeof(T));
        _head = new T[size];
        _size = size;
        std::cout<< "taille trouvée du tableau : " << size << std::endl;
        _capacity = size;
        for (int i = 0; i < size; ++i) {
            _head[i] = array[i];
        }
    }
    else {
        _capacity = ENLARGEMENT;
        _size = 0;
        _head = new T[_capacity];
    }
}

template<typename T, int ENLARGEMENT>
void Array<T, ENLARGEMENT>::add(const T &element) {
    if (_size == _capacity) {
        if (ENLARGEMENT == 0)
            throw std::invalid_argument("Le tableau ne peut augementer de taille car vous avez mis sa modulation à 0");

        enlargeArray();
    }
    _head[_size] = element;
    _size++;

}

template<typename T, int ENLARGEMENT>
int Array<T, ENLARGEMENT>::size() const {
    return _size;
}

template<typename T, int ENLARGEMENT>
const T &Array<T, ENLARGEMENT>::operator[](int i) const {
    if (i < 0 || i>= _size)
        throw std::out_of_range("l'index n'est pas dans le tableau");

    return  _head[i];
}

template<typename T, int ENLARGEMENT>
T &Array<T, ENLARGEMENT>::operator[](int i) {
    if (i < 0 || i>= _size)
        throw std::out_of_range("l'index n'est pas dans le tableau");

    return  _head[i];
}

template<typename T, int ENLARGEMENT>
Array<T, ENLARGEMENT>& Array<T, ENLARGEMENT>::operator=(const Array<T, ENLARGEMENT> &array) {
    if (this != &array) {
        if (_head != nullptr)
            delete[] _head;

        _size = array._size;
        _capacity = array._capacity;
        _head = new T[_capacity];

        //TODO en faire une fonction.
        for (int i = 0; i < _size; ++i) {
            _head[i] = array._head[i];
        }
    }
    return *this;
}

template<typename T, int ENLARGEMENT>
std::ostream &operator<<(std::ostream &os, const Array<T, ENLARGEMENT> &array) {
    os << "capacity: " << array._capacity << "; size: " << array._size << "; [ ";
    for (int i = 0; i < array._size ; ++i) {
        if (&array._head[i] != nullptr)
            os << array._head[i] << " ";
        else
            os << "nullptr" << " ";
    }
    os << "]" << std::endl;
    return os;
}

template<typename T, int ENLARGEMENT>
Array<T, ENLARGEMENT>::~Array() {
    if (_head != nullptr)
        delete [] _head;
}

template<typename T, int ENLARGEMENT>
void Array<T, ENLARGEMENT>::enlargeArray() {
    _capacity += ENLARGEMENT;
    T* tmpArray = new T[_capacity];

    for (int i = 0; i < _size; ++i) {
        tmpArray[i] = _head[i];
    }

    delete [] _head;
    _head = tmpArray;
}

#endif //EXO2_ARRAY_H
