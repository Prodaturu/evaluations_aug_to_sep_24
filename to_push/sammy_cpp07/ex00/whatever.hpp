#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename Type> void swap(Type &a, Type &b)
{
	Type	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename Type> Type min(Type &a, Type &b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

template <typename Type> Type max(Type &a, Type &b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

#endif