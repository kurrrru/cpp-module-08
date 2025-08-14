#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <list>
#include <string>

#include <ex00/easyfind.hpp>

int main() {
    std::set<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    std::set<int>::const_iterator itSet = easyfind(mySet, 20);
    if (itSet != mySet.end()) {
        std::cout << "Found in set: " << *itSet << std::endl;
    } else {
        std::cout << "Not found in set." << std::endl;
    }

    std::deque<int> myDeque;
    myDeque.push_back(100);
    myDeque.push_back(200);
    myDeque.push_back(300);
    std::deque<int>::const_iterator itDeque = easyfind(myDeque, 201);
    if (itDeque != myDeque.end()) {
        std::cout << "Found in deque: " << *itDeque << std::endl;
    } else {
        std::cout << "Not found in deque." << std::endl;
    }

    std::list<std::string> myList;
    myList.push_back("I");
    myList.push_back("have");
    myList.push_back("not");
    myList.push_back("failed");
    myList.push_back(".");
    myList.push_back("I've");
    myList.push_back("just");
    myList.push_back("found");
    myList.push_back("10000");
    myList.push_back("ways");
    myList.push_back("that");
    myList.push_back("won't");
    myList.push_back("work");
    myList.push_back(".");
    std::list<std::string>::const_iterator itList = easyfind(myList, ".");
    std::list<std::string>::const_iterator beginList = myList.begin();
    if (itList != myList.end()) {
        std::cout << "Found in list: " << *itList << std::endl;
        std::cout << "Distance from top of list: "
                << std::distance(beginList, itList) << std::endl;
    } else {
        std::cout << "Not found in list." << std::endl;
    }

    int  size_vector2d = 100;
    std::vector<std::vector<int> > vector2d(size_vector2d);
    for (int i = 0; i < size_vector2d; ++i) {
        for (int j = 1; j < size_vector2d; ++j) {
            if (i % j == 0) {
                vector2d[i].push_back(j);
            }
        }
    }
    std::vector<int> partof_vector2d;
    partof_vector2d.push_back(1);
    partof_vector2d.push_back(2);
    partof_vector2d.push_back(5);
    partof_vector2d.push_back(10);
    partof_vector2d.push_back(25);
    partof_vector2d.push_back(50);
    std::vector<std::vector<int> >::const_iterator
        itVector2d = easyfind(vector2d, partof_vector2d);
    std::vector<std::vector<int> >::const_iterator
        beginVector2d = vector2d.begin();
    if (itVector2d != vector2d.end()) {
        std::cout << "Found in vector of vectors: ";
        for (std::size_t i = 0; i < itVector2d->size(); ++i) {
            std::cout << (*itVector2d)[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Distance from top of vector of vectors: "
                << std::distance(beginVector2d, itVector2d) << std::endl;
    } else {
        std::cout << "Not found in vector of vectors." << std::endl;
    }

    std::multiset<int> myMultiSet;
    myMultiSet.insert(1);
    myMultiSet.insert(2);
    myMultiSet.insert(3);
    myMultiSet.insert(2);
    myMultiSet.insert(4);
    std::multiset<int>::const_iterator itMultiSet = easyfind(myMultiSet, 2);
    if (itMultiSet != myMultiSet.end()) {
        std::cout << "Found in multiset: " << *itMultiSet << std::endl;
        std::cout << "distance from top of multiset: "
                << std::distance(myMultiSet.begin(), itMultiSet) << std::endl;
    } else {
        std::cout << "Not found in multiset." << std::endl;
    }
    return 0;
}
