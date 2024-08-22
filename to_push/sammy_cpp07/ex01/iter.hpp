#ifndef iter_HPP
# define iter_HPP

template <typename Type> void iter(Type *array, size_t arr_len, void (*f)(Type &))
{
	size_t	i;

	i = 0;
	while (i < arr_len)
	{
		f(array[i]);
		i++;
	}
}

#endif