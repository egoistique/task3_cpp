#include <iostream>
#include <string>
#include <cassert>
#include "LinkedList.h"

void testIntegerLinkedList() {
    LinkedList<int> intList;
    assert(intList.empty() == true);
    assert(intList.size() == 0);

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    assert(intList.size() == 3);

    intList.pop_back();
    assert(intList.size() == 2);
    assert(intList.empty() == false);

    intList.push_front(0);
    assert(intList.size() == 3);
}

void testStringLinkedList() {
    LinkedList<std::string> strList;
    assert(strList.empty() == true);
    assert(strList.size() == 0);

    strList.push_back("Hello");
    strList.push_back("world");
    strList.push_back("!");
    assert(strList.size() == 3);

    strList.pop_front();
    assert(strList.size() == 2);
    assert(strList.empty() == false);

    strList.clear();
    assert(strList.size() == 0);
}

int main() {
    testIntegerLinkedList();
    testStringLinkedList();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
