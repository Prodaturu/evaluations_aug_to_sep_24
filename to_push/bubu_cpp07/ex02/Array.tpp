/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:50:06 by mtayebi           #+#    #+#             */
/*   Updated: 2024/07/26 04:50:29 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : elements(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; ++i) {
        elements[i] = other.elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        T* newElements = new T[other._size];
        for (unsigned int i = 0; i < other._size; ++i) {
            newElements[i] = other.elements[i];
        }
        delete[] elements;
        elements = newElements;
        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

//Const cannot change
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif
