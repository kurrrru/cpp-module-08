#pragma once

#include <stack>
#include <deque>

template<class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    virtual ~MutantStack();

    iterator begin();
    const_iterator cbegin() const;
    iterator end();
    const_iterator cend() const;
    reverse_iterator rbegin();
    const_reverse_iterator crbegin() const;
    reverse_iterator rend();
    const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"
