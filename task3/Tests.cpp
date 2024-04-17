#include "Tests.h"
#include "LinkedList.h"

void testIntegerLinkedList() {
    LinkedList<int> intList;
    assert(intList.empty() == true);
    assert(intList.size() == 0);
    std::cout << "empty() and size() tested successfully." << std::endl;

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    assert(intList.size() == 3);
    std::cout << "push_back() tested successfully." << std::endl;

    assert(intList.get(0) == 1);
    assert(intList.get(1) == 2);
    assert(intList.get(2) == 3);
    std::cout << "get() tested successfully." << std::endl;

    intList.pop_back();
    assert(intList.size() == 2);
    assert(intList.empty() == false);
    std::cout << "pop_back() tested successfully." << std::endl;

    intList.push_front(0);
    assert(intList.size() == 3);
    std::cout << "push_front() tested successfully." << std::endl;
    std::cout << "" << std::endl;
}

void testStringLinkedList() {
    LinkedList<std::string> strList;
    assert(strList.empty() == true);
    assert(strList.size() == 0);
    std::cout << "empty() and size() tested successfully." << std::endl;

    strList.push_back("Hello");
    strList.push_back("world");
    strList.push_back("!");
    assert(strList.size() == 3);
    std::cout << "push_back() tested successfully." << std::endl;

    assert(strList.get(0) == "Hello");
    assert(strList.get(1) == "world");
    assert(strList.get(2) == "!");
    std::cout << "get() tested successfully." << std::endl;

    strList.pop_front();
    assert(strList.size() == 2);
    assert(strList.empty() == false);
    std::cout << "pop_front() tested successfully." << std::endl;

    strList.clear();
    assert(strList.size() == 0);
    std::cout << "clear() tested successfully." << std::endl;
    std::cout << "" << std::endl;
}

void testDisplay() {
    LinkedList<int> intList;
    std::cout << "Integer List:" << std::endl;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.display(); // Display the list

    LinkedList<std::string> strList;
    std::cout << "String List:" << std::endl;
    strList.push_back("Hello");
    strList.push_back("world");
    strList.push_back("!");
    strList.display(); // Display the list
}
void testElementExtraction() {
    LinkedList<int> intList;
    // Попытка извлечения элементов из пустого списка
    try {
        intList.get(0);
        std::cerr << "Error: Expected out_of_range exception for get() on empty list." << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    // Извлечение элементов по индексу
    assert(intList.get(0) == 1);
    assert(intList.get(1) == 2);
    assert(intList.get(2) == 3);
}

void testElementRemoval() {
    LinkedList<int> intList;
    // Попытка удаления элемента из пустого списка
    try {
        intList.pop_back();
        std::cerr << "Error: Expected out_of_range exception for pop_back() on empty list." << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    // Удаление элементов по индексу
    intList.pop_front();
    assert(intList.get(0) == 2);
    intList.pop_back();
    assert(intList.get(0) == 2);
    // Проверка, что список пуст после удаления всех элементов
    intList.pop_back();
    assert(intList.empty() == true);
}

void testClear() {
    LinkedList<int> intList;
    // Попытка очистки пустого списка
    intList.clear();
    assert(intList.empty() == true);

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    // Проверка, что список полностью очищен после вызова clear()
    intList.clear();
    assert(intList.empty() == true);
}

void testCombination() {
    LinkedList<int> intList;
    // Добавление элементов в список, удаление части и добавление еще
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.pop_back();
    intList.push_back(4);
    assert(intList.get(0) == 1);
    assert(intList.get(1) == 2);
    assert(intList.get(2) == 4);
}

void testEdgeCases() {
    LinkedList<int> intList;
    // Добавление большого количества элементов и проверка размера списка
    const size_t bigSize = 10000;
    for (size_t i = 0; i < bigSize; ++i) {
        intList.push_back(i);
    }
    assert(intList.size() == bigSize);

    // Попытка удаления элементов из пустого списка
    while (!intList.empty()) {
        intList.pop_back();
    }

    // Попытка извлечения элемента по индексу, превышающего размер списка
    try {
        intList.get(0);
        std::cerr << "Error: Expected out_of_range exception for get() with index out of range." << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }
}
