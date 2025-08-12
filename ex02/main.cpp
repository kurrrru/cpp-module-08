#include <iostream>

#include <ex02/MutantStack.hpp>

int main() {
    MutantStack<int> stack;
    for (int i = 0; i < 20; ++i) {
        stack.push(i * i);
    }
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " \n"[std::distance(it, stack.end()) == 1];
    }
    for (MutantStack<int>::reverse_iterator rit = stack.rbegin(); rit != stack.rend(); ++rit) {
        std::cout << *rit << " \n"[std::distance(rit, stack.rend()) == 1];
    }
    for (int i = 0; i < 10; ++i) {
        stack.pop();
    }
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " \n"[std::distance(it, stack.end()) == 1];
    }

    return 0;
}