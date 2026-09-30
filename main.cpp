#include "darray.hpp"
#include "stack.hpp"
#include "linkedlist_doubly.hpp"
#include "queue.hpp"

#include <iostream>

int main()
{
    Q<int> q1(12);
    for (int i=1; i<=12; i++)
    {
        q1.enqueue(i);
    }
    for (int i=1; i<=4; i++) {q1.dequeue();}
    for (int i=1; i<=4; i++) {q1.enqueue(100-i);}
    q1.printq();
    std::cout << q1.front << " " << q1.rear << " " << q1.peek()<< std::endl;
    q1.enqueue(1);
}
// int main() {
//     darray<int> arr(8,9);
//     std::cout << arr[3] << std::endl;

//     Stack<int> stk(8);
//     std::cout << stk.size()<< std::endl;
//     for (int i=10; i<=15; i++){
//         stk.push(i);
//         if (i%2==0){stk.pop();}
//     }
//     std::cout << stk.peek() << std::endl;
//     std::cout << stk.size() << std::endl;

//     Stack<std::string> sst;
//     int a{};
//     std::string s{};
//     while (a<8){
//         char c = 97+a;
//         s += c;
//         sst.push(s);
//         std::cout << sst.size() << " " << sst.peek() << " | ";
//         a++;
//     }


//     doublyLL<int> ls;
//     for (int i = 1; i<=1000; i++)
//     {
//         ls.push_back(i);
//     }
//     ls.printls();

//     std::cout << "head: "<< ls.a()->data << " tail: " << ls.Tail() << std::endl;

//     doublyLL<std::string> lss;
//     std::string str{};
//     for (int i=0; i<=25; i++){
//             char c = 97+i;
//             str += c;
//             lss.push_back(str);
//     }
//     lss.printls();
//     lss.clear();
//     lss.printls();
// }
