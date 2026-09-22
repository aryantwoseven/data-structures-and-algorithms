#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

template<typename T>
class Node {
    public:
    T data{};
    Node* prev;
    Node* next;

    Node<T>() : prev(nullptr), next(nullptr){};
    Node<T>(T data) : data(data) {};
    ~Node() = default;
};

template<typename T>
class doublyLL {
    private:
    Node<T>* head;
    Node<T>* tail;

    public:
    doublyLL<T>(): head(nullptr), tail(nullptr){};
    ~doublyLL<T>() = default;
    T Head();
    T Tail();
    Node<T>* a();

    void push_back(const T val);
    void push_front(const T val);
    void insert_at(size_t idx, const T val);

    void pop_back();
    void pop_front();
    void remove(const size_t idx);
    void clear();

    T get(const T val);
    bool find(const T val);

    size_t size();
    bool is_empty();
    void printls();
};

template<typename T>
bool doublyLL<T>::is_empty()
{
    return (head == nullptr);
}

template<typename T>
size_t doublyLL<T>::size()
{
    Node<T>* temp = head;
    size_t size{};
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

template<typename T>
void doublyLL<T>::push_back(const T val)
{
    if (is_empty())
    {
        Node<T>* node = new Node<T>;
        node->prev = nullptr;
        node->next = nullptr;
        head = tail = node;

        node->data = val;
    }
    else
    {
        Node<T>* node = new Node<T>;
        node->data = val;

        tail->next = node;
        node->prev = tail;
        tail = node;
        node->next = nullptr;
    }
}

template<typename T>
void doublyLL<T>::push_front(const T val)
{
    if (is_empty())
    {
        Node<T>* node = new Node<T>();
        node->prev = nullptr;
        node->next = nullptr;
        head = tail = node;

        node->data = val;
    }
    else
    {
        Node<T>* node = new Node<T>();
        node->data = val;

        head->prev = node;
        node->next = head;
        head = node;
        node->prev = nullptr;
    }
}

template<typename T>
void doublyLL<T>::insert_at(size_t idx, const T val)
{
    if (is_empty())
    {
        Node<T>* node = new Node<T>();
        node->prev = nullptr;
        node->next = nullptr;
        head = tail = node;

        node->data = val;
    }
    else
    {
        Node<T>* node = new Node<T>();
        node->data = val;

        Node<T> temp = head;
        while (temp->next !=nullptr && idx != 1)
        {
            idx--;
            temp = temp->next;
        }
        if (temp->next == nullptr){std::cout << "Invalid index." << std::endl;}
        else
        {
            node->next = temp->next;
            temp->next->prev = node;
            temp->next = node;
            node->prev = temp;
        }
    }
}

template<typename T>
void doublyLL<T>::printls()
{
    if (is_empty()){std::cout << "List is empty"; return;}
    Node<T>* temp = head;

    while(temp != nullptr)
    {
        std::cout << temp->data << "  ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
void doublyLL<T>::clear()
{
    if (is_empty()){std::cout << "List is empty."; return;}

    Node<T>* curr = head;
    while (curr != nullptr)
    {
        Node<T>* nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    head = nullptr;
    tail = nullptr;
}

template<typename T>
T doublyLL<T>::Head()
{
    return head->data;
}

template<typename T>
T doublyLL<T>::Tail()
{
    return tail->data;
}

template<typename T>
Node<T>* doublyLL<T>::a(){return head;}
