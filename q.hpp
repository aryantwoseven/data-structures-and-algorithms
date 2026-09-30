#pragma once
#include <cstddef>
#include <iostream>

template<typename T>
class Q {
    private:
        size_t q_capacity{};
        size_t q_size{};
        T* data{};

    public:
        size_t front = 0;
        size_t rear = 0;

        Q():data(nullptr){};
        Q(size_t n) : q_capacity(n), q_size(0), data(new T[q_capacity]){};
        ~Q() = default;

        T& operator[](const size_t i){return this->data[i];}

        size_t size(){return q_size;}
        bool is_empty(){return q_size==0;}
        bool is_full(){return ((front == rear) && (q_size == q_capacity));}

        void enqueue(const T& val);
        void dequeue();
        T peek(){return data[front];}
        void clear();
        void printq();

        Q(const Q& other);
        Q& operator=(const Q& other);
        Q(const Q&& other);
        Q& operator=(const Q&& other);
};

template<typename T>
void Q<T>::enqueue(const T& val){
    if (is_full()){std::cout << "Q full. Cannot enqueue" << std::endl; return;}
    data[rear] = val;
    q_size++;
    rear = (front + q_size) % q_capacity;
}

template<typename T>
void Q<T>::dequeue(){
    if (is_empty()){std::cout << "Q empty. Nothing to dequeue" << std::endl; return;}
    data[front] = T{};
    q_size--;
    front = (front + 1) % q_capacity;
}

template<typename T>
void Q<T>::printq(){
    for (int i=0; i<q_size; i++)
    {
        std::cout << data[(front+i)%q_capacity] << " | ";
    }
    std::cout << std::endl;
}
