#pragma once
#include <cstddef>
#include <stdexcept>

template<typename T>
class Stack {
    private:

    size_t capacity;
    T* stack{};
    T* sp{};

    public:

    Stack();
    Stack(size_t n);
    ~Stack();

    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    Stack(Stack&& other) noexcept;
    Stack& operator=(Stack&& other) noexcept;

    void push(const T val);
    T pop();
    T peek();
    size_t size();
    bool empty();

};

// Tried writing function implementations outside the class

template<typename T>
Stack<T>::Stack() : capacity(8), stack(new T[capacity]) { sp = stack; }
template<typename T>
Stack<T>::Stack(size_t n) : capacity(n), stack(new T[capacity]) { sp = stack;}

template<typename T>
Stack<T>::Stack(const Stack& other) : capacity(other.capacity), stack(new T[capacity]) {
    for (size_t i=0; i<capacity; i++){
        stack[i] = other.stack[i];
    }
    sp = stack + (other.sp - other.stack);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    capacity = other.capacity;
    delete[] stack;
    stack = new T[capacity];

    for (size_t i=0; i<capacity; i++) {
        stack[i] = other.stack[i];
    }
    sp = stack + (other.sp - other.stack);

    return *this;
}

template<typename T>
Stack<T>::Stack(Stack&& other) noexcept : capacity(other.capacity), stack(other.stack), sp(other.sp) {
    other.capacity = 0;
    other.stack = nullptr;
    other.sp = nullptr;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept {
    if (this == &other) return *this;
    capacity = other.capacity;
    other.capacity = 0;
    delete[] stack;
    stack = other.stack;
    sp = other.sp;
    other.stack = nullptr;
    other.sp = nullptr;

    return *this;
}

template<typename T>
Stack<T>::~Stack(){
    delete[] stack;
    stack=nullptr;
}

template<typename T>
void Stack<T>::push(const T val){
    if (sp == stack + capacity){throw std::length_error("Stack is full. Cannot push.");}
    else {
        *sp = val;
        sp++;
    }
}

template<typename T>
T Stack<T>::pop(){
    if (sp == stack) {throw std::out_of_range("Stack is empty. Nothing to pop.");}
    sp--;
    T value = *sp;
    *sp = T();
    return value;
}
template<typename T>
T Stack<T>::peek(){
    if (sp == stack) {throw std::out_of_range("Stack is empty.");}
    else return *(sp-1);
}
template<typename T>
size_t Stack<T>::size(){
    return sp-stack;
}

template<typename T>
bool Stack<T>::empty(){
    return (stack == sp);
}
