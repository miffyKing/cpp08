#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template<class T, class Container = std::deque<T> > 
class MutantStack : public std::stack<T, Container> {
	public:

		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack & copy) {
			*this = copy;
		};
		MutantStack & operator=(const MutantStack & assign) {
			if (this != &assign) std::stack<T, Container>::operator=(assign);
			return *this;
		};
		typedef typename Container::iterator                iterator;
		typedef typename Container::reverse_iterator        reverse_iterator;

		iterator begin() {
			return this->c.begin();
		};
		iterator end() {
			return this->c.end();
		};
		reverse_iterator rbegin() {
			return this->c.rbegin();
		};
		reverse_iterator rend() {
			return this->c.rend();
		};
};

#endif