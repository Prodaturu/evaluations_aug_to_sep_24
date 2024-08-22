#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename Type> class Array
{
private:
    Type *_array;
    unsigned int _size;
public:
    Array(void)
    {
        _array = NULL;
        _size = 0;
    }
    Array(unsigned int n)
    {
        _array = new Type[n];
        _size = n;
    }
    ~Array(void)
    {
        if (_array)
            delete [] _array;
    }
    
    Array(Array const &src)
    {
        _size = src.size();
        _array = new Type[_size];
        for(unsigned int i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }
    
    Array &operator=(Array const &src)
    {
        if (this == &src)
            return *this;
        if (_array)
            delete [] _array;
        _size = src.size();
        _array = new Type[_size];
        for(unsigned int i = 0; i < _size; i++)
            _array[i] = src._array[i];
        return *this;
    }

    unsigned int size(void) const
    {
        return this->_size;
    }
    
    class OutOfRange : public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return "Index Out Of Range";
        }
    };
    Type &operator[](unsigned int i) const
    {
        if (i >= _size || i < 0)
            throw OutOfRange();
        return _array[i];
    }
};




#endif