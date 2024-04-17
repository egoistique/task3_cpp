#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include "LinkedList.h"
#include "Tests.h"

void runTests() {
    testIntegerLinkedList();
    testStringLinkedList();
    testDisplay();
    testStringLinkedList();
    testElementExtraction();
    testElementRemoval();
    testClear();
    testCombination();
    testEdgeCases();

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    runTests();
}
