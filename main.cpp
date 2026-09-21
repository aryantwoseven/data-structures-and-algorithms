#include "darray.hpp"
#include "stack.hpp"

#include <iostream>

int main() {
    darray<int> arr(8,9);
    darray<int> a;
    std::cout << arr[3];
}
