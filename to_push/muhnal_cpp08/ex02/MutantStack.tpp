#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const &src)
	: std::stack<T, Container>(src) {}

template <typename T, typename Container>
MutantStack<T, Container> &
MutantStack<T, Container>::operator=(MutantStack const &rhs) {
	if (this != &rhs) {
	std::stack<T, Container>::operator=(rhs);
	}
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end() {
	return this->c.end();
}

template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const {
	return this->c.begin();
}

template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const {
	return this->c.end();
}

template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rbegin() {
	return this->c.rbegin();
}

template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rend() {
	return this->c.rend();
}

template <typename T, typename Container>
typename Container::const_reverse_iterator
MutantStack<T, Container>::rbegin() const {
	return this->c.rbegin();
}

template <typename T, typename Container>
typename Container::const_reverse_iterator
MutantStack<T, Container>::rend() const {
	return this->c.rend();
}

template <typename T, typename Container>
bool MutantStack<T, Container>::safeincrement(iterator &it) {
	if (it != this->c.end()) {
	++it;
	return true;
	}
	return false;
}

template <typename T, typename Container>
bool MutantStack<T, Container>::safedecrement(iterator &it) {
	if (it != this->c.begin()) {
	--it;
	return true;
	}
	return false;
}

template <typename T, typename Container>
bool MutantStack<T, Container>::reverse_safeincrement(reverse_iterator &it) {
	if (it != this->c.rend()) {
	++it;
	return true;
	}
	return false;
}

template <typename T, typename Container>
bool MutantStack<T, Container>::reverse_safedecrement(reverse_iterator &it) {
	if (it != this->c.rbegin()) {
	--it;
	return true;
	}
	return false;
}

template <typename T, typename Container>
bool MutantStack<T, Container>::const_reverse_safeincrement(
	const_reverse_iterator &it) {
	if (it != this->c.rend()) {
		++it;
	return true;
	}
	return false;
}

template <typename T, typename Container>
bool MutantStack<T, Container>::const_reverse_safedecrement(
	const_reverse_iterator &it) {
	if (it != this->c.rbegin()) {
		--it;
	return true;
	}
	return false;
}

template <typename T, typename Container>
bool MutantStack<T, Container>::const_safeincrement(const_iterator &it) {
	if (it != this->c.end()) {
	++it;
	return true;
	}
	return false;
}

template <typename T, typename Container>
bool MutantStack<T, Container>::const_safedecrement(const_iterator &it) {
	if (it != this->c.begin()) {
	--it;
	return true;
	}
	return false;
}

#endif
