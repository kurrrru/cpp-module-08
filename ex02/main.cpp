#include <iostream>

#include <ex02/MutantStack.hpp>

namespace subject {
    void test();
}  // namespace subject

int main() {
    MutantStack<int> stack;
    for (int i = 0; i < 20; ++i) {
        stack.push(i * i);
    }
    for (MutantStack<int>::iterator it = stack.begin();
        it != stack.end(); ++it) {
        std::cout << *it << " \n"[std::distance(it, stack.end()) == 1];
        (*it)++;
    }
    for (MutantStack<int>::reverse_iterator rit = stack.rbegin();
        rit != stack.rend(); ++rit) {
        std::cout << *rit << " \n"[std::distance(rit, stack.rend()) == 1];
        (*rit)++;
    }
    for (int i = 0; i < 10; ++i) {
        stack.pop();
    }
    for (MutantStack<int>::const_iterator it = stack.cbegin();
        it != stack.cend(); ++it) {
        std::cout << *it << " \n"[std::distance(it, stack.cend()) == 1];
    }
    for (MutantStack<int>::const_reverse_iterator rit = stack.crbegin();
        rit != stack.crend(); ++rit) {
        std::cout << *rit << " \n"[std::distance(rit, stack.crend()) == 1];
    }

    subject::test();

    return 0;
}

void subject::test() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}
