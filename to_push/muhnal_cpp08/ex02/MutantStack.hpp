#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

// https://en.cppreference.com/w/cpp/container
// https://en.cppreference.com/w/cpp/container/deque
// https://en.cppreference.com/w/cpp/language/templates
// https://en.cppreference.com/w/cpp/container/stack/stack

#include <deque>
#include <stack>

// template <data type, container type>
//  if you don't specify the container type, it will use std::deque as
//  default
// thats why bec stack is a container adapter that defines the
// underlying container type as std::deque
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	// typedefs for the container type and its iterators are needed to make the class compatible with the STL
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// begin() and end() functions are needed to make the class compatible with the STL
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	// rbegin() and rend() functions are needed to make the class compatible with the STL
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

	// safeincrement and safedecrement functions
	bool safeincrement(iterator &it);
	bool safedecrement(iterator &it);

	// reverse safeincrement and safedecrement functions
	bool reverse_safeincrement(reverse_iterator &it);
	bool reverse_safedecrement(reverse_iterator &it);

	// reverse safeincrement and safedecrement functions
	bool const_reverse_safeincrement(const_reverse_iterator &it);
	bool const_reverse_safedecrement(const_reverse_iterator &it);

	// reverse safeincrement and safedecrement functions
	bool const_safeincrement(const_iterator &it);
	bool const_safedecrement(const_iterator &it);

	//OCF for the MutantStack class
	MutantStack();
	MutantStack(MutantStack const &src);
	MutantStack &operator=(MutantStack const &rhs);
	~MutantStack();
};
#include "MutantStack.tpp"

#endif