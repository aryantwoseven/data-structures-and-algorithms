#include "darray.hpp"
#include "stack.hpp"

#include <iostream>

int main() {
    darray<int> arr(8,9);
    std::cout << arr[3] << std::endl;

    Stack<int> stk(8);
    std::cout << stk.size()<< std::endl;
    for (int i=10; i<=15; i++){
        stk.push(i);
        if (i%2==0){stk.pop();}
    }
    std::cout << stk.peek() << std::endl;
    std::cout << stk.size() << std::endl;

    Stack<std::string> sst;
    int a{};
    std::string s{};
    while (a<8){
        char c = 97+a;
        s += c;
        sst.push(s);
        std::cout << sst.size() << " " << sst.peek() << " | ";
        a++;
    }
}
