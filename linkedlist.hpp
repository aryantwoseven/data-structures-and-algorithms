#pragma once

class Node {
    public:
    int value{0};
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
    private:
    Node* head;
    public:
    LinkedList() {
        head = nullptr;
    }
    // ~LinkedList() {}
    void addNode(int x){
        Node* node = new Node(x);
        node->value = x;
        if (head == nullptr) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next!= nullptr) {
                temp = temp->next;
            } temp->next = node;
            node->next = nullptr;
        }
    }
    void insertAt(int pos, int val) {
        Node* temp = head;
        int cnt{1};
        Node* node = new Node(val);
        if (pos == 1 || head == nullptr) {
            node->next = head;
            head = node;
            return;
        }
        while (temp->next != nullptr && cnt != pos-1) {
            temp = temp->next;
            cnt++;
        } node->next = temp->next;
        temp->next = node;
    }
    void deleteAt(int pos){
        Node *temp = head;
        int cnt{1};
        if (pos == 1){
            head = head->next;
            delete temp;
            return;
        }
        while (temp->next != nullptr && cnt != pos-1){
            temp=temp->next;
            cnt++;
        } Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        del = nullptr;
    }
    void showList(){
        Node* temp = head;
        std::cout << "-------------------------\n";
        while (temp != nullptr) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        } std::cout << "nullptr" << std::endl;
        std::cout << "-------------------------\n";
    }
};


// int main() {
//     LinkedList list1;
//     int ch{};
//     int val{};
//     int pos{};
//     do {
//         std::cout << "Menu:\n1. Add New Node\n2. Insert Node at n position\n3. Delete node at n position\n4. Show List\nChoice: ";
//         std::cin >> ch;
//         switch (ch) {
//             case 1:
//                 std::cout << "Enter value: ";
//                 std::cin >> val;
//                 list1.addNode(val);
//                 break;
//             case 2:
//                 std::cout << "Enter position: ";
//                 std::cin >> pos;
//                 std::cout << "Enter value: ";
//                 std::cin >> val;
//                 list1.insertAt(pos, val);
//                 break;
//             case 3:
//                 std::cout << "Enter position: ";
//                 std::cin >> pos;
//                 list1.deleteAt(pos);
//                 break;
//             case 4:
//                 list1.showList();
//                 break;
//             case 5:
//                 std::cout << "Exiting...\n";
//                 break;
//             default:
//                 std::cout << "Invalid choice, try again.\n";
//         }
//     } while (ch!=5);
//     return 0;
// }
