#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
};

template<typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), count(0) {}
    ~LinkedList() {
        clear();
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>{ value, nullptr, nullptr };
        if (empty()) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        count++;
    }

    void pop_back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
        count--;
    }

    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>{ value, nullptr, nullptr };
        if (empty()) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void pop_front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        count--;
    }

    bool empty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    Node<T>* head;
    size_t count;
};
