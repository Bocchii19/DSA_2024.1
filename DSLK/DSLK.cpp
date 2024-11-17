#include <iostream>


struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
};

void insertNode(LinkedList* l, int data) {
    Node* newNode = new Node(data);
    if (l->head == nullptr) {
        l->head = newNode;
        l->tail = newNode;
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
}
void displayList(LinkedList* l) {
    Node* current = l->head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
//Xóa node ở đầu
void deleteHeadNode(LinkedList* l) {
    if (l->head != nullptr) {
        Node* temp = l->head;
        l->head = l->head->next;
        delete temp;
    }else{
        std::cout<<"Danh sách rỗng!"<<std::endl;
    }
}
//Xóa node ở cuối
void deleteTailNode(LinkedList* l) {
    if (l->head != nullptr) {
        Node* current = l->head;
        Node* prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        if (prev != nullptr) {
            prev->next = nullptr;
            delete current;
        }
    }else{
        std::cout<<"Danh sách rỗng!"<<std::endl;
    }
}
//Xóa node sau node cho trước
void deleteAfterNode(LinkedList* l, Node* prevNode) {
    if (prevNode != nullptr && prevNode->next != nullptr) {  
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        delete temp;    
    }else{
        std::cout<<"Node không tồn tại!"<<std::endl;
    }
}
int main()  {
    LinkedList* l = new LinkedList();
    insertNode(l, 1);
    insertNode(l, 2);
    insertNode(l, 3);
    displayList(l);
    deleteHeadNode(l);
    displayList(l);
    deleteTailNode(l);
    displayList(l);
    deleteAfterNode(l, l->head);
    displayList(l);
    return 0;
}
