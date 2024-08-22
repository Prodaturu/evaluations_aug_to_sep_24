#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename std::vector<T>::iterator easyfind(std::vector<T> &container, int value) {
    typename std::vector<T>::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

#endif