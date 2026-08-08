#include <cstddef>
#include <iostream>
#include <stdexcept>

template<typename T>
class darray {
    private:
        T* data{};
        std::size_t a_size{};
        std::size_t a_capacity{};

    void reallocate(size_t newCap){
        T* newData = new T[newCap];
        for (size_t i; i<a_size; i++){
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        a_capacity = newCap;
    }

    public:
    size_t size(){
        return a_size;
    }
    T& operator[](size_t i){ return data[i]; }

    darray():data(nullptr), a_size(0), a_capacity(0){}

    darray(size_t n){
        data = new T[n];
        a_capacity = n;
    }
    darray(size_t n, const T& x){
        data = new T[n];
        for (size_t i = 0; i<n; i++){
            data[i] = x;
        }
        a_capacity = n;
        a_size = n;
    }
    darray(const darray& darr){
        a_capacity = darr.a_capacity;
        a_size = darr.a_size;
        data = new T[a_capacity];
        for (size_t i=0; i<a_size; i++){
            data[i]=darr.data[i];
        }
    }
    darray& operator=(const darray&){}
    darray(const darray&& darr){
        a_size = darr.a_size;
        data = std::move(darr.data);
    }
    ~darray(){ delete[] data; }

    // member functions
    void append(const T& value) {
        if (a_size== a_capacity) {
            reallocate(2*a_size);
        }
        data[a_size++] = value;
    }
    // 0-indexed
    void insert(const T& value, size_t pos) {
        if (pos > a_size)
            throw std::out_of_range("insert position out of range");

        if (a_size == a_capacity) {
            reallocate(a_capacity == 0 ? 1 : 2 * a_capacity);
        }
        for (size_t i = a_size; i > pos; i--) {
            data[i] = std::move(data[i - 1]);
        }
        data[pos] = value;
        a_size++;
    }
    // 0-indexed
    void erase(size_t pos) {
        if (pos >= a_size)
            throw std::out_of_range("position out of range");

        for (size_t i=pos; i<a_size-1; i++){
            data[i] = std::move(data[i+1]);
        }
        data[a_size-1].~T();
        a_size--;
    }
};

int main() {
    darray<int> arr(8,9);
    darray<int> a;
    std::cout << arr[3];
}
